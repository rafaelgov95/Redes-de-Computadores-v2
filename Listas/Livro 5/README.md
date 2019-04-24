# Lista de Exercícios – Congestionamento

## Exercícios

### P43
* Neste problema, não há perigo em transbordar o receptor, uma vez que o receptor recebe buffer pode conter o arquivo inteiro. Além disso, porque não há perda e os reconhecimentos são retornado antes que os temporizadores expirem, o controle de congestionamento do TCP não estrangula o remetente. No entanto, o processo no host A não transmitirá dados continuamente para o soquete porque O buffer de envio será rapidamente preenchido. Quando o buffer de envio ficar cheio, o processo passará dados a uma taxa média ou R << S
### P44
*  a. Leva 1 RTT para aumentar o CongWin para 6 MSS; 2 RTTs para aumentar para 7 MSS; 3 RTTs aumentar para 8 MSS; 4 RTTs para aumentar para 9 MSS; 5 RTTs para aumentar para 10 MSS; 6 RTTs para aumentar para 11 MSS; e 7 RTTs para aumentar para 12MSS.
*  b) No primeiro RTT 5 MSS foi enviado; no segundo RTT 6 MSS foi enviado; no terceiro RTT 7 MSS foi enviado; no quarto RTT 8 MSS foi enviado; no quinto RTT, 9 MSS foi enviado; e no sexto RTT, 10 MSS foram enviados. Assim, até o momento 6 RTT, 5 + 6 + 7 + 8 + 9 + 10 = 45 MSS foram enviados (e confirmados). Assim, podemos dizer que o taxa de transferência média até o tempo 6 RTT foi (45 MSS) / (6 RTT) = 7,5 MSS / RTT.


### P45(opcional),

### P46
* A) Deixe W denotar o tamanho máximo da janela medido em segmentos. Então, W * MSS / RTT = 10 Mbps, pois os pacotes serão descartados se a taxa máxima de envio exceder o link capacidade. Assim, temos W * 1500 * 8 / 0.15 = 10 * 10 ^ 6, então W tem cerca de 125 segmentos.
* B) Como o tamanho da janela de congestionamento varia de W / 2 para W, o tamanho médio da janela é 0.75W = 94 (teto de 93,75) segmentos. O rendimento médio é de 94 *  1500 * 8 / 0,15 = 7,52 Mbps
* C) 94/2 * 0.15 = 7.05 segundos, como o número de RTTs (que esta conexão TCP precisa para aumentar o tamanho da janela de W / 2 para W) é dado por W / 2. Lembre-se do o tamanho da janela aumenta em um em cada RTT.
  
### P47
* Deixe W denotar o tamanho máximo da janela. Deixe S denotar o tamanho do buffer. Para simplificar, suponha O remetente TCP envia pacotes de dados de uma forma redonda para redonda, com cada ciclo correspondendo a um RTT. Se o tamanho da janela atingir W, ocorrerá uma perda. Então o remetente cortará o tamanho da sua janela de congestionamento pela metade e aguardará os ACKs por W / 2 pacotes pendentes antes de começar a enviar segmentos de dados novamente. Para ter certeza o link sempre ocupado enviando dados, precisamos deixar o link ocupado enviando dados no período W / (2 * C) (este é o intervalo de tempo em que o remetente está aguardando os ACKs para o W / 2 pacotes pendentes). Assim, S / C não deve ser menor que W / (2 * C), isto é, S> = W / 2. Deixe Tp denotar o atraso de propagação unidirecional entre o remetente e o receptor. Quando o tamanho da janela atinge o mínimo W / 2 e o buffer está vazio, precisamos Verifique se o link também está ocupado enviando dados. Assim, devemos ter W / 2 / (2Tp)> = C, assim, W / 2> = C * 2Tp. Assim, S> = C * 2Tp.
 
### P48
* A) Deixe W denotar o tamanho máximo da janela. Então, W * MSS / RTT = 10Gbps, como os pacotes ser descartado se a taxa máxima de envio atingir a capacidade do link. Assim, nós temos W * 1500 * 8 / 0,15 = 10 * 10 ^ 9, depois W = 125000 segmentos.

