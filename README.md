Controle de Motor com Botão

Este projeto implementa o controle de um motor utilizando um botão. Quando o botão é pressionado, o motor é ligado por 10 segundos, durante os quais o tempo decorrido é exibido em um display LCD. Após esse tempo, o motor é desligado e o botão pode ser pressionado novamente.


Descrição

Funcionamento:

O motor é controlado por um transistor conectado ao pino digital 3 do microcontrolador.

O botão, conectado ao pino digital 2, utiliza um resistor de pull-up interno para garantir leituras estáveis.

Um display LCD é utilizado para informar o status do motor ("Ligado" ou "Desligado") e o tempo decorrido durante a operação.


Ambiente de Desenvolvimento

O projeto foi desenvolvido no Proteus Design Suite 8.13.

Observação Importante

O componente Push Button teve que ser criado manualmente como uma biblioteca personalizada. Portanto, pode haver problemas na simulação se a biblioteca não estiver carregada ou configurada.

Caso o botão não apareça no layout ou a simulação não funcione, um vídeo foi incluído no repositório demonstrando o funcionamento do projeto.

A pasta com a library foi diponibilizada.


Passos para adicionar a biblioteca manualmente no Proteus:

Copiar a pasta da biblioteca para o diretório de bibliotecas do Proteus:

No computador onde o Proteus está instalado, localize a pasta da biblioteca personalizada que você deseja adicionar.
Copie a pasta contendo os arquivos da biblioteca (geralmente arquivos .LIB e .IDX).
Vá até o diretório de bibliotecas do Proteus. O caminho padrão geralmente é:
C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\LIBRARY
Cole a pasta da biblioteca personalizada nesse diretório.


Simulação:

Execute a simulação no Proteus para verificar o funcionamento do controle do motor.

Código Fonte:

O código fonte em C++ é responsável por gerenciar as operações do motor, a interação com o botão e a exibição de mensagens no LCD.
