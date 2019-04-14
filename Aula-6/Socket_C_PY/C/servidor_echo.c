#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/socket.h>     /* recv, send */
#include <arpa/inet.h>      /* struct sockaddr */
#include <unistd.h>         /* exit */

#define BUFFSIZE 32
#define MAXPENDING 5
#define SA struct sockaddr

void error(char *msg);

int main(int argc, char *argv[])
{
  int listenfd, connfd, clientlen, n;
  char buffer[BUFFSIZE];
  struct sockaddr_in servaddr, client;

  if(argc != 2)
    error("Use: SERVERecho <porta>");
  
  if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    error("Falha ao criar o socket");

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));

  if(bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
    error("Falha ao observar o socket do servidor");

  if(listen(listenfd, MAXPENDING) < 0)
    error("Falha ao tentar escutar o socket do servidor");

  for( ; ; )
    {
      n = -1;
      clientlen = sizeof(client);

      if((connfd = accept(listenfd, (SA *) &client, &clientlen)) < 0)
	error("Falhou ao aceitar a conexao do cliente");

      printf("Cliente connectado: %s:%d\n", inet_ntoa(client.sin_addr),client.sin_port);

      if((n = recv(connfd, buffer, BUFFSIZE, 0)) < 0)
	error("Falhou ao receber os dados iniciais do cliente");
  
      while(n > 0)
	{
	  if(send(connfd, buffer, n, 0) != n)
	    error("Falhou ao enviar os dados devolta para o cliente");
	
	  if((n = recv(connfd, buffer, BUFFSIZE, 0)) < 0)
	    error("Falhou ao receber os dados restantes do cliente");
	}
      close(connfd);
    }

  exit(0);
}

/* Imprime mensagens de erro */
void error(char *msg)
{
  printf("%s\n", msg);
  exit(0);

  return;
}
