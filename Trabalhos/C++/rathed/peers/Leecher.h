//
// Created by rafael on 08/04/19.
//

#ifndef UNTITLED_LEECHERS_H
#define UNTITLED_LEECHERS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


#define MAXLINE 1024
#define T_PACOTE 160; //tamanho do pacote

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>//use select() for multiplexing
#include <sys/fcntl.h> // for non-blocking
#include "iostream"
#include "vector"
#include "thread"
#include "util.h"
#include "model.pb.h"
#define MAX_LENGTH 160

class Leecher {

private:
    int rastreadorPorta=8080;
    fd_set socketoriginal;
    fd_set readfds;
    struct timeval tv;
    int numfd = 1;
    int socket_fd, bytes_read;
    unsigned int address_length;
    char recieve_data[MAX_LENGTH], send_data[MAX_LENGTH];
    struct sockaddr_in server_address, client_address,rastreador_address;
    std::vector<std::pair<std::string,std::vector<std::string>>> tableFiles;
    void run();
    void responseP2P( rathed::Datagrama data);
    void baixar();
    void consultarRastreador();
public:
   Leecher(int porta);

};


#endif //UNTITLED_LEECHERS_H
