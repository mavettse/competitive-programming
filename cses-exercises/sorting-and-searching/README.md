# Sorting and Searching

Resoluções dos exercícios de ordenar e pesquisar do CSES.

## Tabela de Conteúdos

| ID | Nome do Problema | Solução |
| :--- | :--- | :---: |
| 1621 | Distinct Numbers | [Código](./1621.cpp) |
| 1084 | Apartments | [Código](./1084.cpp) |
| 1090 | Ferris Wheel | [Código](./1090.cpp) |
| 1091 | Concert Tickets | [Código](./1091.cpp) |
| 1619 | Restaurant Customers | [Código](./1619.cpp) |
| 1629 | Movie Festival | [Código](./1629.cpp) |
| 1640 | Sum Of Two Values | [Código](./1640.cpp) |
| 1643 | Maximum Subarray Sum | [Código](./1643.cpp) |
| 1074 | Stick Length | [Código](./1074.cpp) |
| 2183 | Missing Coin Sum | [Código](./2183.cpp) |
| 2216 | Collecting Numbers | [Código](./2216.cpp) |
| 2217 | Collecting Numbers II | [Código](./2217.cpp) |
| 1141 | Playlist | [Código](./1141.cpp) |
| 1073 | Towers | [Código](./1073.cpp) |
| 1163 | Traffic Lights | [Código](./1163.cpp) |
| 3420 | Distinct Values Subarrays | [Código](./3420.cpp) |
| 3421 | Distinct Values Subsequences | [Código](./3421.cpp) |
| 2162 | Josephus Problem I | [Código](./2162.cpp) |
| 2163 | Josephus Problem II | [Código](./2163.cpp) |
| 2168 | Nested Ranges Check | [Código](./2168.cpp) |
| 2169 | Nested Ranges Count | [Código](./2169.cpp) |
| 1164 | Room Allocation | [Código](./1164.cpp) |
| 1620 | Factory Machines | [Código](./1620.cpp) |
| 1630 | Tasks and Deadlines | [Código](./1630.cpp) |
| 1631 | Reading Books | [Código](./1631.cpp) |
| 1641 | Sum of Three Values | [Código](./1641.cpp) |
| 1642 | Sum of Four Values | [Código](./1642.cpp) |
| 1645 | Nearest Smaller Values | [Código](./1645.cpp) |
| 1660 | Subarray Sums I | [Código](./1660.cpp) |
| 1661 | Subarray Sums II | [Código](./1661.cpp) |
| 1662 | Subarray Divisibility | [Código](./1662.cpp) |
| 2428 | Distinct Values Subarrays II | [Código](./2428.cpp) |
| 1085 | Array Division | [Código](./1085.cpp) |
| 1632 | Movie Festival II | [Código](./1632.cpp) |
| 1644 | Maximum Subarray Sum II | [Código](./1644.cpp) |

---

## 1621 - DISTINCT NUMBERS
- Cria-se um vetor de inteiros para armazenar todos os n números da entrada.
- Depois, utiliza-se a função sort da biblioteca Algorithms para ordenar os números dentro do vetor.
- Com os números ordenados em ordem crescente, basta contar quantos deles são diferentes.

## 1084 - APARTMENTS
- Após armazenar os inteiros dos compradores, dos apartamentos e da tolerância; e os vetores contendo os tamanhos desejados e os tamanhos disponíveis da cada apartamento, utiliza-se a função sort para organizar os vetor em ordem crescente. 
- Organizando-os dessa forma, tem-se a garantia de que o menor apartamento disponível será oferecido para a pessoa que deseja o menor tamanho possível.
- Utilizam-se dois ponteiros para percorrer ambos vetores em um while, que se repete enquanto esses forem maiores do que o tamanho de seus respectivos vetores. 
- Dentro do laço, dois blocos condicionais são executados:
	- Se o tamanho do apartamento atual for menor do que o tamanho mínimo aceitável, o ponteiro dos apartamentos avança, pois, como os apartamentos estão organizados de forma crescente, o tamanho do próximo apartamento com certeza será maior do que o anterior.
	- Se o tamanho do apartamento atual for maior que o tamanho máximo aceitável, o ponteiro dos tamanhos desejados pelos compradores avança, pois a próxima pessoa com certeza desejará um apartamento maior do que a anterior. 
	- Se nenhum dos casos ocorrer, então uma pessoa encontrou um apartamento. 

## 1090 - FERRIS WHEEL
- Para encontrar o número mínimo de gôndolas, armazena-se os pesos das crianças em um vetor, ordenado com a função sort. 
- Depois, cria-se dois ponteiros, um que aponta para o início e outra que aponta para o fim, para percorrer os pesos em um loop. 
- O algoritmo se baseia na ideia de manter a criança mais pesada (parte final do vetor) com a criança mais leve (parte inicial do vetor). 
- Se a soma dessas duas crianças for menor ou igual ao peso máximo permitido da gôndola, então ambas as crianças vão juntas (o ponteiro inicial incrementa e o final decrementa em 1).
- Já se a soma for maior que o peso máximo, então a criança mais pesada irá sozinha na gôndola, enquanto a mais leve permanece esperando uma que seja compatível com seu peso. 

