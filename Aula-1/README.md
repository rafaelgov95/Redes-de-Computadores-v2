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
    