# Introductory Problems

Resoluções dos exercícios introdutórios do CSES.

## Tabela de Conteúdos

| ID | Nome do Problema | Solução |
| :--- | :--- | :---: |
| 1068 | Weird Algorithm | [Código](./1068.cpp) |
| 1083 | Missing Number | [Código](./1083.cpp) |
| 1069 | Repetition | [Código](./1069.cpp) |
| 1094 | Increasing Array | [Código](./1094.cpp) |
| 1070 | Permutations | [Código](./1070.cpp) |
| 1071 | Number Spiral | [Código](./1071.cpp) |
| 1072 | Two Knights | [Código](./1072.cpp) |
| 1092 | Two Sets | [Código](./1092.cpp) |
| 1617 | Bit Strings | [Código](./1617.cpp) |
| 1618 | Trailing Zeros | [Código](./1618.cpp) |
| 1754 | Coin Piles | [Código](./1754.cpp) |
| 1755 | Palindrome Reorder | [Código](./1755.cpp) |
| 2205 | Gray Code | [Código](./2205.cpp) |
| 2165 | Tower of Hanoi | [Código](./2165.cpp) |
| 1622 | Creating Strings | [Código](./1622.cpp) |
| 1623 | Apple Division | [Código](./1623.cpp) |
| 1624 | Chessboard and Queens | [Código](./1624.cpp) |
| 3399 | Raab Game I | [Código](./3399.cpp) |
| 3419 | Mex Grid Construction | [Código](./3419.cpp) |
| 3217 | Knight Moves Grid | [Código](./3217.cpp) |
| 3311 | Grid Coloring I | [Código](./3311.cpp) |
| 2431 | Digit Queries | [Código](./2431.cpp) |
| 1743 | String Reorder | [Código](./1743.cpp) |
| 1625 | Grid Path Description | [Código](./1625.cpp) |

---

## 1068 - WEIRD ALGORITHMS
- Como o valor n dado é um inteiro positivo e poderá ser um valor até 10^6, a variável responsável por armazená-lo será um unsigned long int.
- Criação de um loop com a condição de parada para n == 1.
- Uso de um condicional que utiliza operação bitwise, pois é muito mais rápido do que as operações de divisão padrão;
    - Em binário, números pares possuem o dígito menos significativo 0, enquanto os ímpares possuem o dígito menos significativo como 1. Portanto, a operação and entre um número qualquer n e o número 1 retornará 1 se n for ímpar e 0 se n for par (X & 1 = X).
    - Se n for par, a operação bit a bit shift right 1 é realizada para fazer uma divisão por dois. 
    - Se n for ímpar, n é multiplicado por 3 e incrementado em 1. 

## 1083 - MISSING NUMBER
**(UTILIZANDO SET)**
- Como o Set não permite duplicatas e organiza os números em ordem crescente, os números digitados após n são armazenados em um conjunto Set criado.
- Depois, é feita uma contagem de 1 até n, com um condicional que compara se o número atual da contagem está dentro do Set.
    - Se o número da contagem já existir dentro do Set, a contagem prossegue normalmente.
    - Se o número da contagem não existir dentro do Set, o número referido é impresso e a contagem se encerra. 

**(UTILIZANDO A SOMA DE PROGRESSÃO ARITMÉTICA)**
- A soma de todos os números do intervalo é armazenada em uma variável do tipo long long.
- Depois, utiliza-se a fórmula da soma de progressão aritmética (n (a0 + an))/2, sendo a0 o primeiro termo (1) e an o último termo (n).
- No fim, faz a subtração da soma de PA com a soma obtida dos números fornecidos. O resultado dessa diferença é o número que não foi fornecido.

## 1069 - REPETITION
- A sequência é armazenada em uma string e duas variáveis são inicializadas com 1: uma para armazenar o valor máximo total e outra para armazenar o valor máximo da sequência atual.
- Os caracteres da sequência são percorridos um a um e comparados.
    - Se o caractere atual for igual ao caractere anterior, o valor máximo da sequência atual é incrementado.
    - Se o caractere atual for diferente do caractere anterior, o valor máximo da sequência atual recebe o valor 1.
    - A cada iteração, a variável que armazena o valor máximo total é atualizada com o maior valor obtido.

