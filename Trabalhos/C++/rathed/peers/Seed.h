//
// Created by rafael on 08/04/19.
//

#ifndef UNTITLED_SEEDS_H
#define UNTITLED_SEEDS_H


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
#include "model.pb.h"
#include "thread"
#include "util.h"
#include <unistd.h>

#define MAX_LENGTH_DATAG 360
#define MAX_LENGTH_FILE 350

class Seed {

private:
    int rastreadorPorta=8080;
    fd_set socketoriginal;
    fd_set readfds;
    struct timeval tv;
    int numfd = 1;
    int socket_fd, bytes_read,bytes_total;
    unsigned int address_length;
    char recieve_data[MAX_LENGTH_DATAG], send_data[MAX_LENGTH_FILE];
    struct sockaddr_in server_address, client_address,rastreador_address;
    std::vector<std::pair<std::string,std::string>> file;
    void run();
   void atualizarRastreador( std::string hash);
    void tratarMensagem(rathed::Datagrama data);
    void EnviarArquivo(rathed::Datagrama data);
    void atualizacaoRealizada(rathed::Datagrama data);
    void consultaFileSize(rathed::Datagrama data);
    void confirmaEnvio(rathed::Datagrama *datagrama);
    void Desconectar();
public:
    Seed(int porta);
    ~Seed();



};


#endif //UNTITLED_SEEDS_H
