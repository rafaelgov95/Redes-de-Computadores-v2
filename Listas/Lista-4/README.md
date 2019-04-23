# Lista de Exercícios – Lista 4

## Exercícios

  1. Descreva os passos para estabelecimento de uma conexão (three-way handshake) e para a finalização da mesma.
     * Conexão
        1. Cliente encaminha [SYNbit=1, seq=x]
        2. Servidor recebe etapa 1 encaminha [SYNbit=1, seq=y, ACKseq=x+1]
        3. Cliente recebe etapa 2 encaminha [SYNbit=0, seq=x+1, ACKseq=y+1]
        4. Em 3 já podem começar a troca de informação.
     * Finalização 
        1. Cliente solicita o fechamento encaminha [FIN=1, seq=x] 
        2. Servidor recebe etapa 1 e encaimnha uma confirmação só que não finaliza proque ela pode estar encaminhando dados ainda então so confirma com [FIN=0, ACK=x+1]
        3. Cliente recebe a confirmação do servidor então sabe que pode ligar um temporizador senão teria que retransmitir o pacote de encerramento!
        4. Servidor termina de enviar dados para o cliente de solicitações anteriores e envia [FINbit=1 seq=y] (acredito que poderia adicionar um timeoutput aqui)
        5. Cliente confirma o encerramento e finaliza com o envio de um [ACK=y+1]
 
  2. Quando uma conexão é fechada, por que não são necessárias temporizações (timeouts) na transição de LAST_ACK para CLOSED? 
    * R: O servidor ja está ciente que o cliente pediu o encerramento se ele termino de transmitir os dados que estavam pendendentes, basta posteriormente encaminhar um [FIN=1,seqy] para o cliente assim o fim da transmissão e realizado sem ter a necessidade de receber a confirmação do encerramento para o cliente que iniciou um temporizador para encerramento.

  3. No  protocolo  de  janelas  deslizantes  utilizado  no  TCP,  um  emissor  que  recebe  uma  janela de anúncio (AdvertisedWindow) igual a 0 periodicamente consulta o receptor para saber se o  tamanho  da  janela  tornou-se  diferente  de  zero.  Se  considerássemos  um  caso  hipotético em  que  o  receptor  fosse  o  responsável  por  informar o  emissor  o  momento  em  que  a  sua janela  de  anúncio  se  tornasse  maior  que  zero,  veríamos  que  o  receptor  precisaria  de  um temporizador extra. Por quê?
        * R : O receptor teria a necessidade de alertar o transmissor o momento que o ele se encontrasse com um valor de janela maior que 0 ou outro tamanho da janela, assim para o transmissor ficar sabendo deste valor o receptor teria que notificalo com uma mensagem,  utilizar um temporizador de tempos em tempos ele realiza o anuncio do tamanho de janela se esta estiver maior que 0 para o transmissor, senão espera mais um tempo para outra tentativa.  

  4. O  tamanho  do  campo  “Sequence  Number”  no  cabeçalho  TCP  é  de  32  bits,  o  que corresponde  a  uma  cobertura  de  mais  de  4  bilhões  de  bytes  de  dados.  Mesmo  que  esse montante de dados não seja transferido em uma única conexão TCP, por que o número de sequência ainda pode passar de 2^32-1 para 0?
      * R: O número de sequência varia aleatoria e possui formato de anel, então se estiver sido aleatoriamente sorteado em 2^32-1 seu proximo número será 0.   

  5. Você  foi  contratado  para  projetar  um  protocolo  baseado  em  fluxo  de  bytes  e  que implemente  a  ideia  de  janelas  deslizantes,  tal  como  o  TCP.  O  protoloco  a  ser  projetado deverá executar em cima de uma rede de 1 Gbps. O RTT (round trip time) dessa rede é de 140  ms  e  o  tempo  de  vida de  um  segmento  é  de  60  segundos.  Quantos  bits  você  incluiria nos campos AdvertisedWindow e SequenceNum do cabeçalho do seu protocolo?
      * AdvertisedWindow: (0.140 * 10^9) / 8 -resultado em bits
         * 17,5MB = 2^25 numero de sequencia ideal
         * Janela = 2^25
      * Sequence Num: 
        * Etapa Conferir Tempo de vida
          * (60 * 10^9) / 8
          * 7.5 GB = 2^33 
          * NumberSeqPeloTTL=2^33
        * Etapa conferir o multiplo da janela
          * NumberSequencia = Janela 2^25 <= Numbersequência+1/2
          * NumberSeqPelaJanela = 2^26
        * MAX(NumberSeqPeloTTL,NumberSeqPelaJanela) 
          * O maior e o tamanho da sequência 

  6.  Se um nó A recebe dois pacotes com as respectivas flags SYN configuradas em 1 a partir de  uma  mesma  porta.  O  segundo  pacote  pode  ser  uma  retransmissão  do  primeiro  ou  uma nova requisição de conexão caso o nó remoto tenha sofrido uma falha e perdido a conexão anterior. 
    a. Como o nó A consegue distinguir entre os dois casos? 
      * R A) Para identificar se o pacote de sincronização é uma retransmissão basta obervar o número de sequência enviado pelo cliente, se for o mesmo do número de sequência X anteriormente encaminhado,  então é uma retransmissão senão tratasse de um nova conexão porque o número de sequencia será outro aleatoriamente selecionado diferente de X e pedidos de SYN acontecem somente no início.
          
           
    b. Descreva  um  algoritmo  sobre  o  que  o  TCP  deve  fazer ao  receber  um  pacote SYN de abertura de conexão. Considere os dois casos descritos acima e ainda a possibilidade de nenhum processo estar escutando na porta de destino. 
      * R Retransmissão)
            * Cliente encaminha pacote com sync 1 e seq x
            * Servidor recebe e encaminha [sync 1, seq y, ACKnum=x+1]
            * Cliente encaminha novamente uma mensagem [sync 1, seq x]
            * Servidor recebe e percebe que o seq x já foi utilizado anteriormente e entende que o cliente não recebeu a mensagem [sync 1, seq y, ACKnum=x+1] então retransmite a novamente ela
            *  Daqui pra frente e normal o solicitação de abertura
      * R Nova requisição
            * Cliente encaminha pacote com sync 1 e seq x
            * Servidor recebe e encaminha [sync 1, seq y, ACKnum=x+1].
            * Cliente encaminha pacote [sync 1, seq k].
            * Servidor recebe e percebe que o número de sequência não é o anteriormente armazenado e assim sabe que é uma nova conexão.
      * Algoritmo
            * if (connections tolportare not being accepted)
                * send RST
            * else if (there is no entry inTfor〈lport, raddr, rport〉) // new SYN
                * Put〈lport, raddr, rport〉into a table,
                * Set rISN to be the received packet’s ISN,
                * Set lISN to be our own ISN,
                * Send the reply ACK
                * Record the connection as being in state SYNRECD
            * else if (T[〈lport, raddr, rport〉] already exists)
                * if (ISN in incoming packet matches rISN from the table)
                  * // SYN is a duplicate; ignore it
                * else
                * send RST to〈raddr, rport〉

  7. O  algoritmo  de  Nagle  requer  que  o  emissor  mantenha um  segmento  de  dados  parcial  até que os dados atinjam o tamanho de um segmento (mesmo que haja dados sinalizados como prioritários) ou chegue um ACK pendente do receptor. 
     a. Suponha  que  as  letras abcdefghi  sejam  enviadas,  uma  por  segundo,  através de  uma  conexão TCP  cujo  RTT  seja  igual a  4,1  segundos.  Desenhe  uma  linha indicando quando cada pacote é enviado e o que ele contém. 
      * T=0.0  ‘a’ sent
      * T=1.0  ‘b’ collected in buffer
      * T=2.0  ‘c’ collected in buffer
      * T=3.0  ‘d’ collected in buffer
      * T=4.0  ‘e’ collected in buffer
      * T=4.1  ACK of ‘a’ arrives, “bcde” sent
      * T=5.0  ‘f’ collected in buffer
      * T=6.0  ‘g’ collected in buffer
      * T=7.0  ‘h’ collected in buffer
      * T=8.0  ‘i’ collected in buffer
      * T=8.2  ACK arrives; “fghi” sent
       
     b. Suponha que as mudanças de posições de um mouse sejam enviadas através da conexão. Assumindo que muitas mudanças são enviadas a cada RTT, como o usuário notaria o avanço do mouse com e sem o uso do algoritmo de Nagle?
      * Com o algoritmo de Nagle, o mouse parece pular de um lugar para outro. Sem o algoritmo Nagle, o cursor do mouse moveria suavemente, mas exibiria alguma inércia: ele continuaria se movendo para um RTT após o mouse físico ser parado.
  
  8. Explique por que TIME_WAIT é um problema maior se o servidor iniciar o fechamento da conexão.
    R: Se o servidor iniciar o fechamento e o cliente estiver enviando dados, estes serão perdidos.   

  9.  Por que os protocolos UDP e TCP utilizam os campos IP de destino/IP de origem em seus checksums? Qual é o problema dessa abordagem que mistura dados da Camada de Transporte com dados da Camada de Rede? 
      R: Um problema em fazer isso é porque quebra o principio das camadas onde cada camada tem que ser responsavel apenas por realizar operações em suas camadas, se algum dia o modo de como a camada for modificada porem suas interfaces continuarem as mesmas o protocolo irá quebrar porque não sabera gerenciar o novo cabellho por este propossito as camadas trabalham com interfaces de comunicação entre a camada superior e a inferior.  
      
  
  10. Por que os protocolos da Camada de Transporte recebem o nome de Protocolos Fim-a-Fim?
    * R: Porque ele entrega um pacote de processo do hospedeiro A para processo do hospedeiro B e possui confiabilidade com checksum da camada de transporte, diferente da camada de enlace que garante confiabilidade entre enlaces, porém não dentro de filas de roteadores digamos, ou da camada de rede com confiabilidade entre hospedeiros mais não entre processos. 


  11. Relacione as Colunas

      1.  Controle de Fluxo
      2.  Controle de Congestionamento
      3.  Ambos os mecanismos
      4.  Nenhum dos anteriores
      
      (1) Controla a quantidade de dados que o transmissor pode enviar ao receptor sem confirmação.
      (3) Limita a velocidade de transmissão em função da capacidade de processamento do receptor.
      (2) Limita a velocidade de transmissão para evitar congestionamento da rede.
      (2) Reduz a quantidade de dados que pode ser transmitida sem confirmação quando um pacote não chega ao seu destino
      (4) Rejeita o pedido de uma nova conexão TCP caso não haja mais banda disponível
      (2) Mantém a taxa de transmissão constante ao longo de toda a conexão TCP.

  12. Supondo uma comunicação TCP iniciada e terminada pelo cliente. Numere a ordem dos pacotes e deixe em branco os pacotes que não corresponderem a uma comunicação TCP.
      (3/4) Cliente e Servidor trocam pacotes de dados com ACK=1, SYN=0 , FIN=0
      (5) O servidor envia um pacote com ACK=1, SYN=0, FIN=1
      (2) O servidor envia um pacote com ACK=1, SYN=1 , FIN=0
      (3) O cliente envia um pacote com ACK=1, SYN=0, FIN=0
      (4 ) O cliente envia um pacote com ACK=1, SYN=0, FIN=1
      ( ) O servidor envia um pacote com ACK=1, SYN=1, FIN=1
      ( ) O cliente envia um pacote com ACK=0, SYN=0, FIN=0
      ( ) O servidor envia um pacote com ACK=0, SYN=1, FIN=1
      (1) O cliente envia um pacote com ACK=0, SYN=1, FIN=0
      ( ) O servidor envia um pacote com ACK=0, SYN=1, FIN=0

  13) Considerando os seguintes dados, determine quantos bytes no máximo podem ser enviados
  do servidor para o cliente, sem confirmação:
  – último número de confirmação recebido pelo servidor: 9000
  – janela de recepção anunciada do cliente: 10000 bytes
  – último número de seqüência enviado pelo servidor: 12000
  – janela do emissor é de 7000 bytes    