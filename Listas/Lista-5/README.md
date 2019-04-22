# Lista de Exercícios – Lista 3

## Exercícios

  1. Considere um protocolo simples para transferência de arquivos. Após uma negociação inicial, A envia pacotes de tamanho 1 KB para B; B então responde com um reconhecimento (ACK). A sempre espera por cada ACK antes de enviar o próximo pacote de dados. Isso é conhecido como protocolo stop-and-wait. Pacotes atrasados são supostos como perdidos e retransmitidos. 

    a) Na ausência de perdas e duplicações, explique porque não é necessário a inclusão de um “número de seqüência” no cabeçalho do protocolo.
      
      * Em um protocolo stop-and-wait com ausência de perdas e duplicações, o número de sequências não é necessario basta A encaminhar um pacote para B e B responder com ACK para A e assim podendo criar uma retro alimentação confiavel entre A e B.


    b) Suponha que o enlace ocasionalmente perde pacotes, mas que os pacotes chegam sempre na ordem enviada. Um número de sequência de 2 bits é suficiente para que A e B detectem e reenviem os pacotes perdidos? E um  número de sequência de 1 bit é suficiente? 
    
    
    c) Suponha agora que  o enlace possa entregar os pacotes fora de ordem, e que às vezes o pacote pode ser entregue até 1 minuto após pacotes subseqüentes. Como isso altera os requisitos para o número de sequência?

  2) Suponha que você esteja projetando um protocolo de janela deslizante para um enlace ponto  a  ponto  de  1  Mbps  para  um  satélite  estacionário  à  3  x  104  km  de  altitude. Considerando que cada pacote carrega 1 KB de dados, qual o número mínimo de bits será necessário para o “número de sequência” nos seguintes casos? Suponha velocidade da luz igual a 3 x 108 m/s. 
    a.RWS = 1
    b.RWS = SWS 

  3) Desenhe um diagrama com a linha do tempo para o algoritmo de janela deslizante, com tamanho de 3 quadros para a janela do emissor (SWS) e do receptor (RWS), para os casos a seguir. Use um intervalo de timeout de 2 x RTT.   OBS: Desenhe o diagrama até o envio do décimo quadro, e mostre as mensagens de controle trocadas entre emissor e receptor, eventos  de timeout,  situação  da  janela,  e  tudo  que  achar  importante  para  o entendimento do funcionamento do algoritmo.
    
    a) Considere que o quarto quadro foi perdido. 
    b) Quadros 4, 5 e 6 são perdidos. 