* B)Como o tamanho da janela de congestionamento varia de W / 2 para W, o tamanho médio da janela é 0,75 W = 93750 segmentos. A taxa de transferência média é 93750 * 1500 * 8 / 0,1 = 7,5Gbps.
 
* C) 93750/2 * 0,15 / 60 = 117 minutos. Para acelerar o processo de aumento da janela, podemos aumentar o tamanho da janela por um valor muito maior, em vez de aumentar tamanho da janela apenas por um em cada RTT. Alguns protocolos são propostos para resolver problema, como ScalableTCP ou TCP de Alta Velocidade.
### P50
* A principal diferença entre C1 e C2 é que o RTT de C1 é apenas metade do de C2. Assim, C1 ajusta seu tamanho de janela após 50 ms, mas C2 ajusta seu tamanho de janela após 100 ms. Suponha que sempre que um evento de perda acontece, C1 recebe após 50 ms e C2 recebe após 100 ms. Além disso, temos o seguinte modelo simplificado de TCP. Após cada RTT, uma conexão determina se deve aumentar o tamanho da janela ou não. Para C1, calculamos a taxa média total de envio no link nos 50 anos anteriores ms. Se essa taxa exceder a capacidade do link, então assumimos que C1 detecta perda e reduz o tamanho da janela. Mas, para C2, calculamos a taxa média total de envio no link nos 100 ms anteriores. Se essa taxa exceder a capacidade do link, então assumimos C2 detecta perda e reduz o tamanho da janela. Note que é possível que o A taxa média de envio nos últimos 50 ms é maior do que a capacidade do link, mas a média taxa de envio nos últimos 100 ms é menor ou igual à capacidade do link, então neste No caso, assumimos que C1 terá um evento de perda, mas C2 não. A tabela a seguir descreve a evolução dos tamanhos das janelas e as taxas de envio com base nas hipóteses acima. Com base na tabela acima, descobrimos que, após 1000 ms, os tamanhos das janelas de C1 e C2 são 1 segmento cada
* B) Não. No longo prazo, o compartilhamento de largura de banda de C1 é aproximadamente duas vezes maior do que o de C2, porque C1 tem RTT mais curto, apenas metade do de C2, então C1 pode ajustar seu tamanho de janela duas vezes rápido como C2. Se olharmos para a tabela acima, podemos ver um ciclo a cada 200 ms, por ex. de 850ms a 1000 ms, inclusive. Dentro de um ciclo, a taxa de envio de C1 é (40 + 20 + 40 + 20) = 120, que é três vezes maior que o envio de C2 dado por (10 + 10 + 10 + 10) = 40.
 
### P51
* a) Da mesma forma como no último problema, podemos calcular os tamanhos das janelas ao longo do tempo no tabela seguinte. Ambos C1 e C2 têm o mesmo tamanho de janela 2 após 2200 ms.

* B) Yes, this is due to the AIMD algorithm of TCP and that both connections have the same RTT.

* c) Yes, this can be seen clearly from the above table. Their max window size is 2. 
  
* d) No, this synchronization won’t help to improve link utilization, as these two connections act as a single connection oscillating between min and max window size. Thus, the link is not fully utilized (recall we assume this link has no buffer). One possible way to break the synchronization is to add a finite buffer to the link and randomly drop packets in the buffer before buffer overflow. This will cause different connections cut their window sizes at different times. There are many AQM (Active Queue Management) techniques to do that, such as RED (Random Early Detect), PI (Proportional and Integral AQM), AVQ (Adaptive Virtual Queue), and REM (Random Exponential Marking), etc.
### P56

* a) Referindo-nos à figura abaixo, vemos que o atraso total é
    * RTT + RTT + S / R + RTT + S / R + RTT + 12 S / R = 4RTT + 14 S / R
* b) Da mesma forma, o atraso neste caso é:
    * RTT + RTT + S / R + RTT + S / R + RTT + S / R + RTT + 8 S / R = 5RTT +11 S / R
* c) Da mesma forma, o atraso neste caso é:
    * RTT + RTT + S / R + RTT + 14 S / R = 3 RTT + 15 S / R