# Lista de Exercícios – Lista 4

## Exercícios

  1. Descreva os passos para estabelecimento de uma conexão (three-way handshake) e para a finalização da mesma.
      Conexão
        1. Cliente encaminha [SYNbit=1, seq=x]
        2. Servidor recebe etapa 1 encaminha [SYNbit=1, seq=y, ACKseq=x+1]
        3. Cliente recebe etapa 2 encaminha [SYNbit=0, seq=x+1, ACKseq=y+1]
        4. Em 3 já podem começar a troca de informação.
      Finalização 
        1. Cliente solicita o fechamento encaminha [FIN=1, seq=x] 
        2. Servidor recebe etapa 1 e encaimnha uma confirmação só que não finaliza proque ela pode estar encaminhando dados ainda então so confirma com [FIN=0, ACK=x+1]
        3. Cliente recebe a confirmação do servidor então sabe que pode ligar um temporizador senão teria que retransmitir o pacote de encerramento!
        4. Servidor termina de enviar dados para o cliente de solicitações anteriores e envia [FINbit=1 seq=y] (acredito que poderia adicionar um timeoutput aqui)
        5. Cliente confirma o encerramento e finaliza com o envio de um [ACK=y+1]
 
  2. Quando uma conexão é fechada, por que não são necessárias temporizações (timeouts) na transição de LAST_ACK para CLOSED? 
    R: O servidor ja está ciente que o cliente pediu o encerramento se ele termino de transmitir os dados que estavam pendendentes, basta posteriormente encaminhar um [FIN=1,seqy] para o cliente assim o fim da transmissão e realizado sem ter a necessidade de receber a confirmação do encerramento para o cliente que iniciou um temporizador para encerramento.

  3. No  protocolo  de  janelas  deslizantes  utilizado  no  TCP,  um  emissor  que  recebe  uma  janela de anúncio (AdvertisedWindow) igual a 0 periodicamente consulta o receptor para saber se o  tamanho  da  janela  tornou-se  diferente  de  zero.  Se  considerássemos  um  caso  hipotético em  que  o  receptor  fosse  o  responsável  por  informar o  emissor  o  momento  em  que  a  sua janela  de  anúncio  se  tornasse  maior  que  zero,  veríamos  que  o  receptor  precisaria  de  um temporizador extra. Por quê?
        * R : O receptor teria a necessidade de alertar o transmissor o momento que o ele se encontrasse com um valor de janela maior que 0 ou outro tamanho da janela, assim para o transmissor ficar sabendo deste valor o receptor teria que notificalo com uma mensagem,  utilizar um temporizador de tempos em tempos ele realiza o anuncio do tamanho de janela se esta estiver maior que 0 para o transmissor, senão espera mais um tempo para outra tentativa.  

  4. O  tamanho  do  campo  “Sequence  Number”  no  cabeçalho  TCP  é  de  32  bits,  o  que corresponde  a  uma  cobertura  de  mais  de  4  bilhões  de  bytes  de  dados.  Mesmo  que  esse montante de dados não seja transferido em uma única conexão TCP, por que o número de sequência ainda pode passar de 2^32-1 para 0?
      * R: 

  5. Você  foi  contratado  para  projetar  um  protocolo  baseado  em  fluxo  de  bytes  e  que implemente  a  ideia  de  janelas  deslizantes,  tal  como  o  TCP.  O  protoloco  a  ser  projetado deverá executar em cima de uma rede de 1 Gbps. O RTT (round trip time) dessa rede é de 140  ms  e  o  tempo  de  vida de  um  segmento  é  de  60  segundos.  Quantos  bits  você  incluiria nos campos AdvertisedWindow e SequenceNum do cabeçalho do seu protocolo?
       * R: 0.140 * 10^6 / 8

  6.  Se um nó A recebe dois pacotes com as respectivas flags SYN configuradas em 1 a partir de  uma  mesma  porta.  O  segundo  pacote  pode  ser  uma  retransmissão  do  primeiro  ou  uma nova requisição de conexão caso o nó remoto tenha sofrido uma falha e perdido a conexão anterior. 
    a. Como o nó A consegue distinguir entre os dois casos? 
      * R A) Para identificar se o pacote de sincronização e uma retransmissão basta obervar o numero de sequencia enviado pelo cliente, se for o mesmo do numero de sequencia X anteriormente encaminhado,  então é uma retransmissão senão tratasse de um nova conexão porque o numero de sequencia será outro aleatoriamente selecionado diferente de X.
          
           
    b. Descreva  um  algoritmo  sobre  o  que  o  TCP  deve  fazer ao  receber  um  pacote SYN de abertura de conexão. Considere os dois casos descritos acima e ainda a possibilidade de nenhum processo estar escutando na porta de destino. 
      * R Retransmissão)
            * Cliente encaminha pacote com sync 1 e seq x
            * Servidor recebe e encaminha [sync 1, seq y, ACKnum=x+1]
            * Cliente encaminha novamente uma mensagem [sync 1, seq x]
            * Servidor recebe e percebe que o seq x já foi utilizado anteriormente e entende que o cliente não recebeu a mensagem [sync 1, seq y, ACKnum=x+1] então retransmite a novamente ela
            *  Daqui pra frente e normal o solicitação de abertura
      * R Nova requisição
            * Cliente encaminha pacote com sync 1 e seq x
            * Servidor recebe e encaminha [sync 1, seq y, ACKnum=x+1]
            * Cliente encaminha pacote [sync 1, seq k]
            * Servidor recebe e percebe que o numero de sequencia não esta na faixa da janela e assim sabe que é uma nova conexão

  7. O  algoritmo  de  Nagle  requer  que  o  emissor  mantenha um  segmento  de  dados  parcial  até que os dados atinjam o tamanho de um segmento (mesmo que haja dados sinalizados como prioritários) ou chegue um ACK pendente do receptor. 
     a. Suponha  que  as  letras abcdefghi  sejam  enviadas,  uma  por  segundo,  através de  uma  conexão TCP  cujo  RTT  seja  igual a  4,1  segundos.  Desenhe  uma  linha indicando quando cada pacote é enviado e o que ele contém. 
      * R:
 
  