## 1091 - CONCERT TICKETS
- Para tal algoritmo, utiliza-se a estrutura de dados multiset, que funciona como o set, armazenando os elementos de forma ordenada, mas permitindo repetições. Os preços dos tickets são armazenados no multiset. 
- Um loop é iniciado para fazer a leitura dos preços máximos que os clientes estão dispostos a pagar e os armazenando no inteiro precoMax.
- A cada iteração do loop, utiliza-se a função upper_bound no multiset com o inteiro lido. Essa função retorna um iterador que aponta para o primeiro elemento, dentro do multiset, que é maior que o inteiro inserido por parâmetro. Tal iterador é salvo em ptrMaior.
- Após isso, um bloco condicional é executado:
	- Se o iterador apontar para o início do multiset, então todos os valores são maiores que o inteiro precoMax lido. Isso porque, como os elementos estão ordenados, se o primeiro deles já for maior que o limite estabelecido pelo cliente, então todos os outros também serão maiores. Logo, não haverá nenhum preço de ticket que atenda aos critérios do cliente.
	- Já se o iterador não apontar para o início, então ele é decrementado em um (já que ele aponta para o primeiro maior, então o valor anterior a ele será menor ou igual ao valor estabelecido pelo cliente). O valor apontado por ele é então impresso e removido do multiset (passa-se o iterador para remoção ao invés do valor, pois, passando-se o valor, todos os elementos iguais a ele são removidos).

## 1619 - RESTAURANT CUSTOMERS
- Cria-se um par de inteiros que será responsável por armazenar os horários de chegada e saída da seguinte forma: 
	- evento = {a, 1}; em que a representa o horário e 1 representa que é chegada. 
	- evento = {b, -1}; em que b representa o horário e -1 representa que é saída.
- Cria-se, também, um vetor de pares de inteiros que será responsável por armazenar todos os pares de horários. 
- Uma vez que todos os horários foram devidamente armazenados, utiliza-se a função sort para organizar os eventos em ordem crescente.
- Após isso, basta percorrer todo o vetor e utilizar uma variável auxiliar para armazenar a quantidade de pessoas que estão atualmente dentro do restaurante.
	- Se o segundo número do par atual for maior que zero, então é uma chegada, logo, a variável auxiliar vai incrementar em um.
	- Se o segundo número do par atual for menor que zero, então é uma saída, logo, a variável auxiliar vai decrementar em um. 
	- Após tal bloco condicional, outro será executado para verificar se a quantidade de pessoas atual é maior que a máxima registrada até agora. Se for, então a máxima é atualizada, se não, segue para o próximo horário.

## 1629 - MOVIE FESTIVAL
- Cria-se um vetor de par de inteiros responsável por armazenar todos os horários de todos os filmes e um par de inteiros para armazenar temporariamente os horários dos filmes a cada iteração; Os horários dos filmes serão armazenados da seguinte forma:
	- {b, a}, ou seja, {fim, início};
	- O motivo para armazenar dessa forma é simples: a fim de assistir a maior quantidade de filmes possível, os filmes que terminam mais cedo precisam ter prioridade; quanto mais cedo um filme se encerrar, mais filmes dará para ver depois dele. 
- Após armazenar todos os valores, utiliza-se o sort para organizar os elementos dentro do vetor dos horários. 
- Então, uma variável auxiliar é responsável por guardar o horário final do último filme assistido.
- Um laço itera pelo vetor de pares e executa o seguinte bloco condicional:
	- Se o horário inicial do filme atual for maior ou igual ao horário final do último filme assistido, então esse filme também pode ser assistido; A variável que armazena os filmes assistidos incrementa em um e a auxiliar recebe o último horário do filme atual. 

## 1640 - SUM OF TWO VALUES
- Para resolver tal problema, basta criar um map de inteiros para armazenar os números da array que será passada. 
- Dentro do loop para ler todos os números, será feita uma busca dentro do map. Se tem-se, por exemplo:
	- No map, os números 2 e 7, o número atual lido foi 4 e o número alvo é 6. A cada iteração, verifica-se se existe, dentro do map, o número alvo subtraído do número atual; (alvo - atual), que, nesse caso, seria 6 - 4 = 2. 
	- Se o número existir, então serão impressas as posições do número dentro do map e do número atual. No caso do exemplo, a posição do número 2 dentro do map é 1 (0 + 1), e a  posição do número atual dentro do loop é 3 (2 + 1). Portanto, será impresso 1 e 3.
	- Se o número não existir dentro do map, então o número atual será inserido nele e o loop seguirá até ler todos os números. 
	- Se nenhum par de números for encontrado, será impresso que é impossível.

## 1643 - MAXIMUM SUBARRAY SUM
- Para esse problema, cria-se duas variáveis long long: maxSoma para armazenar o valor máximo das somas e somaAtual para armazenar o valor das somas até o momento.
- Dentro do loop para ler todos os n valores, faz-se duas operações principais: 
	- A soma atual vai receber o maior valor entre o número atual ou a soma dele mesmo com o número atual. Essa linha funciona como um if/else; se a soma atual com o número atual for menor que o número atual, a variável soma atual recebe o valor do número atual; senão, ela recebe a soma entre os dois.	
	- O valor da soma máxima é atualizado para o maior valor entre ela mesma e a soma atual.

## 1074 - STICK LENGTHS
- Armazena-se todos os números em um vetor e ordena-o em ordem crescente com o sort. 
- A ordenação serve para obter a mediana, que é um valor que divide um conjunto ordenado em partes iguais. Como ela representa o valor central, a soma das distâncias entre essas duas partes se torna a menor possível.
- Após pegar a mediana, basta somar o valor absoluto entre as diferenças de todas as varetas.

