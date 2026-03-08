# Dynamic Programming

Resoluções dos exercícios de programação dinâmica do CSES.

## Tabela de Conteúdos

| ID | Nome do Problema | Solução |
| :--- | :--- | :---: |
| 1633 | Dice Combinations | [Código](./1633.cpp) |
| 1634 | Minimizing Coins | [Código](./1634.cpp) |
| 1635 | Coin Combinations I | [Código](./1635.cpp) |
| 1636 | Coin Combinations II | [Código](./1636.cpp) |
| 1637 | Removing Digits | [Código](./1637.cpp) |
| 1638 | Grid Paths I | [Código](./1638.cpp) |
| 1158 | Book Shop | [Código](./1158.cpp) |
| 1746 | Array Description | [Código](./1746.cpp) |
| 2413 | Counting Towers | [Código](./2413.cpp) |
| 1639 | Edit Distance | [Código](./1639.cpp) |
| 3403 | Longest Common Subsequence | [Código](./3403.cpp) |
| 1744 | Rectangle Cutting | [Código](./1744.cpp) |

---

## 1633 - DICE COMBINATIONS
- A técnica utilizada nesse exercício consiste em utilizar um vetor dp para armazenar, em cada posição, o número de combinações de dados necessário para obter tal valor e uma janela deslizante para ter controle de quais valores anteriores se enquadram na soma do número atual.
- A princípio, percebe-se o padrão que ocorre nos valores iniciais das combinações dos dados:
	- 0: 1 () - (a única maneira de não obter nenhum valor é jogando nenhum dado)
	- 1: 1 (1)
	- 2: 2 (1+1, 2)
	- 3: 4 (1+1+1, 1+2, 2+1, 3)
	- 4: 8 (1+1+1+1, 1+1+2, 1+2+1, 1+3, 2+1+1, 2+2, 3+1, 4)
- Com esses números, é possível notar que a quantidade de combinações que um número x possui é a soma de todos os valores anteriores. Ou seja, `dp[4] = dp[3]+dp[2]+dp[1]+dp[0] => 8 = 4 + 2 + 1 + 1`.
- A partir disso, convém verificar números um pouco maiores. `dp[7] = dp[6]+dp[5]+dp[4]+dp[3]+dp[2]+dp[1]+dp[0]` ? Vale atentar-se ao seguinte raciocínio: o dado possui números do 1 ao 6, somente. O que quer dizer que o 'pulo' máximo que os números podem dar, entre eles, é de 6 dígitos. Ou seja, `dp[7] = dp[6]+dp[5]+dp[4]+dp[3]+dp[2]+dp[1]`. Da mesma forma, para `dp[8] = dp[7]+dp[6]+dp[5]+dp[4]+dp[3]+dp[2]`. Isso quer dizer que, para um dado número x, o número de combinações de dados existentes que resultam nele é a soma dos números das combinações dos 6 valores anteriores a x.
- Com isso, basta fazer o controle da janela. A janela só subtrai uma combinação quando o número é maior que 6; não existe motivo para remover nenhum elemento antes disso, já que o valor máximo da janela é 6. 
- Por fim, o valor de dp para o número atual é atualizado para o valor da janela; A janela, então, incrementa o valor da dp atualizada ao seu valor anterior. 

## 1634 - MINIMIZING COINS
- Essa solução armazena as moedas disponíveis em um vetor ordenado e a quantidade mínima de moedas para todos os valores de 0 até x em um vetor chamado dp; cada posição desse vetor possui o número de moedas mínimas para chegar até tal número, se não é possível chegar ao número, então o valor da posição é -1. 
- Para preencher o vetor dp, segue-se o raciocínio: 
	- Para posição 0, a única maneira de obter tal valor, dado que as moedas possuem somente valores positivos, é não pegando nenhuma moeda; Logo, `dp[0] = 0`.
	- A partir dessa posição, todas as outras terão ou um valor positivo ou o valor -1 (quando não é possível chegar àquele número). 
	- Tendo as moedas {1,5,7} e o alvo 11, a primeira posição depois do zero (1) só tem uma escolha: a moeda de valor 1. Logo, `dp[1] = 1`. 
	- A posição 2 também tem somente uma escolha: pegar duas moedas de valor 1. Logo, `dp[2] = 2`. E assim sucessivamente, `dp[3] = 3` e `dp[4] = 4`.
	- A partir da posição 5, isso muda: ela passa a ter duas escolhas: cinco moedas de 1 ou uma moeda de 5, ou seja, `dp[5] = dp[5-1] + 1 = 4 + 1 = 5` ou `dp[5] = dp[5-5] + 1 = dp[0] + 1 = 0 + 1 = 1`. Como a busca é para a menor quantidade de moedas possíveis, `dp[5] = dp[0] + 1`.
	- Essencialmente, o que está sendo feito é a seleção do menor valor entre `dp[i-moedas]`, sendo `i` a posição atual, e `moedas` sendo uma representação de todas as moedas válidas (aquelas que possuem valor maior do que a posição atual `moeda > i`). 

