# Lista de Exercícios – Conceitos Básicos

#### Alguns Conceitos Básicos

* Lista de Unidades e taxas de dados: usa-se "B" para significar octeto de bits e "b" para sigficar bit. Base 2 para armazenamento e Base 10 para transmissão
 
     | Unidades    | Base Bits Armazenamento | Base Bits Taxa de Transferência |
    |--- |  ---  | --- |
    | KB |   2^10 | 10^6
    | MEGA | 2^20  | 10^7  |
    |GIGA |  2^30 | 10^8

## Exercícios
1. Calcule o tempo total requerido para transferir um arquivo de 1,5 MB nos seguintes casos, assumindo um RTT de 80 ms, pacote de dados de tamanho 1KB, e um handshakin (estabelecimento da conexão) inicial de 2 x RTT, antes do envio dos dados.

     - Quantidade de Pacotes Transmitidos = (1.5 * 2^20 )/ (1 * 2^10) = 1536 pacotes
  
  
* A) Largura de banda é 10 Mbps, e os pacotes de dados são enviados continuamente.
  * tempo total = handshake + tempo trasmissão + tempo do último bit (1/4 do RTT aparentemente)
  
  *  = (2 * RTT) + ( (1.5 * 8 * 2^20) / (10^7 ) ) + (0.5 * RTT)
  *  = (2.5 * RTT) + ( (1.5 * 8 * 2^20) / (10^7 ) )
  *  = (2.5 * RTT) + ( (9.5 * 2^20) / (10^7 ) )
  *  = (2.5 * RTT) + ( (12 * 2^20) / 10000000 )
  *  = (2.5 * (80/10^3)) +((12*2^20)/10^7)
  *  = 1.458,291 Segundos

* B) A largura de banda é 10 Mbps, mas após o envio de cada pacote deve-se esperar um RTT antes do envio do próximo pacote.
    * = a =  1.458,291 Segundos
    * = a + (1536 1) * RTT
    * = a + (1536  * (80/10^3)) - (1 *  (80/10^3))
    * = 124.258,291 segundos
  

* C) O enlace permite transmissão infinitamente rápida, mas limita a largura de banda de tal forma que apenas 20 pacotes podem ser enviados por RTT.
    * tempo total = handshake +(n-1) * RTT + RTT
    * = teto(2+(1536/20)-1 + 0.5) * (80/10^3)
    * = SEM TETO 6.264,000 segundos
    * = TETO 6.280,000 segundos

2. Considere um enlace ponto a ponto de 50 km de comprimento. A que largura de banda seria o atraso de propagação (a uma velocidade de 2 x 10 8 m/s) igual ao atraso de transmissão para pacotes de 100 bytes? E para pacotes de 512 bytes?
    * RTT = ((50 * 10^3 ) / 2*10^8) 


3. Suponha um enlace ponto a ponto de 128 Kbps é estabelecido entre a Terra e Marte. A distância entre a Terra e Marte é de aproximadamente 55 Gm (quando estão mais próximos), e os dados viajam pelo enlace à velocidade da luz – 3 x 10 8 m/s.
   
* A ) Calcule o RTT mínimo para o enlace =  
    * RTT = Distancia/Velocidade
    * RTT = 2 * ((55  * 10^9 )/( 3 * 10^8))
    * = 366.666,6666 segundos


* B) Calcule o produto delay x bandwidth para o enlace
    * 
    *


* C) Se uma câmera tira fotos de tamanho 5MB em Marte e as envia à Terra, quanto tempo demora para a foto chegar a Terra após ser tirada?
    * = (5 * 8 * 2^20 /128 * 10^3 ) + 0.5 RTT
    * = ( 5 * 8 * 2^20 / 128 * 10^3 ) + ((1100/3) *0.5 )
    * = (5 * 8 * 2^20) /(128 * 10^3) + ((1100/3)*0.5)
    * = 511.013,3333 segundos
  
4. Para cada uma das seguintes operações em um servidor de arquivos remoto, discuta se elas são mais sensíveis a atraso ou a largura de banda.