## 1094 - INCREASING ARRAY
- Após a leitura de n, que contém o número de elementos dentro da array, é feita a leitura do primeiro valor da array, armazenando-o na variável long long que salva o valor do número anterior.
- Cria-se um loop para contar de 1 até n.
    - Dentro do laço, é feita a leitura do número atual da array, armazenando em sua respectiva variável long long.
    - Depois, um bloco condicional é executado para saber se o número atual é menor que o número anterior. Se o número atual for menor que o número anterior, a variável que armazena o valor mínimo de movimentos e a que armazena o número atual são incrementadas com o valor da diferença dos números anterior e atual.
    - Após o bloco condicional, a variável responsável por armazenar o número anterior é atualizada, recebendo o valor do número atual.

## 1070 - PERMUTATIONS
- Após fazer a leitura de n, um condicional é executado para cuidar dos casos de borda em que não há solução, imprimindo, se for o caso.
- Outro condicional em bitwise é utilizado para saber se n é par ou ímpar, a fim de armazenar os maiores valores pares e ímpares menores ou iguais a n em suas respectivas variáveis (par e ímpar).
- Depois, dois loops são executados.
    - O primeiro loop imprime todos os valores ímpares de n até 1.
    - O segundo loop imprime todos os valores pares de n até 1.
- Com essa implementação, é garantido que, na sequência dos ímpares e dos pares, a diferença entre os números adjacentes é 2. Dessa forma, o único intervalo que deve ser conferido para que a diferença entre os elementos seja maior que 1 é a fronteira entre os ímpares e os pares. Como os elementos forma impressos em ordem decrescente e o grupos dos ímpares vêm antes dos pares, a diferença sempre será |(Menor Ímpar) - (Maior Par)|. O menor ímpar sempre será 1, e o maior par dependerá de n. Ou seja, a única forma dessa diferença ser igual a 1, seria se o maior par fosse 2, o que só aconteceria se n fosse 3 ou 2. Retirando esses casos de borda (n = 2 e n = 3) que não possuem solução, a implementação funciona perfeitamente.

## 1071 - NUMBER SPIRAL
- A implementação funciona separando o espiral de números em camadas. A camada corresponde ao maior valor entre a coluna (x) ou a linha (y). 
- O espiral segue o seguinte padrão: os quadrados ímpares das camadas se encontram na linha 1 (1, camada), enquanto os quadrados pares das camadas se encontram na coluna 1 (camada, 1).
- Sabendo-se a localização dos quadrados (1, camada) ou (camada, 1), fica fácil encontrar os valores aleatórios no meio do espiral (y,x).
- Basta, então, calcular o módulo da diferença entre a posição do número desejado (y,x) e a posição do quadrado da camada (1, camada) ou (camada, 1), ressaltando que a camada é o maior valor entre y e x.
- Ao obter tais diferenças no y e no x e subtraí-las do quadrado da camada, o valor da número na posição (y,x) é encontrado.  

## 1072 - TWO KNIGHTS
- Após obter a quantidade total de combinações entre as posições dos cavalos (k! / [2! * (k-2)!]), é necessário subtrair as posições de ataque entre eles. 
- Tendo-se em mente um retângulo hipotético de dimensões 3x2, que representa a área em que o cavalo pode se movimentar. 
- Em um tabuleiro de dimensões 3x3, em uma altura de 3 blocos, têm-se 1 retângulo; em uma largura de 3 blocos, têm-se 2 retângulos; multiplicando a quantidade de retângulos na largura pela quantidade de retângulos na altura, obtêm-se 2 retângulos. Como essa disposição pode também ocorrer de maneira horizontal, multiplica esse resultado por 2. Assim sendo, em um tabuleiro 3x3, é possível posicionar 4 retângulos. Dentro de cada retângulo, há duas disposições diferentes em que os cavalos poderiam se atacar, sendo assim, nesse tabuleiro, existem 8 posicionamentos de ataque entre os cavalos.
- Após o raciocínio anterior, é possível observar que tal comportamento acontece em todas as dimensões de tabuleiro:
    - 4x4:
        Altura 4 => 2 retângulos
        Largura 4 => 3 retângulos
    - 5x5: 
        Altura 5 => 3 retângulos
        Largura 5 => 4 retângulos
    - AxL:
        Altura A => A-2 retângulos
        Largura L => L-1 retângulos
