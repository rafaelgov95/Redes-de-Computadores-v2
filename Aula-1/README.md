## Aula 1

## Complexidade da Rede

* Protocolo
* Aplicação
* Multi tarefas
* Multi clientes
* Multi interfaces
* Varios caminhos
  
## Oque é Internet ?

#### Geral   
*   Estrutura + Serviços Oferecidos = Internet

####  Visão da Estrutura: Fisica
*   Host Finais
    *   PCS, Aplicações de Rede, Servidores.
*   Enlaces
    * Fibra, Cobre, Radio, Micro Ondas.
* Roteadores (Comutadores de Rede)   
* ISP (Internet Service Proveders)

#####  Visão da Estrutura: Redes de Redes
* Sistema autônomo (AS) 
* AS é controlada por um ISP
* ISP são provedores de acesso para as AS
* Uma AS e controlada por sua ISP
  * Tipos de ISP: residêncial, corporativo e academico
  * ISP variam de tamanho/abrangência:mundial:regional:global
* Provedores de acesso e AS se conecta para trocas de dados entre ISPs e ASs com roteamento EGP.
  * NAP - são utilizados para troca
  * IXP - também são utilizados para trocas
* ISP podem ser privados
* ISP são colocados em quase que hierarquias
  * No centro um pequeno numero de grande redes bem conectadas.
* Atualmente existem em torno de 70 mil ISP
* ISPs menores pagam pela conexão com maiores.
* ISPs de tamanhos iguais fazem acordo para mover dados de um para outro.
  
####  Visão do Serviços
* Uso de aplicações destribuida.
  * WWW, Email, VOIP, E-Commerce
* Prove interface de programação para aplicação

##### Visão do Serviços: Dois tipos de Serviço UDP e TCP

###### UDP - Sem orientação a Conexão
* Sistemas finais não estabelecem coneção
* Sistemas finais não guardam informação sobre conexão
* Mas Sistemas finais  mantém algu estado
  * Estado (sem memória)
* Transmissão não confiável
    
###### TCP - Orientada orientação a Conexão
* Somente os sistemas finais conhecem a conexão
* Rede não conhece a conexão
  
#### Protocolos
* msgs são especificas são enviadas.
* trocadas entre hosts finais
* ações espefica são realizadas quando as mesagens são recebidas, ou acontece outro eventos.

  ##### Definem o formato e a ordem das trocas de mesgens entre entidades, bem como as ações tomadas quando da trasmissão e da recepção destas mensges.
  
## Estrutura da Rede
* Aplicações e hosts.
  * P2P, Clientes e Servidores.
* Canais de acesso, meio físico
  * Encales de comunicação: Cabeados e Sem fio.
* Núcleo da rede:
  * Roteadores interconectados
  * rede de redes - ASs 
 

#### Estrutura da Rede: Borda da Rede
* Sistemas finais Hosts
  * rodam programas de aplicação
    * Ex: WWW, email, tudo na "extremidade da rede".
    
* Modelo cliente/servidor
  * o host cliente faz pedidos que são atendidos pelos servidores.
    * ex: cliente/servidor de WWWW
    * ex: cliente/servidor de Email
* Modelo peer-to-peer
 * Iteração simétrica entre os hosts
   * ex:teleconferência,NAPSTER,KaZaA,BitTorrent,Emule

#### Estrutura da Rede: Redes de Acesso
* Como conectar os sistemas finais aos roteadores de borda?
  * rede de acesso residencial
  * redes de acesso corporativa(escola,empresa)
  * redes de acesso sem fio
* Questões a serem consideradas:
  * largura de banda (bits por segundo) da rede de acesso
  * compartilhada ou dedicada:

    #### Rede domestica
    * O modem(dedicado ADSL ou compartilado HFC) este sendo o caminho para ponto final ou central telefoneica recebe e é enviado para o roteador e firewall onde é realizado o NAT entre outros procedimentos depois e distribuido por um enlace wifi como um AP.

    #### Rede Coorporativa
    * Utilizado em empresas, universidade etc.
    * Hoje tipicamente equipamentos se conectam em sitches ethernets
  
    * O enlace principal chega do ISP, chega no roteador institucional.
    * Atraves de switches e ap, os sistemas finais acessam a rede para se conectarem ao roteador principal.
    * Entre os sistemas finais no espoco institucional temos, servidores Web, correio eletronico ou DNS entre outros.

    #### Redes de acesso sem fio
    * Redes de acesso compartilhado sem fio conecta o sistema final ao roteador.
      * Utilizando uma estaçao base = AP
    * Lans Sem fio.
      * 200 metros fechada
      * 802.11 b/g/n/ac WIFI
      
    * Acesso de longa Distância
      * Celulares
        * 3G,4G:LTE
      * Satelites
      * WifiMax
    