## 2183 - MISSING COIN SUM
- Para descobrir a menor soma que não é possível fazer, o vetor contendo os valores das moedas deve estar ordenado. 
- Depois, deve-se criar uma variável para guardar a soma atual das moedas sequencialmente. Tal variável é incrementada dentro de um loop que percorre o vetor contendo as moedas ordenadas.
- Utilizando-se do exemplo das seguintes moedas: 1 2 2 7 9; Para descobrir o intervalo em que existe um "buraco", soma-se um por um: 
	- 1ª iteração: Moeda 1; somaAtual = 0 + 1 = 1; intervalo {1};
	- 2ª iteração: Moeda 2; somaAtual = 1 + 2 = 3; intervalo {1,3}; O intervalo aumentou porque agora tem o valor 2 sozinho e a soma dele com a soma anterior {2,2+1} = {2,3} (tal intervalo é adicionado ao anterior {1}, ficando {1} e {2,3} = {1,3});
	- 3ª iteração: Moeda 2; somaAtual = 3 + 2 = 5; intervalo {1,5}; O intervalo aumentou porque agora tem o valor 2 sozinho (que já tinha antes) e a soma dele com a soma anterior {2,2+3} = {2,5} (tal intervalo é adicionado ao intervalo anterior, ficando {1,3} e {2,5} = {1,5});
	- 4ª iteração: Moeda 7; somaAtual = 5 + 7 = 12; intervalo {1,5} e {7,12}; O intervalo atual ficou dessa forma pois ele possui o 7 sozinho e a soma dele com a soma anterior {7,7+5} = {7,12}; Percebe-se, então, que um buraco foi formado na iteração 4; não é possível formar a soma do número 6.
- Em código, se a soma atual + 1 for menor do que a próxima moeda, então esse valor (soma atual + 1) é a soma impossível. Nota-se isso também no exemplo anterior: 
	- somaAtual na 3ª iteração = 5; A próxima moeda é 7; somaAtual + 1 = 5 + 1 = 6; Como 6 < 7, então 6 é a soma impossível. 

## 2216 - COLLECTING NUMBERS
- Para saber a quantidade de rounds necessários para ler uma sequência de números de 1 a n, basta seguir o seguinte raciocínio: 
	- Utilizando a sequência 4 2 1 5 3 como exemplo; Na leitura de cada número, pode-se fazer a seguinte associação: Lendo o número 4, o primeiro número da sequência, se seu antecessor 3 ainda não foi lido, então mais uma rodada terá que acontecer para essa leitura, então round = 1; Lendo o número 2, percebe-se que seu antecessor 1 também não foi lido, logo, round = 2; Lendo o número 1, que é onde a contagem se inicia, pode-se também incrementar as rodadas, round = 3; Lendo o número 5, seu antecessor já foi lido, então o round permanece igual a 3; A mesma coisa acontece com o número 3, então, round = 3;
- Tendo tal leitura em mente, tem-se a seguinte ideia: Se, após ler o número X, notar que seu antecessor X-1 ainda não foi lido, então mais uma rodada precisará ser feita para tal leitura. 
- Diante disso, cria-se um vetor de inteiro dos números lidos com capacidade n+1.
- Um loop itera pela sequência dos números e verifica se o número anterior a ele já foi lido, se não, incrementa rounds; Após cada iteração, o número atual é marcado como lido no vetor. 

## 2217 - COLLECTING NUMBERS II
- A resolução desse exercício tem como base o algoritmo do exercício anterior para calcular a quantidade de rounds da sequência de números inserida inicialmente. A diferença é que, ao invés de ter somente um vetor indicando se o número foi lido ou não, têm-se dois vetores: um que armazena as posições dos números e outro que armazena os valores. 
- O ponto principal nesse é realizar o cálculo dos rounds após a troca da posição dos números da sequência. 
- Para cada vez que posicao[valor] < posicao[valor-1], a quantidade de rounds aumenta em 1. O foco aqui é pegar retirar a quantidade de rounds que foram adicionadas por razão das posições dos valores em a e em b.
- Se a e b forem, por exemplo, 2 e 3, e a sequência inicial for 4 2 1 5 3, com rounds = 3, os valores que serão movidos de lugar são 2 e 1. 
- Os números que são afetas por tais valores são aqueles em suas vizinhanças, então deve-se chegar todos os pares que possuem uma unidade de diferença entre eles: Para o número 2: (1,2) e (2,3); Para o número 1: (0,1) e (1,2); Como possui 2 pares diferentes e 1 deles está fora do intervalo dos números, sobra: (1,2) e (2,3).
- Tendo os pares de valores, a sequência antes da troca, e a quantidade de rounds, basta subtrair do número de rounds toda vez que posicao[valor] < posicao[valor-1];
	- Para a sequência 4 2 1 5 3:
	- (1,2): posicao[2] = 2; posicao[1] = 3; Como 2 < 3, rounds = 3 - 1 = 2;
	- (2,3): posicao[3] = 5; posicao[2] = 2; Como 5 > 2, nada é feito. 
- Agora, basta fazer a troca e incrementar em 1 a quantidade de rounds toda vez que posicao[valor] < posicao[valor-1]; 
	- Para a sequência trocada 4 1 2 5 3:
	- (1,2): posicao[2] = 3; posicao[1] = 2; Como 3 > 2, nada é feito.
	- (2,3): posicao[3] = 5; posicao[2] = 3; COmo 5 > 3, nada é feito.
	- Logo, a quantidade de rounds após a troca é 2.