- Temos, então, a fórmula para obter a quantidade de posições de ataque:
    [(A-2) * (A-1)] * 2 * 2 = [(A-2) * (A-1)] * 4 
    - Multiplica-se por 4, pois é necessário obter a quantidade total de retângulos (na horizontal e na vertical) e, depois, a quantidade total de posições de ataque dentro de cada retângulo (duas posições de ataque)
- No fim, basta subtrair a quantidade total de disposições no tabuleiro pela quantidade de posições em que os cavalos podem se atacar

## 1092 - TWO SETS
- Primeiro, para saber se um número pode ser dividido em dois sets de somas iguais, é preciso saber se a soma da progressão aritmética de 1 até n será par.
    - Se não for par, sabemos que o número não pode ser dividido, então é impresso "NO" e o programa encerra.
    - Se for par, pode ser dividido e o código prossegue.
- Depois, o valor que cada set deve ter é armazenado e um laço que percorre de n até 1 se inicia com um condicional dentro.
    - Se uma variável auxiliar, que armazena o valor total do set 1, somada com o contador do laço for menor ou igual ao valor do set, então o valor do contador é inserido dentro do set 1 e a variável auxiliar tem seu valor atualizado.
    - Se não, o valor é inserido no set 2.
- Dessa forma, os dois sets serão separados de forma que a soma de seus elementos seja igual.

## 1617 - BIT STRINGS
- Como conhecido, a quantidade de combinações diferentes de uma cadeia de n bits em binário é 2^n.
- Para tratar de tal problema com números grandes, inicializa-se a variável responsável por armazenar o resultado final com 1.
- Inicia-se um loop de 0 até n-1.
    - Dentro do loop, o resultado será multiplicado por 2 a cada iteração.
    - Após a multiplicação, o resultado será igual ao resto da divisão dele mesmo por 1000000007 para garantir que não ocorra um overflow. 

## 1618 - TRAILING ZEROS
- A quantidade de zeros que um número possui é correspondente à quantidade de fatores 2 e 5 que ele possui.
    - O fator de 2 aparece a cada 2 números (2, 4, 6, ...).
    - O fator de 5 aparece a cada 5 números (5, 10, 15, ...).
    - Portanto, o número que vai definir a quantidade de zeros será a quantidade de vezes que o fator 5 aparecer dentro dele, pois, como ele é mais difícil de aparecer do que o fator 2, ele se torna o limitante. 
- Para encontrar a quantidade de zeros, soma-se os resultados da divisão inteira de N pelas potências de 5 (5, 5^2, ...) até que o resultado de tal divisão seja zero. 
- Por exemplo: N = 25. 
    N/5 = 25/5 = 5; 5 é a quantidade de vezes que esse fator aparece no número, no entanto, 25 também pode ser dividido por 5^2, logo:
    N/5^2 = 25/25 = 1;
    N/5 + N/5^2 = 5 + 1 = 6 é a quantidade de zeros que aparecem no número 25!

## 1754 - COIN PILES
- A cada movimento, 2 moedas são retiradas de uma pilha e 1 moeda é retirada da outra. Isso quer dizer que, a cada movimento, 3 moedas são retiradas no total.
- Para saber se duas pilhas podem ser esvaziadas, basta somar a quantidade de moedas totais das duas pilhas e verificar se esse valor é divisível por 3.
    - Se for divisível, então as pilhas podem ser esvaziadas.
    - Se não for divisível, então as pilhas não podem ser esvaziadas.
- Outra coisa é saber se a proporção entre as moedas garante que ambas as pilhas poderão ser esvaziadas. Por exemplo: se uma pilha tiver 14 moedas e a outra tiver 1, embora o número total de moedas seja divisível por 3, ambas não poderão ser esvaziadas. 
- Como a proporção de retirada das moedas das pilhas é 1/2 (tira uma moeda de uma pilha e duas moedas da outra), uma pilha nunca poderá ter um valor menor do que a metade da outra.
    - Se uma pilha for menor do que a metade da outra, as pilhas não podem ser esvaziadas.
    - Se uma pilha for maior ou igual do que a metade da outra, as pilhas podem ser esvaziadas.