#### Estrutura da Rede: Núcleo da Rede
    
* Uma manha de roateadores interconectados

  ### Como os dados são transferidos pela rede?
    #### Comutação de Circuito
    * Circuito dedicado
      * Sem compartilhamento de conexão
      * Redes Telefonicas
    * Apenas um Circuito alocado para cada conexão
      * Recursos fim a fim são reservados como a banda do enlace e a capacidade do comutador.
    * Seu desempenho e garantido (como em um circuito físico)
    * necessita estabelecer conexão previamente, alem de ter que realizar mantenção do estado
      * mecanismo complexo
    * Sua banda e dividia e fatia assim como os outro recursos.
      * E alocadas em chamadas de circuito
    * Uma fatia ficara ociosa se o dono não utilizala, sem compartilhamento
    * Suporta poucos usuarios.
    * Adivisão das fatias são realizadas por MULTIPLIXAÇÂO
      * Divisão de Frequência = FDM (Frequency-Division Multiplexing)
        * Divide em canais
      * Divisão de Tempo = TDM (Time-Division Multiplexing)
        * Divide em blocos de tempo
    * 

    #### Comutação de Pacotes
    * Armazena e encaminha a mensagem.
      * Os dados quebrados e adicionados em envelopes chamdos de pacotes, estes são encaminhados. 
        * Ex: Internet.
    * Cada fluxo de dado fim a fim e divido em pacotes.
      * Pacotes dos usuários compartilham recusos da rede
        * Processamento, largura de banda etc
      * A rede não conhece a conexão nem mesmo toma parte dela
      * recusos são utilizados sobre demanda.
    * Disputa por recusos
      * a demanda total dos recusos pode superar a quantidade disponivel
      * congestionamento de pacotes pelo infileiramento, esperando para usar o enlace.
      * armazena e retrasmite pacotes se deslocam uma etapa (hop) por vez
        * trasmite num enlace
        * espera a vez no próximo enlace
    * Simples porém eficiente

    #### Comutação de Pacotes: Miltiplexação estatística
    * Divisão de tempo dor demanda
      * cada pacote usa toda a banda do canal
    * estabelece enlace com base em cada pacote
    * pacotes de diferentes origns intercalados no enlace
    * coloca em buffer os pacotes que estão disputando o enlace
      * O tamannho do pacote é limitado para evitar monopólio.
    * O estouro do buffer(fila) é chamada de congestionemnto
    
    #### Comutação de Pacotes: Armazena e repassa
    * Tambem conhecida como "store ond forward", e a tecnica da comutação de pacotes que armazena e repassa o pacote.
    
    * Quebra uma mensagem em pedaçoes menores
    
    * Store-and-forward nesta tecnica o comutador espera a chegada do pacote completo e o encaminha/roteia para o próximo comutador
  
    #### Segmentação de Mensagens e Desempenho
    * Sem segmentação:
      * cada mensagem precisa ser armazenada completamente em cada comutador antes de ser retrasmitida
      * longa espera em cada comutador
      * Uso sequencial dos componentes da rede
        * desperdício de recursos
        * Ex: 5s para trasmitir entao se tivermos 3 hops teremos 3x o atraso.
    * Com segmentação:
      * Cada componente da rede pode "trabalhar" em paralelo em pacotes diferentes da mensgens
      * Resulta em um menor tempo de atraso total de transmissão da mensagem

    #### Comutação de pacotes x Comutação de circuitos
    * Comutação de pacotes permite que mais usúarios usem a rede!
      * Enlace de 1 Mbit/s
      * cada usuário:
        * 100Kbls quando "ativo"
        * ativo 10% do tempo

  
    * Comutação por circuito
      * 10 usuários
  
    * Comutação por pacotes
      * com 35 usuários, probabilidade de num ativo >10 é menor que 0,004.

    * A Comutação de pacotes é sempre mais vantajosa?
      * Otima para dados em surtos/rajadas
      * compartilhamento dos recursos
      * não necessita estabelecimento de conexão
      * Congestionemento excessivo
        * atraso e perda de pacotes
        * neessita de protocolos para transferência confiavel de dados, controle de congestionemnto
      * Como fornecer um comportamento do tipo Circuito?
        * São necessárias garantias de banda para aplicações de áudio e vídeo.
        *  ainda é umm problema não resolvido!
    #### Comutação de pacotes x comutação de circuitos
    * Roteamento
      * determina a rota origem-destino tomada pelos pacotes
      * algoritmos de roteamento
        * IGP
          * RIP, SIS
        * EGP
          * BGP
      * Com os algoritmos temos as tabelas de Repasse dos roteadores
        * A funçao de repasse move pacotes da entrada do roteador para a saída apropriada do roteado.
          * Endereço do destino no cabeçalho do pacote entrante.

