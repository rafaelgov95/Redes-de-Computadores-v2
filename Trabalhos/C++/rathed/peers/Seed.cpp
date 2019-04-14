//
// Created by rafael on 08/04/19.
//
//libs do sistema


//lib importadas

#include <model.pb.h>
#include "Seed.h"
#include "util.h"
#include <ostream>
#include <google/protobuf/io/zero_copy_stream_impl.h>

namespace io = google::protobuf::io;

Seed::~Seed() {

}

Seed::Seed(int porta) {
    if ((socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        error("socket()");
    }
    FD_ZERO(&socketoriginal);
    FD_ZERO(&readfds);
    FD_SET(socket_fd, &socketoriginal);
    FD_SET(socket_fd, &readfds);
    numfd = socket_fd + 1;
    tv.tv_sec = 0;
    rastreador_address.sin_family = AF_INET;
    rastreador_address.sin_port = htons(rastreadorPorta);
    rastreador_address.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_address.sin_zero), 8);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(porta);
    server_address.sin_addr.s_addr = INADDR_ANY;
    bzero(&(client_address.sin_zero), 8);
    bzero(&(rastreador_address.sin_zero), 8);

    run();

}


void Seed::run() {
    if (bind(socket_fd,
             (struct sockaddr *) &server_address, sizeof(struct sockaddr)) == -1) // atribui ip
    {
        error("bind()"); // erro se der merd@
    }

    address_length = sizeof(struct sockaddr); //tamanh do endereco ipv4

    atualizarRastreador();
    while (1) {
        readfds = socketoriginal;
        int recieve = select(numfd, &readfds, NULL, NULL, &tv);
        if (recieve == -1) {
            perror("Erro select"); // erro no select()
        }

        if (FD_ISSET(socket_fd, &readfds)) {
            FD_CLR(socket_fd, &readfds);
            std::cout << "Comunicação Cliente" << std::endl;
            bytes_read = recvfrom(socket_fd, recieve_data, MAX_LENGTH, 0, (struct sockaddr *) &client_address,
                                  &address_length); //block call, will wait till client enters something, before proceeding
            rathed::Datagrama buf;
            buf.ParseFromArray(recieve_data, bytes_read);
            tratarMensagem(buf);

        }
    }
}

void Seed::tratarMensagem(rathed::Datagrama data) {
    std::cout << "Chegou: " << data.type() << std::endl;
    if (data.type() == 1) {

    } else if (data.type() == 2) {
        EnviarArquivo(data);
    } else if (data.type() == 3) {
        atualizacaoRealizada(data);

    } else if (data.type() == 4) {
        atualizacaoRealizada(data);

    }

}

void Seed::EnviarArquivo(rathed::Datagrama data) {

    auto it = std::find_if(file.begin(), file.end(), CompareHash(data.data()));

    if (it.base() != nullptr) {
        rathed::Datagrama datagrama;
        int fd_arq = open("/home/rafael/Música/AlanWalker.mp3", O_RDONLY);
//        io::ZeroCopyInputStream* raw_input = new io::FileInputStream(fd_arq);
//        auto* coded_input = new io::CodedInputStream(raw_input);
        // AQUI E A COISA LINDA QUE VOU FAZER
        int total_bytes=0,total_bytes_read=0,cont_pacote=0;

        while (( bytes_read = read(fd_arq,recieve_data, MAX_LENGTH )) > 0) {
            cont_pacote++;
            datagrama.set_type(static_cast<rathed::DatagramaType>(2));
            datagrama.set_packnumber(cont_pacote);
            datagrama.set_data(recieve_data,bytes_read);
            size_t size = datagrama.ByteSizeLong();
            void *buffer = malloc(size);
            datagrama.SerializeToArray(buffer, size);
            sendto(socket_fd, buffer, size, 0, (struct sockaddr *) &client_address, sizeof(client_address));
            total_bytes_read+=bytes_read;
            total_bytes+=size;
            std::cout<<"Enviado Total de Pacotes: "<<total_bytes<<std::endl;
            std::cout<<"Enviado Total de Pacotes DATA: "<<total_bytes_read<<std::endl;

            usleep(200);
        }
        datagrama = DataGrama(2,-1,"");
        sendto(socket_fd, DataGramaSerial(datagrama), datagrama.ByteSizeLong(), 0, (struct sockaddr *) &client_address, sizeof(client_address));
        sleep(5);
//        delete coded_input;
//        delete raw_input;

    } else {
        if (sendto(socket_fd, "ERRO", sizeof("ERRO"), 0,
                   (struct sockaddr *) &rastreador_address, sizeof(struct sockaddr)) <= 0)
            error("Erro ao enviar");
    }


}

void Seed::atualizarRastreador() {
    std::cout << "atualizarRastreador Seed: " << std::endl;
    std::pair<std::string, std::string> arquivo = std::make_pair("cc72fc24056ced9ce13a287ca1243d48",
                                                                 "/home/rafael/Música/AlanWalker.mp3");
    file.push_back(arquivo);

    rathed::Datagrama _data = DataGrama(4, arquivo.second.size(), arquivo.first);


    if (sendto(socket_fd, DataGramaSerial(_data), _data.ByteSizeLong(), 0,
               (struct sockaddr *) &rastreador_address, sizeof(struct sockaddr)) <= 0)
        error("Erro ao enviar");

}

void Seed::atualizacaoRealizada(rathed::Datagrama data) {
    std::cout << "TIPO: " << data.type() << "| OK |" << std::endl;

}