## 1755 - PALINDROME REORDER
- O primeiro passo do algoritmo é criar um array de inteiro de 26 posições. Cada posição correponde a uma das letras do alfabeto (alfabeto[0] -> A, alfabeto[1] -> B, e assim por diante) e cada valor dentro do vetor correponde a quantidade de vezes que tais letras apareceram dentro da string passada. Essa contagem é feita através de um loop que percorre toda a string e incrementa a array.
- O segundo passo é contar quantas letras estão em quantidades ímpares na string.
- Para saber se uma string é palíndroma, ela deve seguir duas condições: 
    - Se o número de caracteres da string for ímpar, então DEVE haver UMA letra que se repete um número ímpar de vezes.
    - Se o número de caracteres da string for par, então NÃO DEVE haver NENHUMA letra que se repete um número ímpar de vezes.
- Após a verificação se a string é palíndroma, é feita a impressão dos caracteres de maneira a formar uma palavra palíndroma. 
- Primeiro é impressa a metade esquerda da string, em ordem alfabética. Depois, é impresso o meio da string, se houver, isto é, se a string for ímpar. Por fim, é impressa a metade direita da string, mas começando pela última letra do alfabeto, indo de 'Z' a 'A'.

## 2205 - GRAY CODE
- Ao fazer a tabela verdade entre o binário e o gray, é possível visualizar que o código gray é o resultado de um XOR entre dois dígitos binários, enquanto o dígito mais significativo permanece o mesmo.
    - Por exemplo:
    - 5 em binário é 101. Para descobrir o LSB em gray, pegamos os LSB em binário e o dígito anterior a ele, ou seja, 1 e 0, e aplicamos a porta XOR: 1 ^ 0 = 1. Descobrimos o LSB em gray. 
    - Para descobrir o dígito do meio em gray, pegamos o dígito do meio em binário e o anterior a ele, ou seja, 0 e 1, e aplicamos a porta XOR: 0 ^1 = 1. Descobrimos o dígito do meio em gray.
    - Por fim, o MSB não muda, então 5, que em binário é 101, em gray é 111
- No código, tal algoritmo pode ser implementado da seguinte forma: grayCode = binário ^ (binário >> 1). 
    - Isso faz exatamente os passos descritos anteriormente. Uma porta XOR entre o dígito binário e o seu dígito anterior, que é calculado em (binário >> 1). 

## 2165 - TOWER OF HANOI
- O primeiro passo é observar o padrão da quantidade mínima de movimentos necessários para mover as peças para a última torre: 
    - 1 peça  -> 1 movimento
    - 2 peças -> 3 movimentos
    - 3 peças -> 7 movimentos 
    - 4 peças -> 15 movimentos
    - 5 peças -> 31 movimentos
- Nota-se que os movimentos são 2^n - 1, sendo n a quantidade de peças. 
- Após isso, precisa-se de um vetor para armazenar em qual torre cada uma das n peças está; como todas as peças iniciam na torre 1, a posição de todas, no início, é 1.
- Para saber qual peça se move, é preciso observar outro padrão: 
        - 2 peças -> 3 movimentos (discos que se movem)
    - Movimento 1 (01) - 1 2  -> disco 1 - 0 zeros no final
    - Movimento 2 (10) - 1 3  -> disco 2 - 1 zero no final
    - Movimento 3 (11) - 2 3  -> disco 1 - 0 zeros no final
- Atentando-se ao número binário do movimento atual, fica perceptível que o disco que se move é representado pela quantidade de zeros que tem antes do primeiro bit em 1 do movimento + 1. Por exemplo:
    - No Movimento 1 (binário 01), o disco 1 se move; O binário 01 não tem nenhum zero antes do primeiro bit 1. Então: 0 (quantidade de zeros) + 1 = 1, que é o disco que se move.
    - No movimento 2 (binário 10), o disco 2 se move; O binário 10 tem 1 zero antes do primeiro bit 1. Então: 1 (quantidade de zeros) + 1 = 2, que é o disco que se move.
