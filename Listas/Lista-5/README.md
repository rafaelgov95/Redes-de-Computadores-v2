# Lista de Exercícios – Lista 3

## Exercícios
 1. Admitindo-se  que  TCP  Reno  é  o  protocolo  que  experimenta  o  comportamento mostrado  no  gráfico responda  às  seguintes  perguntas.  Em  todos  os  casos  você  deverá apresentar uma justificativa resumida para sua resposta
    
    a. Quais os intervalos de tempo em que a partida lenta do TCP está em execução?
     * Do tempo 0 ao tempo 6, do tempo 23 ao 26
      
    b. Quais  os  intervalos  de  tempo  que  a  prevenção  de  congestionamento  do  TCP  está  em execução 
      * Do tempo 6 ao 16 e do 15 ao 22.
       
    c. Após a 16ª rodada de transmissão, a perda de segmento será detectada por três ACKs duplicados ou por um esgotamento de temporização? 
      * 3 ACks duplicado se fosse o temporizador iria o mss iria ser 1 e volta para prevenção de congestionamento.

    d. Após a 22ª rodada de transmissão, a perda de segmento será detectada por três ACKs duplicados ou por um esgotamento de temporização?
      * Por um esgotamento do temporizador assim o mss vai para 1 e apartida lenta e iniciada.
       
    e. Qual é o valor inicial de Threshold na primeira rodada de transmissão? 
      * Ele possui 32 segmentos nesta rodada.
    
    f. Qual é o valor inicial de Threshold na 18ª rodada de transmissão?
      * Ele possui 21 segmentos nesta rodada.
  
    g. Qual é o valor de Threshold na 24ª rodada de transmissão?
      * Ele possui 12+3 segmentos nesta rodada.

    h. Durante qual rodada de transmissão é enviada o 70º segmento? 
      * Entre 8 e 10!

    i. Admitindo-se que uma perda de pacote será detectada após a 26ª rodada pelo recebimento de três ACKs duplicados, quais serão os valores do tamanho da janela de congestionamento e de Threshold
      * threshold =12+3
      * cmwd = janela+3

  2. Considere os seguintes dados do algoritmo de controle de congestionamento do TCP Reno (combinação de partida lenta, aumento aditivo/diminuição multiplicativa e retransmissão/recuperação rápida): MSS = 1460 bytes,  Threshold = 64Kbps,  CongWin = 8 MSS  e RTT=1s.    
     a. Qual a taxa atual de transmissão? 
      * 64kbps/1s = 8 KB

     b. Se todos os bytes transmitidos forem confirmados com sucesso, qual será a nova taxa de transmissão após 1 RTT ?
      *

     c. Caso haja uma falha por temporização, qual será a nova taxa máxima de transmissão? 
      * 