- Ou seja, o algoritmo, basicamente, subtrai os valores dos rounds inseridos antes da troca, realiza a troca e adiciona os valores dos rounds que ocorreram após ela. 

## 1141 - PLAYLIST
- Para contar a quantidade máxima de músicas que tocam sem se repetir, faz-se uso de unordered map para armazenar as músicas da playlist e de dois ponteiros indicando o início e o fim da sequência de faixas atual. 
- Dentro do loop para ler as músicas da playlist, é feito uma verificação: 
	- Se a faixa atual já existir dentro do map e sua posição estiver na frente do ponteiro de início, esse ponteiro tem seu valor atualizado; o início da subsequência passa a ser a posição seguinte à faixa existente.
- Em todos os casos, a faixa atual é inserida (ou tem seu valor atualizado) no map com a key sendo a faixa e o valor sendo o índice atual, o ponteiro apontando para o final da subsequência é atualizado para a índice atual e a variável que armazena o valor máximo recebe o valor máximo entre seu valor anterior ou a sequência atual.

## 1073 - TOWERS
- O primeiro passo para descobrir a quantidade de torres necessárias para empilhar n cubos, sendo o mais acima de um tamanho menor do que está mais abaixo, é criando um vetor de inteiros. O vetor tem n posições reservadas e cada posição dele representa uma torre. 
- Dentro do loop para ler os tamanhos dos cubos, utiliza-se a função upper bound do STL; essa função retorna um iterador que aponta para o primeiro elemento maior do que um valor passado por parâmetro; o valor, nesse caso, é o tamanho do cubo. 
- Então, um bloco condicional é executado:
	- Se o iterador mencionado apontar para o final do vetor, uma nova torre será criada com o cubo atual sendo a base.
	- Caso negativo, o valor apontado pelo iterador terá seu valor atualizado para o cubo atual.
- Ou seja, o algoritmo utiliza um vetor, em que cada posição representa uma torre, para armazenar somente o valor do último cubo posicionado, pois os valores anteriores não importam mais. Esse vetor então é utilizado como base para criar uma nova torre ou inserir um cubo em uma já existente.

## 1163 - TRAFFIC LIGHTS
- Para tal solução, utiliza-se duas estruturas de dados: um set de inteiros chamado posSemaforos para armazenar as posições dos semáforos (começando inserindo os semáforos nas posições 0 e p1) e um multiset de inteiros chamado comprimentos para, obviamente, armazenar os comprimentos entre os intervalos de semáforos, o primeiro comprimento inserido é o do p1 atual. 
- Inicia-se, então, um loop para fazer a leitura dos semáforos e a lógica dos comprimentos dos intervalos.
- O primeiro passo dentro do loop é descobrir quais são os semáforos vizinhos do semáforo atual. Isso é feito utilizando a função upper_bound, que retorna o 1º valor maior que um valor passado por parâmetro (o valor passado é a posição do semáforo atual), então tem-se a posição do semáforo à esquerda e do semáforo à direita do semáforo atual. 
- Como um semáforo será inserido entre esses dois, o comprimento desse intervalo deve ser removido do multiset. Tal operação é feita utilizando o comando find para buscar um iterador e, em seguida, removendo-o do multiset de comprimentos. (o iterador é utilizado ao invés do valor para que todos os valores iguais não sejam removidos de dentro do set). 
- Após isso, insere-se a posição do semáforo atual no set das posições e os comprimentos da esquerda (pi - esq) e da direita (dir - pi) no multiset dos comprimentos. 
- Na última linha do loop, é feita a impressão do maior valor do multiset de comprimentos.

## 3420 - DISTINCT VALUES SUBARRAYS
- A solução para esse exercício é similar à solução do exercício 1141 - Playlist. Utiliza-se um map e a técnica da janela deslizante.
- Dois inteiros esq e dir são criados para apontar o início e o fim do intervalo das subarrays sem repetição, enquanto o map nums armazena os números.
- Faz-se a leitura de cada número da array dentro de um for loop e a função find() é utilizada para verificar se o número lido já foi inserido no map.
	- Se o número já foi lido e o seu índice estiver dentro da janela {esq,dir}, então o ponteiro esq, que aponta para o início do intervalo, recebe o valor do índice da frente incrementado em 1. 
- Ao final do loop, o map armazena (ou atualiza) o valor do número atual com o índice atual, e a variável que contém os subarrays válidos é atualizada. 

## 3421 - DISTINCT VALUES SUBSEQUENCES
- Para resolver tal problema, utiliza-se o exemplo dado: 
1 2 1 3; Agrupando a sequência para a frequência de cada número, obtêm-se: 1 1 2 3;
	- A quantidade de vezes que o número 1 aparece é 2, então f1 = 2; Mas a quantidade de maneiras que ele pode ser selecionado em uma subsequência é: [1] (o primeiro), [1] (o último) e [] (nenhum dos dois). Ou seja, f1 + 1 = 2 + 1 = 3 é a quantidade de combinações que podem ser feitas com ele.
	- A quantidade de vezes que o número 2 aparece é 1, então f2 = 1; a quantidade de maneiras que ele pode ser selecionado em uma subsequência é: [2] e []. Ou seja, f2 + 1 = 1 + 1 = 2 é a quantidade de combinações que podem ser feitas com ele. O exemplo do 2 é análogo ao 3, já que ele também só aparece uma vez. 