#### Métricas de Desempenho
* Latência ou atraso
  * Tempo dos pacotes
* Produto retardo x largura de banda
  * Largura dos canais
* Atraso de enfileiramento
  * Quando chega nos roteadores congestionado
* Perda de pacotes
  * pode ser ate por congestionamento ou por erro na comunicação
* Vazão (Throughput)
  * Quantidade de dados que consegue fluir em uma rede espefica sua metríca maxima de bits (produto final sia vazão)

### Porque aprender as Métricas
   * Conhecer as características da rede:
     * Estimar parâmetros para protocolos 
     * Melhorar a QoS das aplicaçẽs multimídia;
     * Criar modelo mais precisos
     * Provisionamento de canais.

    

  #### Medidas de desempenho

  * O desempenho de uma rede pode ser medida de duas formas principais.
    * Latência (ou atraso, em unidade de tempo)
      * tempo para enviar mensagem do ponto A ao ponto B
      * somente ida ou ida e volta (RTT- round-trip time)
    * Vazão(Throughput) - em bits por segundo
      * Vazão é a taxa de bits efetivamente transportada
      * Largura de banda é a taxa máxima de bits que um meio físico pode transmitir em uma unidade de tempo (taxa de transmissão) 
        * Largura de banda ou banda de um canal pode ser dada em Hz ou bits/segundos

  #### Quanto vale um Mega?
  * Mega = 2 20 ou 10 6 ?
     | Unidades    | Base Bits Armazenamento | Base Bits Taxa de Transferência |
    |--- |  ---  | --- |
    | KB |   2^10 | 10^6
    | MEGA | 2^20  | 10^7  |
    |GIGA |  2^30 | 10^8  

  #### Atraso em redes comutadas por pacotes
  * pacotes sofrem atrasos no caminho fim a fim
  * quatro fontes atraso em cada etapa (roteador)
    * D(no)=processamento+enfileiramento+transmissão+propagação
      ##### 1 Processamento
        * Verificação de bits com erro
        * identif. do enlace de saída
      ##### 2 Enfileiramento
        * tempo de espera no enlace de saída até a transmissão depende do nível de congestionemnto do roteador
      ##### 3 Atraso de transmissão
        * tempo para colocar os bits no enlace
        * depende da taxa de transmissão do enlace e do tamanho do pacote
          * R = taxa transm(largura de banda do enlace)(bps)
          * L = tamanho do pacote (bits) 
          * trasmissão = R/L
      ##### 4 Atraso de Propagação
        * Tempo de colocar os bits no meio (Comprimento do enlace)
        * RTT = 2*propagação (generalizando)
        * 
          * D = compr. do enlace 
          * S = velocidade de propagação no meio       
          * Propagação = D/S
  
      #### Exemplos 
        * Por exemplo, transferência de um arquivo de 1MB em um enlace de fibra óptica de 10Mbps e a uma distância de 5000 m. Velocidade de propagação em fibra 2x10 8 m/s
          * Ignorando fila de espera e atraso de processamento no nó.
          * Atraso de transmissão: (2 10 x2 10 x8)/10x10 6 = 0.839s
          * Atraso de propagação: 5000/2x10 8 = 0.025ms
          * Latência (ou atraso) = 0.839s.
      
        * Mudando agora de 10 Mbps para 10 Gbps:
          * Atraso de transmissão: (1x2 20 x8)/10x10 9 = 0.839ms
          * Latência = 0.864ms
  
    #### Produto: Retardo X Largura de banda
    * Produto: Delay x Bandwidth
    * Quantidade de dados "em vôo" ou "na tubulação"
      * Volume de dados em "transito" no canal
    * Normamente realtivo ao RTT
    * Exemplo: 100ms x 45Mbps = ~549kb
      * (((45*10^6) * (100/10^3))/8)/2^10 = 549 KB
      * (((549 * 2^10))/((100/10^3))*8)/10^6 = 45Mbps
      * ((549 * 2^10 * 8)/(45 * 10^6))*10^3 = 99.942000 ms


    #### Atraso de enfileiramento
    * Fila: tempo que pacote espera até iniciar sua transmissão
    * Depende da intensidade de tráfego: La/R
      * R=largura de banda do enlace (bps)
      * L= tamanho médio dos pacotes (bits)
      * a=taxa média de chegada de pacotes Atraso de enfileiramento
        * La/R ~ 0: pequeno atraso de enfileiramento
        * La/R ~ 1: alto atraso médio
        * La/R > 1 : chega mais “trabalho” do que a
        
        *capacidade de atendimento, atraso médio infinito!!(assumindo capacidade de fila infinita!)
        
    #### Perda de pacotes
    * Na realidade: filas dos roteadores têm tamanho limitado
    * O que acontece quando um pacote chega a um roteador cuja fila está cheia?
      * O pacote é descartado (i.e., perdido)!
    * Taxa de perda de pacotes aumenta à medida que a intensidade do tráfego (La/R) aumenta
      * taxa de chegada de pacotes ao enlace excede a capacidade do enlace de saída.
      * pacotes perdidos podem ser retransmitidos (ou não)
    
    #### Jitter de Pacotes
    * Variação do atraso entre pacotes
    * É uma medida da suavidade do processo de chegada de pacotes e pode ser expresso como a variabilidade do intervalo de tempo entre chegada de pacotes.
    * O jitter pode ocorrer devido à variação no tempo dos atrasos das filas nos roteadores ao longo do caminho.
    * Chegada de pacotes com baixo jitter são mais previsíveis e leva a um desempenho na camada de aplicação mais confiável.

    #### Vazão (Throughput)
    * vazão: taxa (bits/unidade de tempo) na qual os bits são transferidos entre o transmissor e o receptor
      * instantânea: taxa num certo instante de tempo
      * média: taxa num período de tempo mais longo
    * vazão fim a fim
      * Taxa do enlace de gargalo: min {R c , R s }
    * Vazão efetiva fim a fim:
      * Throughput = TransferSize/TransferTime
      * TranferTime = RTT + TransferSize/Bandwidth
    * Considerando que o tempo de transferência engloba a latência em um sentido e também o tempo adicional para requisitar ou estabelecer a transferência

    #### Atrasos e Rotas na Internet
    * Como se mostram os atrasos e perdas na Internet?
    * Programa traceroute: realiza medidas de atraso da origem para cada roteador ao longo do caminho até o destino na Internet. Para todo i:
      * envia três pacotes que chegarão ao roteador j no caminho em direção ao destino (i.e., três experimentos distintos)
      * roteador j retornará pacotes de resposta à origem
      * origem mede o intervalo de tempo entre a transmissão dos pacotes e a recepção das respostas

    #### Outras Métricas
    * "Atraso de ida“ (One-way delay - OWD)
    * Goodput : taxa na qual a aplicação recebe dados com sucesso
    * Capacidade de Transmissão dos Enlaces (fim a fim)
    * Capacidade de Transmissão do Gargalo
    * Tamanho do Buffer no Gargalo
    * Caminho (Path)
    * Nota: Estimar algumas dessas métricas é elativamente simples, no entanto, outras requerem algoritmos mais sofisticados.
     
    #### Técnicas de Medição
    * Duas técnicas existentes:
      * Ativa:
        * Adicionam tráfego na rede para obter as medições desejadas
        * Envio de Sondas entre os "pontos" usados na medição;
      * Passiva:
        * Coleta informações do tráfego passante por um ponto;
        * Captura de dados gerados por outros usuários e aplicações e não pelo processo de medição

