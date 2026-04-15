# Graph Algorithms

Resoluções dos exercícios de algoritmos de grafos do CSES.

## Tabela de Conteúdos

| ID | Nome do Problema | Solução |
| :--- | :--- | :---: |
| 1192 | Counting Rooms | [Código](./1192.cpp) |
| 1193 | Labyrinth | [Código](./1193.cpp) |
| 1666 | Building Roads | [Código](./1666.cpp) |
| 1667 | Message Route | [Código](./1667.cpp) |
| 1668 | Building Teams | [Código](./1668.cpp) |
| 1669 | Round Trip | [Código](./1669.cpp) |
| 1194 | Monsters | [Código](./1194.cpp) |
| 1671 | Shortest Routes I | [Código](./1671.cpp) |
| 1672 | Shortest Routes II | [Código](./1672.cpp) |
| 1679 | Course Schedule | [Código](./1679.cpp) |
| 1678 | Round Trip II | [Código](./1678.cpp) |
| 1680 | Longest Flight Route | [Código](./1680.cpp) |
| 1197 | Cycle Finding | [Código](./1197.cpp) |
| 1196 | Flight Routes | [Código](./1196.cpp) |
| 1681 | Game Routes | [Código](./1681.cpp) |
| 1202 | Investigation | [Código](./1202.cpp) |
| 1750 | Planets Queries I | [Código](./1750.cpp) |
| 1751 | Planets Cycles | [Código](./1751.cpp) |
| 1160 | Planets Queries II | [Código](./1160.cpp) |
| 1676 | Road Construction | [Código](./1676.cpp) |
| 1675 | Road Reparation | [Código](./1675.cpp) |
| 1682 | Flight Routes Check | [Código](./1682.cpp) |
| 1683 | Planets and Kingdoms | [Código](./1683.cpp) |
| 1684 | Giant Pizza | [Código](./1684.cpp) |
| 1691 | Mail Delivery | [Código](./1691.cpp) |
| 1692 | De Bruijn Sequence | [Código](./1692.cpp) |
| 1693 | Teleporters Path | [Código](./1693.cpp) |
| 1690 | Hamiltonian Flights | [Código](./1690.cpp) |

---