- Sabendo o disco que se move e sua posição, tem-se, então a primeira impressão do algoritmo.
- Para a última etapa, outro comportamento precisa ser observado: 
        - 3 discos - 7 movimentos
    - Movimento 1 - 1 3 -> disco 1
    - Movimento 2 - 1 2 -> disco 2 
    - Movimento 3 - 3 2 -> disco 1 
        - 2 discos -> 3 movimentos
    - Movimento 1 - 1 2 -> disco 1 
    - Movimento 2 - 1 3 -> disco 2 
    - Movimento 3 - 2 3 -> disco 1
- Se o número total de discos e o número do disco atual forem de paridades iguais, então ele vai andar duas casas. 
- Se o número total de discos e o número do disco atual forem de paridades opostas, então o disco vai andar uma casa. 
- Toda vez que o número de casas for superior ao número de torres, ele dá a volta. Por exemplo:
    - Com 3 discos, no movimento 3, o disco deve andar duas casas, mas ele está na última. 3 + 2 = 5. Mas, ao obter o resto da divisão por 3 desse número, obtemos a casa onde ele parou: 5 % 3 = 2.
- Com isso, tem-se a segunda impressão do movimento. 
- Tal algoritmo se repete dentro de um laço até que todos os movimentos sejam representados.

## 1622 - CREATING STRINGS
- A quantidade de strings que serão geradas é um problema de permutação com repetição: n!/(p1! * p2! * p3! * ...); Sendo n a quantidade de letras no total e p1, p2, p3, ... a quantidade de letras únicas que se repetem. Por exemplo:
    - Na string aabac, n = 5, p1 = 3; então, o número de strings que serão geradas é 5! / 3! = 5 * 4 * 3! / 3! = 20.
    - Na string abab, n = 4, p1 = 2 e p2 = 2; então, o número de strings que serão geradas é 4! / (2! * 2!) = 4 * 3 * 2! / (2! * 2!) = 3 * 2 = 6.
- Para imprimir as letras, faz-se uso da biblioteca algorithms. 
    - Essa biblioteca possui uma função chamada 'next_permutation()', que altera a string inserida para a próxima string seguindo ordem lexicográfica e retorna verdadeiro se existir e falso se não existir. 
- A princípio, então, é preciso reorganizar a string original para que ela forme a primeira posição em ordem lexicográfica. Por exemplo:
    - A string aabac é reorganizada, formando aaabc. Assim que ela for inserida na função, ela passará a ser aaacb e assim por diante. 

## 1623 - APPLE DIVISION
- O número de maças e o array contendo-as com seus respectivos pesos foram declarados como variáveis globais, a fim de facilitar o acesso a tais campos.
- Para encontrar o valor mínimo, foi-se utilizado uma função recursiva que funciona da seguinte forma:
    - Sua lista de parâmetros contém: um inteiro i - que funciona como um contador até n (total de maçãs) - e dois long long (grupo1 e grupo2) - que armazenam o peso das maças inseridas no grupo 1 e no grupo 2, respectivamente.
    - Seu caso base é quando i = n, ou seja, quando a iteração atual i chega no número total de maçãs. Ao atingir tal valor, a função retorna o valor absoluto da subtração entre o grupo 1 e o grupo 2 das maçãs. 
    - O corpo da recursão retorna o valor mínimo entre duas opções: 
        1 - Se a maçã na posição i for adicionada ao grupo 1
        2 - Se a maçã na posição i for adicionada ao grupo 2
    - Isso funciona como uma árvore de escolhas; a função recursiva abre ramificações entre todas as opções até encontrar a menor entre elas. 

