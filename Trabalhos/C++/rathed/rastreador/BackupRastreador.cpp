//
// Created by rafael on 08/04/19.
//

#include "Rastreador.h"


// private functions
void error(char *message)
{
    perror(message);
    exit(1);
}

void Rastreador::run() {
    if (bind(socket_fd,(struct sockaddr *)&server_address, sizeof(struct sockaddr)) == -1) // atribui ip
    {
        error("bind()"); // erro se der merd@
    }
    address_length = sizeof(struct sockaddr); //tamanh do endereco ipv4
    printf("\nRastreador Iniciado\n");
    printf("(Q ou q) para sair\n");
    while (1)
    {
//        readfds = original_socket; // readfds le do escritor fds
//        writefds = original_stdin; // escreve no escritor stdin
//        int recieve = select(numfd, &readfds, &writefds,/*NULL,*/ NULL, &tv);
//        std::cout<<"entrou1"<<std::endl;

        int recieve = select(numfd, &readfds, NULL, NULL,&tv);
        if (recieve == -1)
        {
            perror("select"); // erro no select()
        }
//        else if (recieve == 0)
//        {
//            std::cout<<"entrou2"<<std::endl;

//            close(socket_fd);/
//            printf("Timeout occurred!  No data after 10.5 seconds.\n"); //erro ainda não sei
//        }
//        else
//        {
//            std::cout<<"entrou3"<<std::endl;

            // one or both of the descriptors have data
//            if (FD_ISSET(socket_fd, &readfds)) //if set to read
//            {
//                FD_CLR(socket_fd, &readfds);
//              std::cout<<"ultimo"<<std::endl;
                bytes_read = recvfrom(socket_fd,recieve_data,MAX_LENGTH,0,(struct sockaddr *)&client_address, &address_length); //block call, will wait till client enters something, before proceeding
//                std::cout<<"paro aqui"<<std::endl;
                recieve_data[bytes_read] = '\0'; //add null to the end of the buffer
                if((strcmp(recieve_data , "q") == 0) || (strcmp(recieve_data , "Q") == 0)) { //if client quit, then quit also
                    printf("\nClient has exited the chat.\n");
                    break;
                }
                in_addr ip=client_address.sin_addr;
                uint16_t porta = ntohs(client_address.sin_port);
                consultaRastreador(ip,porta,recieve_data);// funcao de buscar Hash

//            }
//            else if (FD_ISSET(/*socket_fd*/0, &writefds)) //if set to write
//                //else
//            {
//                FD_CLR(0, &writefds);
//                printf("SERVER: ");
////                fgets (send_data, MAX_LENGTH, stdin); //input the name with a size limit of MAX_LENGTH
//                if ((strlen(send_data)>0) && (send_data[strlen (send_data) - 1] == '\n')) //if there is a trailing \n, remove it
//                {
//                    send_data[strlen (send_data) - 1] = '\0';
//                }
//                if ((strcmp(send_data , "q") == 0) || (strcmp(send_data , "Q") == 0)) { //if user enters q, then quit
//                    sendto(socket_fd,send_data,strlen(send_data),0,(struct sockaddr *)&client_address, sizeof(struct sockaddr));
//                    break;
//                }
//                fflush(stdout);
//            }
//            else printf("\nOOPS! What happened? SERVER");
//        } //end else
    }//end while

}

Rastreador::~Rastreador(){
    close (socket_fd);
//    return 0;
}
// public functions
Rastreador::Rastreador(int porta) {

    if ((socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        error("socket()");
    }
//    int flags = fcntl(socket_fd, F_GETFL);
//    flags |= O_NONBLOCK;
//    fcntl(socket_fd, F_SETFL, flags);
    //fcntl(socket_fd, F_SETFL, O_NONBLOCK); //set socket to non-blocking
//     clear the set ahead of time
//    FD_ZERO(&original_socket);
//    FD_ZERO(&original_stdin);
    FD_ZERO(&readfds);
//    FD_ZERO(&writefds);
    // add our descriptors to the set (0 - stands for STDIN)
//    FD_SET(socket_fd, &original_socket);//instead of 0 put socket_fd
    FD_SET(socket_fd, &readfds);
//    FD_SET(0,&original_stdin);
//    FD_SET(0, &writefds);
    // since we got s2 second, it's the "greater", so we use that for
    // the n param in select()
    numfd = socket_fd + 1;
    // wait until either socket has data ready to be recv()d (timeout 10.5 secs)
    tv.tv_sec = 10;
    tv.tv_sec = 0;

    tv.tv_usec = 500000;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(porta);
    server_address.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_address.sin_zero),8);
    run();
}

void Rastreador::stopDTH(){

}

void Rastreador::uploadingFile(std::string hash, std::vector<std::string>) {

}

void Rastreador::downloadFile(std::string hash, std::vector<std::string>) {

}
void Rastreador::enviarSeeds(std::string hash, std::vector<std::string>) {

}

void Rastreador::consultaRastreador(in_addr ip, uint16_t porta,std::string hash) {
    std::cout<<"Rastreador em Construção:"<<porta<<":"<<hash<<std::endl;
    strncpy(send_data,"Rastreador em Construção\n",28);
    sendto(socket_fd,send_data,strlen(send_data),0,(struct sockaddr *)&client_address, sizeof(struct sockaddr));
}