## 1635 - COIN COMBINATIONS I
- O objetivo é calcular o número de maneiras diferentes que um conjunto de moedas pode ser permutado para produzir uma soma x. 
- O vetor `dp[i]` armazena a quantidade de combinações possíveis para alcançar a soma i. 
- Para cada valor i, acumula-se as combinações dos estados anteriores somando o valor de cada moeda válida através de `dp[i] = dp[i] + dp[i - moeda]`.
- O caso base é `dp[0] = 1`, pois existe somente uma maneira de formar a soma 0: não selecionando nenhuma moeda. 

## 1636 - COIN COMBINATIONS II
- O objetivo é calcular o número de maneiras diferentes e ordenadas que um conjunto de moedas pode produzir uma soma x. 
- O vetor `dp[i]` armazena a quantidade de combinações possíveis para alcançar a soma i.
- Para cada moeda, itera-se sobre todos os valores válidos e atualiza-os com `dp[i] = dp[i] + dp[i - moeda]`. Dessa forma, as permutações entre os valores não são contadas. 

## 1637 - REMOVING DIGITS
- O objetivo é contar a menor quantidade de passos possíveis para zerar um número n, subtraindo, consecutivamente, o maior dígito dele mesmo.
- O vetor `dp[i]` armazena a quantidade de passos possíveis para zerar o número i.
- Para cada número i, de 1 até n, obtêm-se o maior dígito dele e atribui `dp[i] = dp[i - maiorDigito] + 1`. Isso porque, a quantidade de passos necessários para chegar até o número i é igual a quantidade de passos dados para chegar o seu anterior `i - maiorDigito` com a adição de um passo (aquele dado para chegar até o número `i - maiorDigito`).
- O caso base é `dp[0] = 0`, pois não existe nenhum passo necessário para zerar o número 0.

## 1638 - GRID PATHS I
- O objetivo é contar a quantidade de caminhos que podem ser feitos do primeiro quadrado até o último em uma grade evitando as armadilhas.
- A matriz `dp[i][j]` armazena a quantidade de caminhos válidos para chegar até aquele quadrado. Toda vez que uma coordenada [i][j] for uma armadilha, aquele quadrado é zero, pois aquele quadrado não pode ser pisado. 
- Para cada coordenada [i][j], de 1 até n, é feito `dp[i][j] += dp[i-1][j] + dp[i][j-1]`. Como os únicos passos possibilitados são para a direita ou para a esquerda, então, para chegar em uma coordenada `[i][j]`, com certeza veio da esquerda `[i][j-1]` ou de cima `[i-1][j]`.
- O caso base é `dp[1][1] = 1`, se o primeiro quadrado não for uma armadilha, caso contrário, `dp[1][1] = 0` e não tem caminhos possíveis.

## 1158 - BOOK SHOP
- O objetivo é contar a quantidade máxima de páginas que posso obter com um orçamento x em uma loja com n livros, em que cada livro possui um valor e uma quantidade de páginas.
- A matriz `dp[i][j]` armazena a quantidade de páginas acumuladas do livro 1 até o i com um orçamento máximo igual a j. 
- Para cada `dp[i][j]`, dp seleciona o maior valor (a maior quantidade de páginas) entre a quantidade no livro anterior com o orçamento atual `dp[i-1][j]` e o livro anterior se o livro atual for comprado `dp[i-1][j-h[i]] + s[i]`; ou seja: `dp[i][j] = max(dp[i-1][j-h[i]] + s[i], dp[i-1][j]) = max(comprar, não comprar)`.

## 1746 - ARRAY DESCRIPTION
- O objetivo é contar a quantidade de arrays de tamanho n que podem ser criadas (com valores entre 1 e m) em que a diferença absoluta de dois valores adjacentes seja, no máximo, 1. Entradas com 0 indicam posições onde o número é desconhecido e pode ser escolhido.
- A matriz `dp[i][j]` armazena a quantidade de arrays válidos que podem ser criadas de tamanho `i`, de modo que o i-ésimo elemento termine sendo exatamente igual ao valor `j`.
- Para cada `dp[i][j]`, o número de maneiras é a soma das possibilidades do elemento anterior ter sido `j-1`, `j`, ou `j+1`, garantindo que a diferença absoluta não exceda 1; ou seja, `dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])`. Se o número na posição atual `i` já vier fixado (diferente de 0), somente a mudança para aquele valor é calculada. 

