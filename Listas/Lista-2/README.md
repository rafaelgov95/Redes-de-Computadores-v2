# Lista de Exercícios – Conceitos Básicos


## Exercícios

1. Uma   estação   realiza,   pelo   endereço   www.ifrn.edu.br,   uma   consulta recursiva ao seu servidor de DNS local. Considere que o servidor não possua em cache o registro solicitado. Qual das alternativas abaixo melhor descreve a sequência de procedimentos para atender à requisição da estação?  
  
   * Resposta A)

2. Escreva os arquivos de zona para a seguinte árvore de DNS:
   * A) ZONA br
       * [br.,dns.br,SOA]
       * [br.,dns.br,NS]
       * [pucpr.br,dns.br,NS]
       * [dns.br,200.0.0.1, A]

   * B) ZONA pucpr.br
       * [pucpr.br,dns.pucpr.br,SOA]
       * [pucpr.br,dns.pucpr.br,NS]
       * [dns.pucpr.br,210.0.0.1,A]
       * [www,210.0.0.2,A]
       * [www.ppgia,210.0.0.3,A]
        
3. Escreva os arquivos de zona para a seguinte árvore de DNS:
   * A) ZONA br
       * [br.,dns.br,SOA]
       * [br.,dns.br,NS]
       * [pucpr.br.,dns.pucpr.br,NS]
       * [dns.br,200.0.0.1, A]

   * B) ZONA pucpr.br
       * [pucpr.br.,dns.pucpr.br,SOA]
       * [pucpr.br.,dns.pucpr.br,NS]
       * [ppgia.pucpr.br,dns.ppgia.pucpr.br,NS]
       * [dns.pucpr.br,210.0.0.1,A]
       * [www,210.0.0.2,A]
      
   * C) ZONA ppgia.pucpr.br
       * [ppgia.pucpr.br,dns.ppgia.pucpr.br,SOA]       
       * [ppgia.pucpr.br,dns.ppgia.pucpr.br,NS]
       * [dns.pucpr.br,210.0.0.4,A]
       * [www, 210.0.0.3,A]
    
4. Indique se V (verdadeiro) ou F (fals
    a) (V) O Serviço de DNS associa um nome hierárquico com um número IP
    b) (F) A administração do DNS é feita por um único organismo denominado NIC
    (Network Information Center)
    c) (F) O serviço de DNS usa o protocolo TCP para converter um nome em um
    número IP
    d) (F) Toda máquina na Internet precisa ter um nome hierárquico
    e) (V) Toda máquina na Internet precisa ter um endereço IP
    f) (F) Toda máquina na Internet precisa ter um endereço IP e um nome hierárquico
    g) (F) Os Estados Unidos não tem terminação nos nomes hierárquicos, por exemplo US porque eles les são melhores do que todo mundo
    h) (V) Os domínios do tipo nome-do-domínio.br são de instituições educacionais ou de pesquisa
    i) (V) O Nslookup é um programa que converte nomes hierárquicos em números IPs utilizando o serviço de DNS
    j) (F) Uma estação realiza uma consulta recursiva ao seu servidor de DNS local, pelo endereço www.facom.ufms.br. Considerando que o servidor não possua em cache o registro solicitado, o servidor de DNS local verifica sua lista de servidores de DNS raiz e seleciona selecion a um deles para encaminhar a consulta. O servidor de DNS raiz devolve o endereço IP do host www.facom.ufms.br. O servidor de DNS local encaminha o resultado da consulta para a estação requisitante