## 1192 - COUNTING ROOMS
- Esse exercício utiliza a técnica DFS (Depth-First Search ou Busca em Profundidade) para "marcar" toda a área do cômodo, garantindo que ele não seja contado mais de uma vez. 
- A função DFS funciona da seguinte forma:
	- Ela recebe, como parâmetro, a linha e a coluna da estrutura atual. 
	- Se essa estrutura já foi visitada OU se essa estrutura for uma parede (#), ela retorna. Caso contrário, essa estrutura é um chão E ainda não foi visitada, portanto, faz parte de um cômodo. 
	- O chão atual é sinalizado como visitado e, então, a função tenta fazer 4 recursões diferentes: para a direita, para baixo, para esquerda e para cima.
	- Isso faz com que toda a área do cômodo atual seja sinalizada como visitada, a fim de impedir que algum chão desse cômodo seja marcado como um cômodo diferente.
- Na main, é feita uma leitura de toda a matriz que armazena o mapa do local. 
	- Toda vez que a estrutura atual é um chão que ainda não foi visitado, a main incrementa a variável `comodos` e chama a função dfs com as coordenadas atuais. 

## 1193 - LABYRINTH
- Esse exercício utiliza a técnica BFS (Breadth-First Search ou Busca em Largura) para encontrar o caminho mais próximo do fim do labirinto. 
- A função BFS funciona da seguinte forma:
	- Ela recebe a linha e a coluna do início do labirinto `A` como parâmetro e marca esse local como visitado. 
	- Depois, insere na fila essas coordenadas e inicia um loop while que se repete enquanto essa fila não estiver vazia. 
		- Dentro do loop, as coordenadas do elemento na primeira posição da fila são salvas e retiradas da fila. 
		- A partir de tais coordenadas, é feita a tentativa de andar para cima, para baixo, para a direita, e para a esquerda. Para cada uma dessas direções, se o caminho estiver livre (for um chão não visitado), as coordenadas dele serão marcadas como visitada, a letra da direção caminhada naquelas coordenadas é salva e essas coordenadas são inseridas na fila. 
		- Se uma dessas direções encontrar o fim do labirinto `B`, uma outra função é chamada para reconstruir o caminho feito e a função bfs é retornada. 
- A função para reconstruir o caminho funciona da seguinte forma: 
	- Ela recebe a linha e a coluna do fim do labirinto como parâmetro. 
	- Inicia um loop que se repete enquanto a linha e a coluna não forem o início do labirinto `A`. O caminho aqui é feito de trás para frente.
		- Dentro do loop, os passos são armazenados em uma estrutura de pilha (último a entrar, primeiro a sair). 
		- Como está sendo feita a leitura de trás para frente dos passos efetuados, do último até o primeiro, se o último passo dado foi para a direita (R), para fazer o caminho inverso, caminha-se para a esquerda, alterando as coordenadas (decrementando a coluna em 1). 
		- Dessa forma, é executado um switch-case; quando o passo dado foi "R", decrementa-se a coluna em um; quando o passo dado foi "L", incrementa-se a coluna em um; quando o passo dado foi "D", decrementa-se a linha; quando o passo dado foi "U", incrementa-se a linha; tudo isso é feito para retornar os passos, voltando de onde feio (início do labirinto).
- Na main, para a impressão final, se a pilha que armazena os passos finais estiver fazia, então não existe nenhum caminho possível; caso contrário, o caminho foi armazenado e é possível concluí-lo.
	- Os passos são impressos e desempilhados um a um da maneira a qual eles foram empilhados, do último até o primeiro.

## 1666 - BUILDING ROADS
- A técnica utilizada nessa solução foi a de modelar o problema armazenando o grafo em uma lista de adjacências e o explorando com o auxílio de uma função DFS. 
- A função DFS recebe uma cidade como parâmetro e a sinaliza como visitada. Depois, inicia um loop que percorre todas as cidades conectadas a ela através de uma estrada e as sinaliza como visitadas através da recursão. Isso garante que cada conjunto de cidades interligadas só seja contado uma vez. 
- Na main, ao fazer a leitura das rodovias que interligam as cidades `a` e `b`, a cidade `a` é armazenada na lista da cidade `b`, bem como a cidade `b` é armazenada na lista da cidade `a`.
- Depois, uma variável auxiliar `representantes` é criada para "nomear" qual cidade de cada conjunto será responsável por conter a estrada que será criada. 
- O loop for é criado para fazer a leitura de todas as cidades; Toda cidade que ainda não foi visitada é inserida como representante e adicionada ao vetor, e aí a função dfs com ela é chamada para garantir que somente um representante exista para cada conjunto de cidades interligadas.
- Por fim, a quantidade mínima de estradas a serem criadas será a quantidade de cidades representantes menos 1. Então, as cidades representantes são impressas uma a uma, como uma corrente. 

## 1667 - MESSAGE ROUTE
- 

## 1668 - BUILDING TEAMS
- 

## 1669 - ROUND TRIP
- 

## 1194 - MONSTERS
- 

## 1671 - SHORTEST ROUTES I
- 

## 1672 - SHORTEST ROUTES II
- 

## 1679 - COURSE SCHEDULE
- 

## 1678 - ROUND TRIP II
- 

## 1680 - LONGEST FLIGHT ROUTE
- 

## 1197 - CYCLE FINDING
- 

## 1196 - FLIGHT ROUTES
- 

## 1681 - GAME ROUTES
- 

## 1202 - INVESTIGATION
- 

## 1750 - PLANETS QUERIES I
- 

## 1751 - PLANETS CYCLES
- 

## 1160 - PLANETS QUERIES II
- 

## 1676 - ROAD CONSTRUCTION
- 

## 1675 - ROAD REPARATION
- 

## 1682 - FLIGHT ROUTES CHECK
- 

## 1683 - PLANETS AND KINGDOMS
- 

## 1684 - GIANT PIZZA
- A técnica utilizada para esse problema basicamente é uma reciclagem do código dos problemas anteriores (Planets and Kingdoms): o Algoritmo de Kosaraju, que envolve fazer duas buscas dfs - uma para pegar a ordem em que os nós do grafo terminam de ser processados (do primeiro ao último), e outra para ler o grafo na ordem obtida anteriormente, mas com as direções do grafo invertida, a fim de agrupar em "conjuntos" todos os grafos que participam do mesmo ciclo -, esse algoritmo serve para encontrar componentes fortemente conexos (SCC), que são, basicamente, subgrupos dentro do grafo que formam um ciclo entre si. 
- Tendo dois sabores `a` e `b`, como o enunciado do problema requer que pelo menos um dos requisitos de sabores sejam atendidos `(a v b)`, pode-se fazer a seguinte associação: `~a->b` OU `~b->a`; que pode ser lido como, se eu não insiro o sabor `a`, então o sabor `b` deve ser atendido e vice-vesra. Para isso, essas condições são armazenadas em duas listas de adjacência: uma na ordem normal, que armazena `~a` apontando para `b` e `~b` apontando para `a`; a segunda lista de adjacência armazena esses valores com as setas invertidas. (Para um dado sabor `a`, se a pessoa não gosta dele, então o seu valor na lista de adjacência vai ser armazenado na posição `a+m`, sendo `m` a quantidade de sabores; se a pessoa gosta do sabor, seu valor na lista é armazenado na posição `a`. A operação de negação `~` é feita adicionando `+m`, se o valor anterior era positivo, ou removendo `-m`, se o valor anterior era negativo).
- Após feitas a leitura das listas de adjacências e as chamadas das DFS, é feita uma iteração de `1 até m`, a fim de verificar se um sabor `a` faz parte do mesmo conjunto do sabor `~a`, se fizer, então uma contradição foi encontrada e será impresso "IMPOSSIBLE" e o código encerra. Isso porque é impossível que `a` e `~a`, (um sabor esteja e não esteja na pizza) aconteçam ao mesmo tempo.
- Se a condição anterior não foi bem-sucedida, então é feita a impressão dos sabores que estarão (`+`) e que não estarão (`-`) na pizza. Isso é feito a partir de uma iteração de `1` até `m` da seguinte forma: dado o sabor `i` atual, sabe-se que ele se encontra na pizza na posição `i` (`+`), do vetor que armazena os componentes completamente conexos, e que ele não se encontra na pizza na posição `i+1` (-). Para opções mais seguras de valores, faz-se a impressão do valor que foi analisado mais recentemente entre `i` e `i+m`, que é o que possui o maior índice do vetor dos componentes fortemente conexos. 

## 1691 - MAIL DELIVERY
- 

## 1692 - DE BRUIJN SEQUENCE
- 

## 1693 - TELEPORTERS PATH
- 

## 1690 - HAMILTONIAN FLIGHTS
- 