## 1624 - CHESSBOARD AND QUEENS
- A função main desse código possui somente um loop aninhado para ler todo o tabuleiro. Uma matriz de inteiros definida como variável global, representando o tabuleiro, é inicializada com zero e tem seu valor alterado para "-1" toda vez que tem uma casa com impedimento ( * ). Depois disso, o número de maneiras é impresso e a main finaliza. (a matriz que representa o tabuleiro recebe o valor 0 se estiver com a casa vaga, 1 se uma rainha estiver lá e -1 se a casa foi bloqueada).
- A função que faz todo o processo de contagem utiliza o algoritmo de backtracking, que consiste em tentar um caminho para resolver um problema, se falhar, retrocede e tenta no próximo. 
- A princípio, foram declaradas 4 variáveis globais, além da mencionada anteriormente:
    - Um inteiro responsável por armazenar o número de maneiras diferentes que as rainhas podem ser posicionadas;
    - Um bool para representar quais colunas podem ser atacadas por rainhas;
    - Um bool para representar quais diagonais principais (da esquerda cima para direita baixo, ou direita baixo para esquerda cima) podem ser atacadas por rainhas;
    - Um bool para representar quais diagonais secundárias podem ser atacadas por rainhas;
- A função possui, como assinatura, somente um inteiro que representa a linha atual. A cada chamada recursiva, a linha é incrementada, pois as rainhas não podem permanecer na mesma linha, coluna ou diagonal sem se ameaçarem.
- O caso base da função é quando o número de linhas chega a 8, o que significa que todas as rainhas foram postas em seus devidos lugares; então, a função incrementa a variável do número de maneiras e a retorna.
- Após o caso base, no corpo da função, um laço faz uma iteração representando as colunas e um condicional é executado:
    - A cada iteração, se não houver outra rainha na respectiva coluna, a casa estiver vazia e não houver nenhuma rainha nas diagonais, então uma rainha é posta nessa casa. 
    - Após a inserção da rainha, o código faz a chamada recursiva avançando uma linha.
    - Após a chamada recursiva, quando a função retornar, ela retira a rainha desse lugar, liberando as variáveis, e vai para a próxima coluna.
- Ao fim do laço, a função retorna o número de formas diferentes em que as rainhas podem ser posicionadas

## 3399 - RAAB GAME I
- Após a leitura dos testes, dentro do laço para lê-los, um condicional é executado para garantir que existe uma solução para o resultado da jogada inserido na entrada. 
    - Se a soma dos vencedores for maior que o número total de cartas, ou se somente um dos vencedores for igual a zero, não há solução. 
- Se houver solução, o primeiro jogador sempre jogará as cartas na ordem 1 até n.
- A jogada para o segundo jogador é feita de outra forma:
    - Se houver algum empate, um loop percorrerá de 1 até o número de empates, para que as primeiras cartas dos jogadores sejam iguais.
    - Outro loop fará a iteração de n-b+1 até n, o que representa as últimas cartas do baralho (as de maiores valores)
    - Por último, um loop imprimirá da carta posterior à carta dos empates + 1 até n-b, que é uma carta antes da primeira de maior valor do loop anterior.

## 3419 - MEX GRID CONSTRUCTION
- A sacada desse é notar o padrão da sequência mostrada no exemplo. Na linha 3, por exemplo, tem-se, escrevendo a posição de cada número na forma, (i, j) = (linha, coluna):
3 (3,0), em binário => 011 (011,000)
2 (3,1), em binário => 010 (011,001)
1 (3,2), em binário => 001 (011,010)
0 (3,3), em binário => 000 (011,011)
7 (3,4), em binário => 111 (011,100)
- Comparando o número da sequência com i e j, percebe-se que existe uma operação bitwise entre as linhas e as colunas; 
011 ? 000 = 011
011 ? 001 = 010
011 ? 010 = 001
- O operador capaz de realizar tais operações é o ou exclusivo. Aplicando-o em um loop aninhado, tem-se a construção da grade desejada.

## 3217 - KNIGHT MOVES GRID
- Para saber a distância de todas as casas até a casa (0,0), calcula-se o contrário: a distância da casa (0,0) até todas as outras.
- Uma matriz e dois arrays são criados:
    - Uma matriz dist responsável por armazenar a distância de todas as casas até a (0,0). Ela é inicializada com todos os seus valores em -1, para explicitar que sua distância ainda não foi calculada.
    - Dois arrays dx e dy, contendo todas as combinações de "pulos" que o cavalo pode fazer: um para a direita e dois para cima, um para a direita e dois para baixo, e etc (considerando para cima positivo e para a direita positivo).