- Para saber a quantidade total de combinações de subsequências, basta multiplicar: (f1 + 1) * (f2 + 1) * (f3 + 1) = 3 * 2 * 2 = 12. No entanto, ao multiplicar todas essas combinações, a combinação em que todos os elementos vazios são selecionados também entra [,,,]; como ela não faz parte das combinações, ela é retirada subtraindo 1: 12 - 1 = 11.
- Ou seja, para descobrir a quantidade total de subsequências (que não passa de uma combinação), basta multiplicar a frequência de todos os números (contando com não-seleção desses números) e depois subtrair 1 de tal resultado, retirando o conjunto vazio. 
- Para não estourar o tamanho da variável que vai armazenar o total, é importante utilizar a propriedade do módulo de (a*b) % MOD = (a%MOD * b%MOD) % MOD.

## 2162 - JOSEPHUS PROBLEM I
- Como o exercício segue um padrão cíclico de alternância na remoção das crianças, utiliza-se uma fila. 
- Armazena-se, inicialmente, os valores de 1 a n dentro da fila, com 1 sendo o primeiro e n sendo o último. 
- Depois, cria-se uma variável auxiliar remover inicializada com 0, que funcionará de forma a decidir se a criança atual será removida ou pulada. 
- Então, cria-se um loop enquanto a fila não estiver vazia. 
- Dentro dele, um bloco condicional faz a seguinte verificação: 
	- Se remover estiver em 1, então o número da criança atual será impresso. 
	- Se remover estiver em 0, então a criança atual será inserida no último lugar da fila. 
	- Ao fim do bloco condicional, independente do resultado, a criança que está no primeiro lugar da fila será removida e o valor contido em remover será invertido. 
- Dessa forma, se n = 3, por exemplo, o código fará o seguinte: 
	- lista contem 1 2 3; remover = 0, então a lista passa a ser 2 3 1 e remover = 1;
	- lista contem 2 3 1; remover = 1, então, a lista passa a ser 3 1 e remover = 0;
	- lista contem 3 1; remover = 0, então a lista passa a ser 1 3 e remover = 1;
	- lista contem 1 3; remover = 1, então a lista passa a ser 3 e remover = 0;
 	- lista contem 3; remover = 0, lista permanece a mesma, pois só existe um elemento dentro dela e remover = 1;
	- lista zera e finaliza;
	- Tal iteração imprime na ordem em que os elementos foram removidos, então seria: 2 1 3

## 2163 - JOSEPHUS PROBLEM II
- Para resolver esse exercício, foi-se feita a inserção das PBDS para o uso de um ordered_set. Ele funciona normalmente como um set, mas pode ser acessado através de índice e a remoção de elementos ocorre em complexidade em O(log n), muito mais rápido do que um vector (O(n)). 
- Utilizando do exemplo n = 4 e k = 2: 
	- o ordered_set nums contem 1 2 3 4; respectivamente nas posições 0, 1, 2 e 3; com um ponteiro apontando para o primeiro índice, pos = 0; a remoção é feita pulando k vezes a partir da posição atual, por precaução, deve-se utilizar o módulo da quantidade atual de elementos dentro de nums, a fim de manter o ponteiro dentro dos limites; ou seja: pos = (pos + k) % nums.size() = (0 + 2) % 4 = 2, então o elemento na posição 2 será removido;
	- nums contem 1 2 4; pos = 2; a remoção será feita em pos = (pos + k) % nums.size() = (2 + 2) % 3 = 1;
	- nums contem 1 4; pos = 1; a remoção será feita em pos = (1 + 2) % 2 = 1;
	- nums contem 1; pos = 1; a remoção será feita em pos = (1 + 2) % 1 = 0;
	- Como a impressão é feita em ordem de retirada, a saída será: 3 2 4 1;

## 2168 - NESTED RANGES CHECK
- Para esta solução, fez-se o uso de uma struct Intervalo, que armazena o início, o fim, e o índice original de um dado intervalo; a criação de uma função que retorna um bool para personalizar a função sort da biblioteca algorithms, se o início de dois intervalos forem iguais, o primeiro na ordenação será aquele que possui o maior fim.
- Cria-se, então, um vector da struct Intervalo chamada intervalos; todos os intervalos da entrada são armazenados dentro dele, juntamente de seus índices originais; O vector então é ordenado seguindo os critérios requisitados pela função: se o início de dois intervalos for igual, então o que tem o maior fim possui prioridade e vai primeiro; se não, ele é ordenado em ordem crescente normalmente. 
- A primeira lógica feita é a de verificar se um intervalo contém outro;
	- Um vetor de inteiros é criado para armazenar 1 se um intervalo contém, e 0 se não. As posições cujos intervalos serão salvos nesse vetor vai depender exclusivamente do índice original desses intervalos, e não do índice atual deles (já que eles foram trocados de lugar por causa da função sort). 
	- É feita uma leitura de trás para frente do vetor; E, a cada iteração, o vetor contem verifica se o o fim do intervalo atual é maior ou igual ao menor intervalo já visto até o momento. A variável responsável por armazenar o menor fim visto é atualizada a cada iteração. 
	- Como a leitura é feita de trás para frente, garantidamente o último vetor não contém ninguém, pois, além além dele possuir o maior início, mesmo que o início de todos os vetores seja igual, ele terá o menor fim, não podendo conter nenhum número.