* A) Abrir arquivo
    * = Como o comando abrir arquivo e executado pelo sistema operacional basta o comando conseguir chegar ao host para ser executado por este motivo ele a sensivel a "atraso" afinal ninguem gosta de ficar esperando um comando ser executado em um terminal.
   
* B) Ler conteúdo do arquivo
    * = Ao carregar o conteúdo do arquivo por uma conexão a largura de banda  é sensivel uma vez que diversas informações( o conteúdo do arquivo) utilizam  estaram passando pela a conexão.

* C) Listar conteúdo do diretório
    * = Como no A este comando será realizado pelo sistema operacional, apesar de utilizar uma largura de banda para inviar dos dados ele e sensivel a "atraso".

* D) Mostrar os atributos do arquivo
  * = Assim como no A e C, este comando utiliza um possivel pipe para receber informações, mais o atraso destes dados será sentido por este motivo ela é sensivel a "atraso".


5. Calcule a latência (do primeiro bit enviado até p último bit recebido) para:

* A) Um enlace Ethernet de 1 Gbps com um único switch store-and-forward no caminho, e pacote de tamanho 5.000 bits. Suponha que cada enlace introduz um atraso de propagação de 10 ms e que o switch começa a retransmissão imediatamente após ele ter acabado de receber o pacote (i.e., não há atraso de espera na fila nem de processamento).

* B) O mesmo que (a) mas com 3 switches.

* C) Mesmo que (b), mas suponha que o switch é implementado com cut-through, ou seja, ele é capaz de começar a retransmitir o pacote após ter recebido os primeiros 128 bits do pacote.


6. Discuta as necessidades de desempenho relativas das seguintes aplicações, em termos de largura de banda média, largura de banda máxima (pico), latência, jitter e tolerância a perdas:
* A) Servidor de arquivos
    * Largura de Banda Média = 
    * Largura de Banda Máxima =
    * Latência =
    * Jitter = 
    * Tolerância a perdas = 
* B) Servidor de impressão
    * Largura de Banda Média = 
    * Largura de Banda Máxima =
    * Latência =
    * Jitter = 
    * Tolerância a perdas = 
* C) Biblioteca digital
    * Largura de Banda Média = 
    * Largura de Banda Máxima =
    * Latência =
    * Jitter = 
    * Tolerância a perdas = 
* D) Monitoramento de instrumentos meteorológicos remotos.
    * Largura de Banda Média = 
    * Largura de Banda Máxima =
    * Latência =
    * Jitter = 
    * Tolerância a perdas = 
* E) Voz
    * Largura de Banda Média = 
    * Largura de Banda Máxima =
    * Latência =
    * Jitter = 
    * Tolerância a perdas = 
* F) Difusão de televisão
    * Largura de Banda Média = 
    * Largura de Banda Máxima =
    * Latência =
    * Jitter = 
    * Tolerância a perdas = 


7. Relacione as colunas:

    |Opçoes | Alternativa    | Camada |
    |--- |  ---  | --- |
    |1 |  Define como representar bits 0 e 1 em formato elétrico ou ótico. | 1 Camada Física | 
    | 3 | Permite a comunicação de computadores situados em redes locais diferentes. | 2 Camada de Enlace |
    |2|Permite que computadores se comuniquem no interior de uma mesma rede local. | 3 Camada de Rede |
    |9|Permite que várias aplicações diferentes, num mesmo computador, se comuniquem através de uma única interface de rede.| 4 UDP|
    |8|Protocolo implementado na placa de rede.| 5 TCP|
    |7|Protocolo implementado no sistema operacional.| 6 Aplicação|
    |6|Protocolo implementado pela aplicação.| 7 Alternativas 4 e 5|
    |4|Permite enviar mensagens para aplicações especificas, com no máximo 64 Kbytes e sem garantia de entrega.|8 Alternativas 1 e 2.|
    |5|Permite enviar mensagens com mais de 64Kbytes, para aplicações específicas e com garantia de entrega.| 9 Nenhuma das|