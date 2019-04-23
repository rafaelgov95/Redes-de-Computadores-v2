# Lista de Exercícios – Lista 3

## Exercícios
 1. Admitindo-se  que  TCP  Reno  é  o  protocolo  que  experimenta  o  comportamento mostrado  no  gráfico responda  às  seguintes  perguntas.  Em  todos  os  casos  você  deverá apresentar uma justificativa resumida para sua resposta
    
    a. Quais os intervalos de tempo em que a partida lenta do TCP está em execução?
     * A partida lenta do TCP está em execução nos intervalos [1, 6] e [23, 26], pois a janela  de  congestionamento  está  aumentando  exponencialmente,  sendo  duplicada a cada RTT.
      
    b. Quais  os  intervalos  de  tempo  que  a  prevenção  de  congestionamento  do  TCP  está  em execução 
      * Nos intervalos [6, 16] e [17, 22]. Para a prevenção de congestionamento o TCP aumenta sua janela de congestionamento em um segmento a cada RTT.
       
    c. Após a 16ª rodada de transmissão, a perda de segmento será detectada por três ACKs duplicados ou por um esgotamento de temporização? 
      * Foi detectados 3 ACks duplicados, se fosse o temporizador o mss iria cair para 1 e neste caso cai para metade de seu valor.

    d. Após a 22ª rodada de transmissão, a perda de segmento será detectada por três ACKs duplicados ou por um esgotamento de temporização?
      * Por um esgotamento do temporizador assim o mss vai para 1 e apartida lenta e iniciada.
       
    e. Qual é o valor inicial de Threshold na primeira rodada de transmissão? 
      * O valor do Threshold é 32, uma vez que a partir desse valor termina a partida lenta e inicia a prevenção de congestionamento
    
    f. Qual é o valor inicial de Threshold na 18ª rodada de transmissão?
      * Sempre que ocorre um evento de perda o valor de Threshold é ajustado para a metade do valor corrente da janela de congestionamento. Quando a perda foi  detectada durante a 16ª rodada, o tamanho da janela de congestionamento era 42. Assim, o Threshold é 21 no início da 18ª rodada de transmissão, e 22 ao término dessa rodada.
  
    g. Qual é o valor de Threshold na 24ª rodada de transmissão?
      * Sempre que ocorre um evento de perda o valor de Threshold é ajustado para a metade do valor corrente da janela de congestionamento. Quando a perda foi detectada durante a 22ª rodada, o tamanho da janela de congestionamento era 26. Assim, o Threshold é 13 na 24ª rodada de transmissão.

    h. Durante qual rodada de transmissão é enviada o 70º segmento? 
      * Durante a 1ª rodada de transmissão, o pacote 1 é enviado; os pacotes 2 e 3 são enviados na 2ª rodada de transmissão; os pacotes de 4 a 7 são enviados na 3ª rodada de transmissão; os pacotes de 8 a 15 são enviados na 4ª rodada de transmissão; os pacotes de 16 a 31 são enviados na 5ª rodada de transmissão; os pacotes de 32 a 63 são enviados na 6ª rodada de transmissão; os pacotes de 64  a  96  são  enviados  na  7ª  rodada  de    transmissão. Assim,  o  pacote  70  é enviado na 7ª rodada de transmissão.

    i. Admitindo-se que uma perda de pacote será detectada após a 26ª rodada pelo recebimento de três ACKs duplicados, quais serão os valores do tamanho da janela de congestionamento e de Threshold
      * O  Threshold  será  reduzido  a  metade  do  valor  corrente  da  janela  de  congestionamento  (8),  Assim,  o  Threshold  será  4.  Já  a  janela  de congestionamento será Threshold mais três vezes o valor de um segmento, por causa  dos  três  segmentos  que  geraram  os  três  acks  duplicados,  então  o tamanho da janela será 7 (4+3)

  1. Considere os seguintes dados do algoritmo de controle de congestionamento do TCP Reno (combinação de partida lenta, aumento aditivo/diminuição multiplicativa e retransmissão/recuperação rápida): MSS = 1460 bytes,  Threshold = 64Kbps,  CongWin = 8 MSS  e RTT=1s.    
     a. Qual a taxa atual de transmissão? 
      * Resposta: Taxa transmissão = Tamanho_Janela(cong*mss)/RTT
      * (8 MSS/ RTT) = ((8 * 1460 Bytes * 8)/1)  = 93,44 Kbps 


     b. Se todos os bytes transmitidos forem confirmados com sucesso, qual será a nova taxa de transmissão após 1 RTT ?
      * Resposta: Como CongWin > Thrshold, está na fase de prevenção de congetionamento. A cada  pacote  (de  1  MSS)  confirmado  (ACK),  aumenta-se  linearmente  a  janela  de congestionamento, na proporção: Incremento = MSS * (MSS/CongestionWindow) = MSS * (MSS/8*MSS) = 1/8 * MSS. Portanto, após 1 RTT, todos os bytes transmitidos foram confirmados (8 MSS), e com isso a  janela  terá  um aumento  de  1  MSS  (8  *  1/8  *  MSS  ),  ou  seja,  a  janela  de congestionamento (CongWin) passa a ter 9MSS.  Assim a taxa de transmissão passa para 9 MSS/1s = 105,12 Kbps 

     c. Caso haja uma falha por temporização, qual será a nova taxa máxima de transmissão? 
      * Caso haja timeout, a janela de congestionamento é diminuída para 1 MSS, o que significa que a nova taxa máxima de transmissão é de (1 * 1460 * 8)/1 = 11,68 Kbps. Relembrando:  partida  lenta  o  tamanho  da  janela  dobra  a  cada  RTT  até  atingir  o threshold, a partir de onde o aumento passa a ser aditivo (aprox 1 MS a cada RTT, quando há sucesso "prevenção de congestionamento"). 