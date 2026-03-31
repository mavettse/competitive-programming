/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std; 

const int MAXN = 2e5+1;
const int MAXLOG = 30;

int salto[MAXN][MAXLOG];
int adj[MAXN];

// VARIÁVEIS PARA OS PLANETAS EM CICLOS
int ID_CICLOS = 1;
int cicloID[MAXN];
int tamCiclo[MAXN];
int posCiclo[MAXN];
int visitados[MAXN];

// VARIÁVEIS PARA OS PLANETAS QUE NÃO ESTÃO EM CICLOS
int profundidade[MAXN];
int entradaCiclo[MAXN];
bool visitados2[MAXN];

void dfs(int no){
    visitados[no] = 1;
    int vizinho = adj[no];

    if(visitados[vizinho] == 0){
        dfs(vizinho);
    } else if(visitados[vizinho] == 1){
        int atual = vizinho;
        vector<int> planetasCiclo;
            
        do{
            planetasCiclo.push_back(atual);
            atual = adj[atual];
        } while(atual != vizinho);

        int tamanho = planetasCiclo.size();

        for(int i = 0; i < tamanho; ++i){
            int planeta = planetasCiclo[i];

            cicloID[planeta] = ID_CICLOS;
            tamCiclo[planeta] = tamanho;
            posCiclo[planeta] = i;
        }

        ID_CICLOS++;
    }

    visitados[no] = 2; 
}

int calculaProfundidade(int no){
    if(cicloID[no] != 0){
        profundidade[no] = 0;
        entradaCiclo[no] = no;
        return 0;
    }

    if(visitados2[no]){
        return profundidade[no];
    }

    visitados2[no] = true;

    int vizinho = adj[no];

    int profVizinho = calculaProfundidade(vizinho);
    entradaCiclo[no] = entradaCiclo[vizinho];
    profundidade[no] = profVizinho + 1;

    return profundidade[no];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; ++i){
        cin >> adj[i];
        salto[i][0] = adj[i];
    }

    for(int i = 1; i < 30; ++i){
        for(int x = 1; x <= n; ++x){
            salto[x][i] = salto[ salto[x][i-1] ][i-1];
        }
    }

    for(int i = 1; i <= n; ++i){
        if(visitados[i] == 0){
            dfs(i);
        }
    }

    for(int i = 1; i <= n; ++i){
        if(visitados2[i] == 0){
            calculaProfundidade(i);
        }
    }

    for(int i = 0; i < q; ++i){
        int a, b; cin >> a >> b;

        // se a está em um cicloe b não, a nunca vai chegar em b
        if(cicloID[a] != 0 && cicloID[b] == 0){
            cout << "-1\n";
            continue;
        }

        // se a e b estão em ciclos
        if(cicloID[a] != 0 && cicloID[b] != 0){ 
            if(cicloID[a] == cicloID[b]){ // se estiverem no mesmo ciclo, basta imprimri a distância entre eles
                cout << (posCiclo[b] - posCiclo[a] + tamCiclo[a]) % tamCiclo[a] << '\n';
            } else { // se estiverem em ciclos diferentes, nunca vão se encontrar
                cout << "-1\n";
            }

            continue;
        }

        // se a não estiver em um ciclo e b sim
        if(cicloID[a] == 0 && cicloID[b] != 0){ 
            int noEntrada = entradaCiclo[a];

            if(cicloID[noEntrada] == cicloID[b]){
                cout << profundidade[a] + (posCiclo[b] - posCiclo[noEntrada] + tamCiclo[b]) % tamCiclo[b] << '\n';
            } else {
                cout << "-1\n";
            }

            continue;
        }

        // se nem a e nem b estão em ciclos
        if(cicloID[a] == 0 && cicloID[b] == 0){
            int dist = profundidade[a] - profundidade[b];

            if(dist >= 0){ // b está mais próximo do ciclo do que a
                int atual = a;

                for(int j = 0; j < 30; ++j){
                    if(dist & (1<<j)){
                        atual = salto[atual][j];
                    }
                }

                if(atual == b){
                    cout << dist << '\n';
                    continue;
                }
            }

            cout << "-1\n";
            continue;
        }
    }
    
    return 0;
}