## 2413 - COUNTING TOWERS
- O objetivo é contar a quantidade de maneiras possíveis de construir uma torre de largura 2 e altura n utilizando blocos de diferentes proporções.
- A matriz dp[i][estado] armazena a quantidade de formas de preencher a torre até a altura i. O estado `JUNTOS` (0) significa que o bloco do i-ésimo andar é formado por um único bloco de largura 2. O estado `SEPARADOS` (1) significa que o bloco do i-ésimo andar é formado por dois blocos de largura 1 cada. 
- Para cada andar, os cálculos ocorrem baseados em como pode-se estender os blocos do andar de baixo:
	- Para `dp[i][JUNTOS]`: pode-se estender as paredes, mantendo-os `JUNTOS`; pode-se estender as paredes e fechar o andar de baixo, mantendo-os `JUNTOS`; e pode-se fechar o andar de baixo, estender as paredes laterais E a do meio, fazendo-os `SEPARADOS`; Ou seja: duas maneiras de fazê-los `JUNTOS` e uma maneira de fazê-los `SEPARADOS`, sendo: `dp[i][JUNTOS] = (dp[i-1][JUNTOS]*2 + dp[i-1][SEPARADOS])`.
	- Para `dp[i][SEPARADOS]`: pode-se estender todas as paredes, mantendo-os `SEPARADOS`; pode-se estender todas as parede e fechar o andar de baixo, mantendo-os `SEPARADOS`; pode-se estender todas as paredes e fechar o andar de baixo de somente o lado direito (+1 `SEPARADOS`) ou esquerdo (+1 `SEPARADOS`); pode-se fechar o andar de baixo e subir somente as paredes laterais, fazendo-os `JUNTOS`. Ou seja: quatro maneiras de fazê-los `SEPARADOS` e uma maneira de fazê-los `JUNTOS`, sendo: `dp[i][SEPARADOS] = (dp[i-1][SEPARADOS]*4 + dp[i-1][JUNTOS])`.

## 1639 - EDIT DISTANCE
- O objetivo é encontrar a quantidade mínima de operações (inserção, remoção ou substituição de um caractere) necessárias para transformar uma string a, de tamanho n, em uma string b, de tamanho m.
- A matriz `dp[i][j]` armazena o custo mínimo para transformar o prefixo de tamanho `i` da string a no prefixo de tamanho `j` da string b. 
- Para cada `dp[i][j]`, é feito a escolha entre o menor custo entre três opções: remover o caractere atual de a, inserir o caractere atual de b, ou modificar (que pode custar +1, se a[i] != b[j], ou 0, se a[i] == b[i]). Ou seja: `dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + a[i] != b[j])`.
- Os casos bases são `dp[i][0] = i` e `dp[0][j] = j`.

## 3403 - LONGEST COMMON SUBSEQUENCE
- O objetivo é encontrar o tamanho da maior subsequência comum entre dois arrays de tamanho n e m, depois imprimir os elementos que formam essa subsequência.
- A matriz `dp[i][j]` armazena o comprimento máximo da subsequência comum considerando o prefixo de tamanho i do primeiro array e o prefixo de tamanho j do segundo array. 
- Para cada `dp[i][j]`, se o número na posição i do primeiro array for igual ao número na posição j do segundo array, a subsequência cresce e o valor passa a ser `dp[i][j] = dp[i-1][j-1] + 1`. Se forem diferentes, dp pega o maior resultado ignorando o elemento atual de um dos dois arrays: `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`. 
- Depois de preencher a tabela, o código faz o caminho reverso a partir de `dp[n][m]` para recuperar os números. 

## 1744 - RECTANGLE CUTTING
- O objetivo é encontrar o número mínimo de cortes necessários para dividir um retângulo de dimensões `a x b` em quadrados. 
- A matriz `dp[i][j]` armazena a quantidade mínima de cortes exigida para processar um retângulo de tamanho `i x j`. 
- Para cada estado `dp[i][j]`, o algoritmo testa todas as posições possíveis para um corte horizontal (dividindo a altura i nas partes k e i-k) e para um corte vertical (dividindo o comprimento j nas partes k e j-k). O valor armazenado é o menor custo entre todas essas operações somado ao custo do corte atual, ou seja: `dp[i][j] = min(dp[k][j] + dp[i-k][j], dp[i][k] + dp[i][j-k]) + 1`.
- Os casos base `dp[i][1] = i-1` e `dp[1][j] = j-1` representa o cenário onde uma das dimensões é 1, exigindo que o restante seja fatiado em pequenos quadrados de 1x1. Quando a área já é um quadrado `i == j`, a matriz já inicializa com o custo igual a 0. 