- Uma fila contendo um par de dois inteiros é criada para armazenar as coordenadas em (x,y) das distâncias na ordem correta, (a coordenada armazenada primeiro será a primeira a sair). Quando uma distância for atualizada, sua coordenada é inserida no último lugar da fila.
- A primeira distância é a da posição (0,0), que é 0. Tais coordenadas são inseridas na fila e se inicia um loop que repete enquanto a fila não estiver vazia. 
- Dentro do loop, são coletadas as coordenadas x e y do primeiro item na fila, em seguida, esse item é removido e um laço de 0 a 7 se inicia. 
    - Nele, as coordenadas atuais são somadas com todas as combinações possíveis das coordenadas dos arrays dx e dy (que representam os movimentos do cavalo) e salvas em novas variáveis nx e ny. 
    - Após essa soma, verifica-se se as novas coordenadas continuam dentro das limitações do tabuleiro nxn e se a matriz das distâncias nessa posição está vazia.
        - Se as condições forem aceitas, a distância da nova coordenada recebe o valor da distância antiga + 1 e, então, o par de coordenada é inserido na fila.
- No fim, todas as distâncias são impressas no formato requisitado.

## 3311 - GRID COLORING I
- Uma matriz de char para a grade de cores é criada; Um array de char para as 4 cores disponíveis também é criado na ordem A, B, C e D.
- A solução é feita durante a leitura dos caracteres da entrada, que são salvos em uma variável auxiliar. Após ler um caractere, um loop percorre a array de cores.
    - O loop percorre todas as cores e as compara com os vizinhos e com a cor atual, assim que encontrar uma cor diferente de todos esses, a coloca na grade. 
- Se o loop finaliza sem encontrar nenhuma cor, imprime que é impossível e finaliza o programa.
- Ao fim da leitura, imprime as cores alteradas e finaliza o programa.

## 2431 - DIGIT QUERIES
- Para solucionar esse problema, separa-se os grupos de número a depender da quantidade de dígitos que possuem.
- Números de 1 dígito (1-9):
    - Qtd números: 9
    - Qtd caracteres: 9 * 1 = 9
- Números de 2 dígitos (10-99):
    - Qtd números: 90
    - Qtd caracteres: 90 * 2 = 180
- Números de 3 dígitos (100-999):
    - Qtd números: 900
    - Qtd caracteres: 900 * 3 = 2700
- Números de N dígitos:
    - Qtd números: 9 * 10^(n-1)
    - Qtd caracteres: 9 * 10^(n-1) * n
- Assim, tem-se a fórmula para obter a quantidade de número e de caracteres dos números de n dígitos.
- Para encontrar o número na posição k, basta subtrair sucessivamente a posição k pela quantidade de caracteres dos blocos. Por exemplo:
    - k = 200
    - A verificação "k > qtdCarac" será feita enquanto for verdadeira, e a qtdCarac irá aumentando sucessivamente ao decorrer dos blocos dos dígitos
    - 200 > 9 ?
        k = k - 9 = 200 - 9 = 191
    - 191 > 180 ?
        k = k - 180 = 191 - 180 = 11
    - 11 > 2700 ?
        Como k é menor que a quantidade de caracteres, essa subtração não será feita e o loop cessará.
- Como o computador utiliza 0 como o início e o exercício utiliza o 1, decrementa-se k em 1 para fazer essa correção.
- O número de k remanescente indica as posições após o primeiro número do bloco de N dígitos. Seguindo o exemplo anterior:
    - k = 11 - 1 = 10; O número na posição 10 se encontra no bloco de 3 dígitos, pois o loop anterior removeu os números dos blocos de 1 e 2 dígitos, sobrando o 3. 
    - O 1º número do bloco de 3 dígitos é o 100, que possui as posições 0, 1 e 2; o 2º é o 101, nas posições 3, 4 e 5; o 3º é 102, nas posições 6, 7 e 8; o 4ª é 103, nas posições 9, 10 e 11. Como a posição 10 corresponde ao 0 no número 103, esse é o valor desejado.