- A segunda lógica é a verificação se um intervalo está contido em outro:
	- Ela funciona de forma análoga à primeira lógica, sua diferença é que, ao invés do vetor percorrer de trás para frente, ele percorre do início até o fim, armazenando em uma variável o maior fim encontrado até o momento e fazendo a verificação se o fim do intervalo atual é menor ou igual ao maior fim encontrado até o momento. Assim como o último elemento do vetor não poderia conter ninguém, o primeiro item desse vetor também jamais poderá estar contido em outro. Isso porque, além de seu início ser menor que todos os outros, mesmo que ele seja igual ao de todos, o seu fim ainda seria maior que de todos os outros, o que torna impossível que algum outro intervalo seja capaz de contê-lo.

## 2169 - NESTED RANGES COUNT
- A estratégia inicial do problema anterior (2168 - Nested Ranges Check) de organizar os intervalos dentro do vetor com suas posições originais continua a mesma. O que muda é a lógica utilizada depois da ordenação. 
- Para a contagem de intervalos que contêm outros, cria-se um vetor contem, responsável por armazenar as contagens, e um ordered_multiset finsOrdenados, que é capaz de contar a quantidade de elementos menores que um valor passado através de função order_of_key().
	- Como o vetor está em ordem crescente, a sua leitura é feita de trás para frente (em ordem decrescente), pois, assim, a única condição que precisa ser checada para saber se um dado intervalo contém seus anteriores é se FimA >= FimAnteriores; isso porque, garantidamente, InicioA <= InicioAnteriores. 
	- Dito isso, como a função order_of_key() retorna a quantidade de elementos dentro do set que são estritamente menores que o elemento atual, faz-se a chamada order_of_key(fim + 1); pois, dessa forma, sabe-se que o retorno será a quantidade de elementos menores ou iguais a fim. 
	- Depois disso, basta atualizar o índice original do vetor contem com o retorno da função anterior e inserir o fim do intervalo atual no ordered_multiset finsOrdenados.
- A contagem de intervalos que estão contidos em outros é similar à anterior: Cria-se um vetor contidos e limpa-se o ordered_multiset utilizado anteriormente. 
	- Nessa contagem, a leitura do vetor será feita em sua ordem padrão (crescente). Como order_of_key() retorna a quantidade de elementos menores que o valor passado, ao subtrair o total de elementos lidos da quantidade de elementos menores que o fim (retorno da função), obtém-se a quantidade de elementos maiores ou iguais ao fim. 
	- Depois dessa operação, o vetor que armazena a contagem recebe o valor da subtração anterior na posição original do intervalo. O fim do intervalo atual é, então, inserido no ordered_multiset.

## 1164 - ROOM ALLOCATION
- A estratégia utilizada para garantir que todos os hóspedes tenham um quarto único e que o número de quartos seja o menor possível é: 
	- Armazenar os hóspedes em um vetor ordenado de forma crescente de uma struct que armazena o horário de chegada, de saída e o índice original.
	- Armazenar os quartos em um multiset de par de inteiros em que o primeiro elemento é o horário de saída e o segundo elemento é o número do quarto. 
	- Armazenar o histórico dos quartos dos hóspedes em um vetor de inteiro chamado alocações, de tamanho n.
	- Armazenar o número do maior quarto como um inteiro simples. 
- Com essas variáveis criadas, faz-se uma iteração do vetor de hospedes (após a sua ordenação).
	- Dentro do loop, é coletado o primeiro par do multiset quartos, pois esse possui o menor dia de saída. Esse par, então, servirá de base para saber se o hóspede atual será encaixado em um novo quarto ou em um já usado anteriormente. 
	- Se o dia de saída do quarto do primeiro par for menor que o dia de chegada do hóspede atual,  então esse novo hóspede se instalará nesse quarto. 
	- Caso contrário, a variável que armazena o número do maior quarto será incrementada em um e o hóspede atual se instalará nesse novo quarto aberto. 
	- Em ambos os casos, o vetor alocações insere o número do quarto do índice original do hóspede. 

## 1620 - FACTORY MACHINES
- Após armazenar todos os tempos das máquinas em um vetor, faz-se uso da busca binária para encontrar o tempo mínimo.
	- Primeiro, três variáveis auxiliares são criadas: tempoMin inicializada com 1, servindo como o início da busca, tempoMax inicializada com 1e18, servindo como fim da busca, e candidato inicializada com 1e18, que armazenará a resposta correta. 
	- Dentro do loop responsável pela busca, outras duas variáveis são criadas: tempo, que funciona como o "meio" da busca binária, e produtos, que armazena a quantidade de produtos que são feitos no tempo determinado. 
	- Um loop percorrendo os tempos das máquinas é percorrido a fim de incrementar a variável produtos com os tempos necessários de cada máquina. 
	- Por fim, é feita a verificação: se produtos for menor que a quantidade t fornecida pela entrada, então a busca binária reiniciará a busca a partir da metade direita do intervalo; já se a produção for maior ou igual a t, a busca binária reiniciará a partir da metade esquerda do intervalo e a variável candidato receberá o menor valor (menor tempo) entre ela mesma e o tempo (meio). 

