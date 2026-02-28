# Dynamic Programming

Resoluções dos exercícios de programação dinâmica do CSES.

## Tabela de Conteúdos

| ID | Nome do Problema | Solução |
| :--- | :--- | :---: |
| 1633 | Dice Combinations | [Código](./1633.cpp) |
| 1634 | Minimizing Coins | [Código](./1634.cpp) |

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

