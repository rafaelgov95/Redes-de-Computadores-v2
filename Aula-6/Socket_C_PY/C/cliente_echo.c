#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/socket.h>     /* struct sockaddr, socket */
#include <netinet/in.h>     /* struct sockaddr_in */
#include <arpa/inet.h>      /* inet_pton, htons */
#include <unistd.h>         /* read */

#define BUFFSIZE 32
#define SA struct sockaddr

void error(char *msg);

int main(int argc, char *argv[])
{
  int sockfd, received = 0, bytes = 0;;
  struct sockaddr_in servaddr;
  char buffer[BUFFSIZE];
  unsigned int echolen;
  
  if (argc != 4)
    error("Use: TCPecho <server_ip> <palavra> <porta>");
  
  if((sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    error("Falha ao criar o socket");
  
  /* Inicializando a estrutura */
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(atoi(argv[3]));

  /* Estabelecendo conexao */
  if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
    error("Falha ao conectar ao servidor");
  
  /* Envia a palavra ao servidor */
  echolen = strlen(argv[2]);
  if (send(sockfd, argv[2], echolen, 0) != echolen)
    error("Envio falhou ao enviar todos os bytes");

  /* Recebendo a palavra como resposta do servidor */
  printf("Recebido: ");

  while(received < echolen) 
    {
      if((bytes = recv(sockfd, buffer, BUFFSIZE-1, 0)) < 1)
	error("Falhou ao receber os bytes do servidor");

      received += bytes;
      buffer[bytes] = '\0';
      printf("%s", buffer);
    }
  
  printf("\n");
  
  close(sockfd);
  exit(0);
}

/* Imprime mensagens de erro */
void error(char *msg)
{
  printf("%s\n", msg);
  exit(0);

  return;
}
