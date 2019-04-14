//
// Created by rafael on 08/04/19.
//

#include <sstream>
#include "Leecher.h"

#include <google/protobuf/io/zero_copy_stream_impl.h>

namespace io = google::protobuf::io;


Leecher::Leecher(int porta) {
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
    run();

}


void Leecher::run() {

    if (
            bind(socket_fd,
                 (struct sockaddr *) &server_address, sizeof(struct sockaddr)) == -1) // atribui ip
    {
        error("bind()"); // erro se der merd@
    }

    address_length = sizeof(struct sockaddr); //tamanh do endereco ipv4
    consultarRastreador();

    while (1) {
        readfds = socketoriginal;
        int recieve = select(numfd, &readfds, NULL, NULL, &tv);
        if (recieve == -1) {
            perror("Erro select"); // erro no select()
        }
        if (FD_ISSET(socket_fd, &readfds)) {
            FD_CLR(socket_fd, &readfds);
            int n, fd_arq;
            rathed::Datagrama datagrama_buff;
            fd_arq = open("/home/rafael/teste.mp3", O_CREAT | O_WRONLY );
            io::ZeroCopyOutputStream *raw_output = new io::FileOutputStream(fd_arq);
            auto *coded_output = new io::CodedOutputStream(raw_output);
            int buff_int = 0, buff_data=0;
            while ((bytes_read = recvfrom(socket_fd, recieve_data, MAX_LENGTH, 0, (struct sockaddr *) &client_address,
                                          &address_length))) {
                datagrama_buff.ParseFromArray(recieve_data, bytes_read);
                if (datagrama_buff.packnumber() == -1) {
                    std::cout << "Foi Recebido COMANDO DE FIM!!" << std::endl;
                    break;
                }
                coded_output->WriteRaw(datagrama_buff.data().c_str(), datagrama_buff.data().size());
                buff_int += datagrama_buff.data().size();
                buff_data+=bytes_read;
                std::cout << "Recebendo Total Bytes : " << buff_data << std::endl;
                std::cout << "Recebendo Total Bytes DATA: " << buff_int << std::endl;

            }
            std::cout << "Foi Recebido Tudo!!" << std::endl;
            delete coded_output;
            delete raw_output;
//            close(socket_fd);

        }
    }
}


void Leecher::consultarRastreador() {
    rathed::Datagrama _data = DataGrama(2, 0, "cc72fc24056ced9ce13a287ca1243d48");
    if (sendto(socket_fd, DataGramaSerial(_data), _data.ByteSizeLong(), 0, (struct sockaddr *) &rastreador_address,
               sizeof(struct sockaddr)) <= 0)
        error("Erro ao enviar");

    bytes_read = recvfrom(socket_fd, recieve_data, MAX_LENGTH, 0, (struct sockaddr *) &client_address,
                          &address_length); //block call, will wait till client enters something, before proceeding
    rathed::Datagrama datagrama;
    datagrama.ParseFromArray(recieve_data, bytes_read);
    std::cout << "DataGrama consultar Rastreador: " << datagrama.data() << std::endl;

    std::vector<std::string> Peers_Com_File{my_split(datagrama.data(), ';')};
    for (int i = 0; i < Peers_Com_File.size(); ++i) {
        std::cout << "SEED: " << Peers_Com_File[i] << std::endl;
    }
    std::vector<std::string> teste_peer{my_split(Peers_Com_File[0], ':')};

    std::cout << "IP: " << teste_peer[0] << std::endl;
    std::cout << "PORTA: " << teste_peer[1] << std::endl;
    std::cout << "Solicitando do Peers" << std::endl;
//
    struct sockaddr_in seed_address;
    bzero(&(seed_address.sin_zero), 8);
    seed_address.sin_family = AF_INET;
    seed_address.sin_port = htons(std::stoi(teste_peer[1]));
    inet_aton(teste_peer[0].c_str(), &seed_address.sin_addr);
//
    _data = DataGrama(2, 0, "cc72fc24056ced9ce13a287ca1243d48");

    std::cout << "Pedindo Arquivo para Peer" << std::endl;

    if (sendto(socket_fd, DataGramaSerial(_data), _data.ByteSizeLong(), 0,
               (struct sockaddr *) &seed_address, sizeof(struct sockaddr)) <= 0)
        error("Erro ao enviar");


}