## 1630 - TASKS AND DEADLINES
- A fim de encontrar a maior recompensa possível, precisa-se obter a menor soma (momentânea) das durações possível, já que o algoritmo consiste em fazer ∑(prazo - tempoFim) = ∑prazo - ∑tempoFim; Embora o termo ∑prazo seja sempre o mesmo, para maximizar o resultado, a estratégia é minimizar o termo ∑tempoFim.
- Para isso, basta ordenar a estrutura de dados que armazena as tarefas de forma que as durações fiquem em ordem crescente. Dessa forma, o somatório resultará no maior valor possível. 

## 1631 - READING BOOKS
- Para encontrar o menor tempo possível, basta notar que: 
	- Toda vez que a duração de um livro sozinho é maior do que a soma da duração de todos os outros livros, o menor tempo possível será o dobro da duração desse livro. Isso porque o tempo desse maior livro se torna um "gargalo", então é ele quem vai ditar o tempo final; o Kotiivalo e a Justina só podem iniciar um livro se o outro já tiver terminado e, como o tempo do maior livro é maior do que a soma de todos os outros, isso quer dizer que enquanto um deles está lendo o maior, os outros podem ler todos os outros livros e ainda sobrará tempo. Esse tempo restante é o tempo que um dos leitores fica ocioso, esperando o outro finalizar o maior livro. 
	- Se a duração do maior livro não for maior que a soma de todos os outros livros, então o tempo mínimo necessário será a soma de todos os livros; como não há um "gargalo" causado por um único livro, as leituras podem ser feitas livremente, sem que ninguém fique ocioso.

## 1641 - SUM OF THREE VALUES
- Para encontrar a soma de três valores, armazena-se os números em um vetor ordenado de pares de inteiro, em que {chave, valor} = {número, posição}, e a técnica utilizada é a dos dois ponteiros.
- O exercício pede três números tal que: a + b + c = alvo, que é, essencialmente, a + b = alvo - c.
- Tendo isso em mente, um loop percorre todo o vetor e fixa um novoAlvo = alvo - c. Dessa forma, o problema de encontrar três valores se transforma em um problema de encontrar dois. 
- Dois ponteiros são, então, criados com início (esq) na próxima posição do número atual e fim (dir)  no último elemento do vetor. 
- Após isso, um loop while é criado para varrer os números entre esses dois ponteiros:
	- Um inteiro auxiliar dentro do loop armazena a soma dos números apontados pelos ponteiros; 
	- Se essa soma for maior do que o novo alvo, o ponteiro da direita volta uma posição; Se a soma for menor que o novo alvo, o ponteiro da esquerda avança uma posição; Essas operações podem ser feitas, pois o vetor foi ordenado logo após o início, o que garante que, quanto mais à direita do ponteiro da esquerda (esq), maior o número, bem como, quanto mais à esquerda do ponteiro da direita (dir), menor o número.
	- Se nenhuma das condições anteriores foram atendidas, então quer dizer que a soma é igual ao novo alvo; nesse caso, os três valores foram encontrados; O loop, então, dá um break e imprime as posições. 	 

## 1642 - SUM OF FOUR VALUES
- O algoritmo desse exercício é bastante similar ao do exercício anterior (1641 - Sum Of Three Values).
- A diferença é que, ao invés de dois loops, esse possui três. 

## 1645 - NEAREST SMALLER VALUES
- O algoritmo funciona da seguinte forma: 
	- Toda vez que um número menor do que os anteriores for lido, os anteriores (maiores) serão deletados; isso porque, se o número na posição atual é menor que todos os outros que vieram antes dele, então ele será o primero cobiçado pelos próximos que forem maior que ele;
- Para isso funcionar, os números são armazenados em uma stack (pilha) de pares de inteiros {numero, posicao}.
- Um loop para ler os valores então se inicia.
	- Dentro dele, outro loop também é iniciado com a condição de se repetir enquanto a pilha não estiver vazia.	
		- Dentro desse segundo loop, um bloco condicional é executado: os números no topo da pilha serão excluídos enquanto forem maiores ou iguais ao número atual; quando essa condição não ocorre, é feita a impressão do número no topo da fila (pois esse é menor do que o atual) e o loop se encerra.
	- Depois, se a pilha estiver vazia, será impresso "0"; Isso porque, ou essa é a primeira iteração, ou todos os valores dentro da pilha eram menores do que o valor atual; 
	- Por fim, o número atual é inserido dentro da pilha.

## 1660 - SUBARRAY SUMS I
- Utiliza-se a técnica da janela deslizante: 
	- Cada número lido tem seu valor somado ao total do intervalo da janela deslizante. Se essa soma for maior que o valor alvo, a janela avança seu ponto inicial; Se a soma for igual ao valor alvo, então uma subarray foi encontrada; Se a soma for menor ao valor alvo, então a janela avança seu ponto final.
- Tal implementação faz uso de duas variáveis que servem de ponteiros para o intervalo (janela) atual, uma variável para armazenar a soma desse intervalo, outra para contar a quantidade de subarrays e um vetor para armazenar os números. 
- Um loop se inicia para fazer a leitura de todos os números.
	- O número atual é inserido no vetor e a soma do intervalo adiciona o valor do número atual. 
	- Outro loop tem início:
		- Enquanto a soma for maior que o alvo e o ponteiro de início for maior que o de fim, a janela diminuirá; A soma decrementa o valor que reside na posição do ponteiro de início e depois esse ponteiro é avançado.
	- Depois, se a soma for igual ao alvo, a quantidade de subarrays incrementa em um; se não, o ponteiro do fim avança.

