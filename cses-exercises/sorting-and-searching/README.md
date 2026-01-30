# Introductory Problems

Resoluções dos exercícios introdutórios do CSES.

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
- 