#### Modelo de Camadas
  * Modelo de referência em camadas
     * Abstrações para ocultar a complexidade
     * Definição de interfaces e serviços
     * Padronização
   * Objetivos do Modelo OSI ( Open System Interconnection )
     * Definir um esquema conceitual que permita o trabalho ser desenvolvido de forma produtiva e independente para cada uma das camadas;
     * DIZER O QUE FAZER E NÃO COMO FAZER;
       * Explicitar o que cada camada deve fazer;
     * Modelo de Camadas do ISO/OSI
       * Aplicação
       * Apresentação
       * Sessão
       * Transporte
       * Rede
       * Enlace
       * Fisica
    
      * Responsável pela transmissão e representação dos bits através de um canal de comunicação

       #### Camada Fisica
        * Responsável pela transmissão e representação dos bits através de um canal de comunicação
          * nível elétrico, mecânicas, duração do sinal, codificação
          * Definir a forma e o nível dos pulsos óticos em uma rede com fibra ótica
          * Definir a mecânica dos conectores e função de cada circuito do conector
          * Nível físico não deve se preocupar com os possíveis erros de transmissão;
        * Unidade de transmissão: bits
        * Ex. de padrões do nível físico: EIA-232-F (antigo RS-232), ITU X.21, V.90, PHY
        * Dispositivo de rede: Repetidor, Hub
       
      #### Camada Enlace
        * Transferência de dados entre elementos de rede vizinhos
          * Transformar o meio de comunicação bruto numa linha livre de erros de transmissão;
          * Detectar e opcionalmente corrigir erros de transmissão no nível físico;
          * Empacotamento de dados em quadros (frames) dentro da rede;
          * Controlar o acesso ao meio em redes locais;
        * Unidade de transmissão: quadros
        * Ex de padrões que atuam no nível de enlace: IEEE 802.3, SLIP/PPP, HDLC, MAC;
        * Dispositivo de rede: Switch, ponte, placa de rede;
      #### Camada Rede
        * Fornecer ao nível de transporte uma independência quanto ao encaminhamento de pacotes
        * Roteamento através de redes diferentes
          * Define método de endereçamento global;
          * Algoritmos de roteamento
        * Categoria de Serviços:
          * Datagrama (não orientado a conexão)
          * Circuito Virtual (orientado a conexão)
        * Unidade de transmissão: Datagramas ou pacotes(mesma coisa)
        * Ex: X.25, IP, IPX;
        * Dispositivo de rede: Roteador
  
      #### Camada Transporte
      * Comunicação fim a fim: entre processos
      * A camada de transporte pode, ou não, oferecer confiabilidade na transmissão dos pacotes;
      * Oferece serviços:
        * Orientado a conexão
          * Controle de fluxo fim a fim;
          * Controle de sequência fim a fim
          * Detecção e recuperação de erros fim a fim;
          * Ex: TCP
        * Não orientado a conexão.
          * Ex: UDP
      #### Camada Sessão
      * Comunicação com controle de estado.
      * Permite que aplicações em diferentes máquinas estabeleçam uma sessão de comunicação entre si
      * Autenticação
      * Sincronização do diálogo:
         * Exemplo: transferência de arquivos, após interrupção, reatar a comunicação a partir de onde arou;
      * Gerenciamento de atividades
        * Transmissão baseada em prioridade
      #### Camada Apresentação
      * Permite interpretar o significado dos dados
        * Representação de dados independente da plataforma: sintaxe e semântica;
        * Transformação dos dados, formatação dos dados, conversão de códigos de caracteres (EBCDIC, ASCII, etc.);
        * codificação de inteiro, ponto flutuante, etc.
        * Compressão de textos, criptografia,
      #### Camada Aplicaçao
      * Suporte a aplicações de rede
        * Mensagens padronizadas
        * Define uma variedade de protocolos necessários à comunicação propriamente dita;
        * Ex: HTTP, SMTP, Telnet, FTP, DNS. 
      * Unidade de transmissão: mensagem
      * Dispositivo de rede: proxy
       
  #### Arquitetura IEEE 802

    Objtivo: padrões para redes locais de computadores.
    * O IEEE 802 definiu uma arquitetura com três camadas
      * IEEE 802, esta entre a camada de rede e camada fisica.
        * Rede
          * Protocolos (802.1)
        * Enlace(LLC)
          * Protocolos (802.2)
        * Enlace(MAC) 
          * Protocolos (802.3,802.5,802.6)
        * Fisica(PHY)
          * Protocolos (802.3,802.5,802.6)
      
    * O IEEE 802 define padrões para os níveis físico e enlace do RM-OSI;
    * RM-OSI da ISO
      * Aplicação
      * apresentação
      * sessão
      * transporte
      * rede
      * enlace de dados
      * fisica

  #### Arquitetura TCP/IP Arquitetura dos Protocolos

    * Aplicação
      * HTTP,SMTP,SSH,FTP,TELNET
    * Transporte
      * TCP,UDP
    * Rede
      * IP e auxiliares(ARP e ICMP)
    * Enlace de dados
      * Definida na 802.
    * Fisica
      * Definida na 802.
 
  #### Encapsulamento

    * Computador 1
      * Aplicação
      * Transporte
      * Rede
      * Enlace de dados
      * Fisica
  
    * Roteador 1
      * Rede
      * Enlace
      * Física

    * Roteador 2
      * Rede
      * Enlace
      * Física

    * Computador 2
      * Aplicação
      * Transporte
      * Rede
      * Enlace de dados
      * Fisica

  #### Comparação OSI x TCP/IP
    * Aplicação TCP/IP e OSI
      * Apresentação OSI
      * Sessão OSI
    * Transporte TCP/IP e OSI
    * Rede TCP/IP e OSI
    * Fisica TCP/IP
      * Enlace de dados OSI
      * Fisica OSI