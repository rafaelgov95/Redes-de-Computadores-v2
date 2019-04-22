# Lista de Exercícios – Lista 3

## Exercícios
 1. Admitindo-se  que  TCP  Reno  é  o  protocolo  que  experimenta  o  comportamento mostrado  no  gráfico responda  às  seguintes  perguntas.  Em  todos  os  casos  você  deverá apresentar uma justificativa resumida para sua resposta
    
    a. Quais os intervalos de tempo em que a partida lenta do TCP está em execução?
    
    b. Quais  os  intervalos  de  tempo  que  a  prevenção  de  congestionamento  do  TCP  está  em execução 
    
    c. Após a 16ª rodada de transmissão, a perda de segmento será detectada por três ACKs duplicados ou por um esgotamento de temporização? 
    
    d. Após a 22ª rodada de transmissão, a perda de segmento será detectada por três ACKs duplicados ou por um esgotamento de temporização?
    
    e. Qual é o valor inicial de Threshold na primeira rodada de transmissão? 
    
    f. Qual é o valor inicial de Threshold na 18ª rodada de transmissão?
    
    g. Qual é o valor de Threshold na 24ª rodada de transmissão? h.Durante qual rodada de transmissão é enviada o 70º segmento? 
    
    i. Admitindo-se que uma perda de pacote será detectada após a 26ª rodada pelo recebimento de três ACKs duplicados, quais serão os valores do tamanho da janela de congestionamento e de Threshold

  2. Considere os seguintes dados do algoritmo de controle de congestionamento do TCP Reno (combinação de partida lenta, aumento aditivo/diminuição multiplicativa e retransmissão/recuperação rápida): MSS = 1460 bytes,  Threshold = 64Kbps,  CongWin = 8 MSS  e RTT=1s.    
     a. Qual a taxa atual de transmissão? 

     b. Se todos os bytes transmitidos forem confirmados com sucesso, qual será a nova taxa de transmissão após 1 RTT ?

     c. Caso haja uma falha por temporização, qual será a nova taxa máxima de transmissão? 
   