## 1661 - SUBARRAY SUMS II
- Para encontrar a quantidade de subarrays que possuem, como soma, o alvo, faz-se uso de um map para utilizar a técnica prefix sum. Essa técnica consiste em armazenar, em cada posição do vetor (ou map) o valor da soma dos números digitados até aquela posição. 
- Dessa forma, ao buscar a soma da subarray nums[i:j], basta fazer prefix_sum[j+1] - prefix_sum[i]. Sendo assim, o que se busca é a soma de um determinado prefixo, ou seja: alvo = prefix_sum[j+1] - prefix_sum[i] => prefix_sum[i] = prefix_sum[j+1] - alvo. Tendo isso em vista, utilizando a função find do map, é possível verificar se o valor (prefix_sum[j+1] - alvo) existe. 
- Para isso, foi-se criado o map para armazenar a soma do prefixo, sendo que {key, value} = {número, repetições{ e prefix_sum[0] = 1; O valor zero foi inserido para o caso em que uma subarray, contando da primeira posição, é formada. Duas outras variáveis são criadas, uma para armazenar a soma dos prefixos e outra para armazenar a quantidade de subarrays que resultam no alvo. 
- Um loop se inicia e, a cada iteração:
	- O número atual é lido;	
	- A soma é incrementada com o número atual;
	- Verifica-se se existe um número no map tal que o resultado seja a soma até o número atual subtraída pelo alvo; 
	- Se existir, então uma (ou mais) nova subarray é encontrada e a variável que armazena essa quantidade adiciona a quantidade de vezes que tal valor foi encontrado. 
	- Por fim, a quantidade de vezes que a soma atual aparece no map é incrementada.

## 1662 - SUBARRAY DIVISIBILITY
- A técnica utilizada consiste em utilizar dois vetores: um contem a soma do prefixo dos números (armazena, em cada posição, a soma acumulada até ele) e o outro armazena o módulo dos números do vetor dos prefixos por n. 
	- O segundo vetor existe pois os módulos possuem a seguinte propriedade: se 'a-b' for um número múltiplo de n, então 'a%n = b%n'. Isso é, se a subtração de dois números for um número múltiplo de n, então o módulo dos dois por n é igual; esses números são congruentes. 
	- Ainda sobre o segundo vetor, para tratar os casos em que o módulo resulta em um número negativo, faz-se o seguinte: 
		- No caso de 'n=5' e da existência de dois valores no vetor da soma de prefixo 3 e -2, '3 -(-2) = 5', que é múltiplo de n (5). No entanto, '3 % 5 = 3' e '-2 % 5 = -2', como os módulos são diferentes, somente a operação anterior do vetor não será o suficiente. Para tratar isso, como o módulo de um dado número n sempre será menor que n, basta somar n ao resultado final, logo: '(3 % 5) + 5 = 8' e '(-2 % 5) + 5 = 3'. O número negativo foi corrigido, no entanto, o número do módulo sempre precisa ser menor que n, então, basta aplicar o módulo novamente nesse resultado final: '((3 % 5) + 5) % 5 = 8 % 5 = 3' e '((-2 % 5) % 5) = 3 % 5 = 3'. Dessa forma, os dois módulos resultam no mesmo número, o que garante que agora a conta funcionará. Portanto, a fórmula final é: 'mod = ((prefixSum[i] % n) + n) % n'.
- Então, após fazer a leitura dos números e armazenar as somas consecutivas no vetor prefixSum, cria-se uma variável para armazenar a quantidade de sub arrays e um vetor de inteiros para armazenar a quantidade de vezes que os módulos aparecem (como os módulos sempres serão números entre 0 e n-1, uma estrutura de dados simples com n-1 posições e inicializada com 0 é o suficiente). Ou seja, dentro desse vetor, os números serão armazenados na forma modNums[módulo] = (quantidade).
- Dentro de um loop de 0 até n, cria-se uma variável auxiliar 'resto = ((prefixSum[i] % n) + n) % n'. Depois, incrementa-se a variável da quantidade de sub arrays com a quantidade de módulos existentes no vetor até o momento. Então, essa quantidade de módulos existentes é incrementada em 1. 

## 2428 - DISTINCT VALUES SUBARRAYS II
- A técnica utilizada para essa solução é a janela deslizante, que consiste na criação de dois ponteiros: um para o início da janela e o outro para o fim dela. 
- Os valores contidos dentro da janela (o intervalo) são armazenados em uma estrutura de map, sendo que key é o valor e value é a quantidade de vezes que dado valor aparece. 
- Dentro do loop para verificar as subarrays que possuem no máximo k valores distintos, o map incrementa (ou adiciona) o valor apontado pelo ponteiro da direita e verifica se o tamanho desse map é maior que o valor máximo permitido (k). 
	- Enquanto o tamanho do map for maior que o valor máximo permitido k, a janela deslizante encolhe pela esquerda, retirando os valores apontados pelo ponteiro de início do map e incrementando tal ponteiro. Isso se repete até que um valor tenha sido completamente retirado da janela. 
- Então, é feita a inserção do número de subarrays na variável responsável através da fórmula: 'qtdSubArrays = qtdSubArrays + (ptrDir - ptrEsq + 1)'. Essa operação incrementa à contagem atual a quantidade de subarrays existentes depois do último valor válido (apontado pelo ptrDir) inserido. 

## 1085 - ARRAY DIVISION
- 

## 1632 - MOVIE FESTIVAL II
- 

## 1644 - MAXIMUM SUBARRAY SUM II
- 
