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