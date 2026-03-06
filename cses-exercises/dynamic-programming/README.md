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
| 1746 | Book Shop | [Código](./1746.cpp) |
| 2413 | Array Description | [Código](./2413.cpp) |
| 1639 | Counting Towers | [Código](./1639.cpp) |
| 3403 | Edit Distance | [Código](./3403.cpp) |
| 1744 | Longest Common Subsequence | [Código](./1744.cpp) |
| 3359 | Rectangle Cutting | [Código](./3359.cpp) |

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
- O vetor `dp[i][j]` armazena a quantidade de caminhos válidos para chegar até aquele quadrado. Toda vez que uma coordenada [i][j] for uma armadilha, aquele quadrado é zero, pois aquele quadrado não pode ser pisado. 
- Para cada coordenada [i][j], de 1 até n, é feito `dp[i][j] += dp[i-1][j] + dp[i][j-1]`. Como os únicos passos possibilitados são para a direita ou para a esquerda, então, para chegar em uma coordenada `[i][j]`, com certeza veio da esquerda `[i][j-1]` ou de cima `[i-1][j]`.
- O caso base é `dp[1][1] = 1`, se o primeiro quadrado não for uma armadilha, caso contrário, `dp[1][1] = 0` e não tem caminhos possíveis.

## 1746 - BOOK SHOP
- O objetivo é contar a quantidade máxima de páginas que posso obter com um orçamento x em uma loja com n livros, em que cada livro possui um valor e uma quantidade de páginas.
- O vetor `dp[i][j]` armazena a quantidade de páginas acumuladas do livro 1 até o i com um orçamento máximo igual a j. 
- Para cada `dp[i][j]`, dp seleciona o maior valor (a maior quantidade de páginas) entre a quantidade no livro anterior com o orçamento atual `dp[i-1][j]` e o livro anterior se o livro atual for comprado `dp[i-1][j-h[i]] + s[i]`; ou seja: `dp[i][j] = max(dp[i-1][j-h[i]] + s[i], dp[i-1][j]) = max(comprar, não comprar)`.

## 2413 - ARRAY DESCRIPTION
- 

## 1639 - COUNTING TOWERS
- 

## 3403 - EDIT DISTANCE
- 

## 1744 - LONGEST COMMUN SUBSEQUENCE
- 

## 3359 - RECTANGLE CUTTING
- 