5. O nome da minha empresa é XYZ Informática, situada na Avenida Aven Paulista em São Paulo. Pergunta-se: Pergunta ( As perguntas abaixo podem ter er mais de uma resposta correta, uma única resposta correta ou nenhuma resposta correta)
    1) Qual será o possível nome do meu domínio:
       a) WWW.XYZ.COM.BR
       b) VERDADEIRA: XYZ.COM.BR
       c) XYZ.BR
       d) XYZ.INF.BR
    2) Caso o nome que você queira já esteja sendo utilizado por outra empresa do Rio
    Grande do Sul, o que você faz?
        a)VERDADEIRA: Processa a empresa afinal este é o nome da sua empresa registrado na Junta Comercial
        b) Tenta uma solução amigável com a outra empresa, alternando os dias de utilização do domínio
        c) Isto nunca aconteceria porque o NIC é um órgão central e verifica todos os nomes nas Juntas Comerciais
        d) Cadastro o meu domínio normalmente, pois as empresas estão em estados diferentes

    1) Após criar o domínio, você sente a necessidade de criar sub-domínios. O que você faz?
        a) Para cada novo sub-domínio eu tenho que pedir autorização ao meu provedor de acesso
        b) VERDADE: Eu crio os sub-domínios que eu quiser, afinal de contas quem é que manda neste domínio
        c) Preciso pedir autorização do NIC, afinal de contas ele é o órgão que administra todo o DNS mundial
        d) Eu procuro uma solução mais fácil do que a criação de sub-domínios porque os endereços IP estão acabando

    2. A empresa Cute Models (domínio CUTE.COM) te contratou para ligar a rede deles à Internet, configurando o serviço de DNS para todas as máquinas. Mas como você é o Administrador de Redes júnior, nunca instalou o serviço de DNS em uma empresa, você não sabe qual nome dar para as máquinas. Ao encontrar o seu amigo da empresa XYZ Informática ele te sugere escolher os nomes das máquinas que tenham alguma relação entre si, de um determinado conjunto. Ele te diz que na empresa onde ele trabalha o nome das máquinas são nomes de frutas. Daí você volta para a Cute Models e configura todas as máquinas com nomes de frutas. O que acontece?
   
    a) VERDADE: As máquinas vão funcionar perfeitamente, estão em domínios diferentes
    b) As máquinas podem não funcionar se as duas empresas escolherem a mesma frutaca Vocês tem que tar sempre em contato para não usar o nome da mesma fruta, senão como que o NIC vai saber em qual rede esta máquina esta
    d) Os nomes hierárquicos vão ser iguais mais os endereços IPs são diferentes portanto não tem problema nenhum
    e) As duas empresas vão ter que disputar na justiça quais nomes de frutas cada uma vai poder usar

    1) Marque Falso ou Verdadeiro
        a) (V) As aplicações padrão da Internet estão situadas entre as portas 1 à 1.024
        b) (V) As demais aplicações estão entre as portas 1.025 à 65.536
        c) (F) A porta 23 do TCP impede que você tenha uma porta UDP com o mesmo
        número
        d) (F) O serviço de FTP é utilizado para acessar uma máquina remotamente
        executando qualquer programa nela
        e) (F) Para que uma máquina A conecte-se a uma máquina B através do telnet é
        preciso que a máquina B esteja rodando o serviço de WWW
        f) (V) Quando você conecta-se a uma máquina pelo telnet, você tem que utilizar
        os comandos daquele sistema operacional
        g) (F) Pelo telnet e o DNS estarem extremamente relacionados, você só pode
        acessar uma máquina pelo nome hierárquico
        h) (F) O serviço de FTP é utilizado somente para fazer downloads de arquivos
        i) (V) A porta padrão utilizada pelo protocolo Telnet é 23
        j) (V) No serviço de e-mail, dentro do mesmo domínio não pode existir duas
        pessoas com o mesmo login
        k) (V) O login do e-mail pode não ter nada a ver com o nome do usuário
        l) (F) O protocolo utilizado para transferência de mensagens entre os diversos
        servidores de e-mail é o SNMP
        m) (F) A Internet é o serviço de WWW
        n) (V) O serviço de WWW permite a visualização de páginas com hipertextos
        o) (F) O ping é uma aplicação que permite obter maiores informações sobre um
        determinado usuário
        p) (F) POP3 é um protocolo responsável pelo envio de e-mails

    8) Sobre o FTP podemos afirmar que:
        a) É um programa para acessar uma máquina remotamente e executar um programa
        b) Permite a visualização de páginas WWW
        c) Transfere somente arquivos textos
        d)VERDADEIRA: Caso o usuário tenha uma senha a máquina remota, é possível fazer um download e um upload
        e) O FTP é o protocolo padrão para todas as transferências de dados, quer sejam páginas HTML (Home Page), quer sejam arquivos ou mesmo os e-mails.

    9) Sobre o e-mail podemos afirmar que:
        a) VERDADEIRA: Utiliza o SMTP para fazer a entrega de dados
        b) O usuário precisa estar com seu computador ligado para receber um e-mail
        c) VERDADEIRA: O servidor de e-mail precisa estar funcionando para receber os e-mails deste domínio
        d) É possível ter o mesmo login em servidores diferentes, deste que estes sejam do mesmo domínio.
   
    10)   Explique como (quais técnicas usadas) as aplicações WEB podem fazer controle de sessões, se o protocolo HTTP é um protocolo que não mantém estados das conexões.
        Resposta: Utilizando formas de armazenar essas sessões em arquivos, e transmitir estes arquivos pelo cabeçalho http, um exempli são os cokiees, assim quando o servidor receber uma mensagem http com um arquivo cokkoie anteirormente transmitido para o usuario ele sabera oque fazer.

    11)   Qual a função de um Proxy HTTP?
        Servidores proxy são utilizados para armazenar um deterinado arquivo em memoria cache porque o mesmo pode ser solicitado novamente por outros usuarios conectados na rede assim, auxiliando no desempenho já que o arquivo não precissara ser buscado na Internet o sevidor Proxy fica responsavel por devolver o arquivo, porem o proxy tem que dermina ate quando o arquivo pode ser utiliado, como exempo em páginas web podem ser armaqnadas em proxy de http para posteriormente ser transmitida.