- Para chegar ao caractere na posição desejada, é preciso saber qual o número inteiro em que ele se encontra. 
    - Calculando-se k dividido pelo número de dígitos, obtêm-se a quantidade de números inteiros após o primeiro número: 
        - k = 10;
        - k/n = 10/3 = 3
        - O primeiro número do bloco de 3 dígitos é 100. 100 + 3 = 103.
    - Tendo o número em que a posição desejada se encontra, basta descobrir sua posição através do resto da divisão:
        - k = 10;
        - k % n = 10 % 3 = 1
        - O caractere na posição 1 do número 103 é: 0 -> 1, 1 -> 0, 2 -> 3; Ou seja, o caractere 0, como mostrado manualmente alguns passos acima.

## 1743 - STRING REORDER
- O primeiro passo do algoritmo é armazenar a quantidade de vezes que cada letra da string da entrada se repete em uma array de 26 posições que representa o alfabeto. Cria-se, também, uma string nova vazia com o mesmo tamanho daquela inserida na entrada.
- Depois, um loop se repete um numero n de vezes (o tamanho da string) para preencher todos as letras na nova string. 
    - Dentro do loop, se inicia a primeira iteração da array do alfabeto para encontrar a letra urgente; A letra urgente é aquela que está no limite: se ela não for inserida agora, não terá espaço na string para inseri-la sem ser de maneira adjacente. Se qualquer letra se repetir mais do que um certo limite (sendo maior do que a metade do total de letras ou do que a metade das letras restantes até o momento). Ao encontrar uma letra que esteja no limite e que seja válida (não tenha o caractere anterior igual ao atual), essa letra é inserida na nova string.
    - Ainda dentro do loop, se não houver nenhuma letra urgente, uma outra iteração da array do alfabeto se inicia. Ao encontrar a primeira letra válida (diferente da letra inserida uma posição atrás), ela é inserida na nova string.

## 1625 - GRID PATH DESCRIPTION
- Foi-se criado várias variáveis globais para evitar criar muitos parâmetros na função recursiva criada. A string "descricao" que armazena a entrada; a matriz de bool "visitados" 9x9 que armazena se um local já foi percorrido ou não; inteiro "caminhosEncontrados"; duas arrays "dc" e "dl" e um array char "dir", todos com 4 posições para descrever se o passo tomado foi à direita, esquerda, cima ou baixo. 
- A princípio, dentro da main, inicializa-se as fronteiras (linhas e colunas 0 e 8) da matriz visitados como verdadeiro. Essa técnica é chamada de "sentinela"; as bordas da matriz já sinalizam que aquele local está tomado, então não será preciso verificar se as linhas e as colunas permanecem dentro das limitações da grade 7x7.
- A função "solução" foi criada com os parâmetros inteiros: "passos" (para contar quantos passos foram dados, sendo o limite 48), "l" (linhas) e "c" (colunas).
- O caso base da recursão é se o quadrado final, localizado em (7,1), foi alcançado.
    - Se sim e se a quantidade de passos dados foi exatamente 48, então um caminho foi encontrado. Após a incrementação de "caminhosEncontrados" (ou não), a função retorna para onde foi chamada.
- Para excluir caminhos inválidos, é feita a seguinte verificação: se existe um caminho bloqueado à frente e atrás, mas os lados estão livres, então a função retorna. Isso porque, se não tem como prosseguir e nem retornar, mas os caminhos à direita e à esquerda estão bloqueados, então, independente do passo tomado, o resultado será um beco sem saída. 
- O quadrado atual é marcado como ocupado e outra verificação é feita.
- Se a letra atual da string "descricao" for '?', a função fará uma recursão para o próximo passo para todos os caminhos disponíveis (direita, esquerda, cima e baixo).
- Se a letra atual da string "descricao" for diferente de '?', então ela é uma letra dada de fato. Nesse caso, um loop percorrerá para encontrar a direção da letra e fará a recursão para o próximo passo se o caminho estiver disponível. 
- Ao retorno das recursões, a função desocupa o quadrado atual e retorna novamente.