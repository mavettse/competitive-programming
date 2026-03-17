/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int chefe[200001][20];
int altura[200001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    int qtdBits = log2(n) + 1;

    memset(chefe, 0, sizeof(chefe)); memset(altura, 0, sizeof(altura));
    chefe[1][0] = -1; altura[1] = 0;

    for(int i = 2; i <= n; ++i){
        cin >> chefe[i][0];
        altura[i] = altura[chefe[i][0]] + 1;
    }

    for(int i = 1; i <= qtdBits; ++i){
        for(int x = 1; x <= n; ++x){
            int chefeAnterior = chefe[x][i-1];

            if(chefeAnterior == -1){
                chefe[x][i] = -1;
                continue;
            }

            chefe[x][i] = chefe[chefeAnterior][i-1];
        }
    }

    for(int i = 0; i < q; ++i){
        int a, b; cin >> a >> b;

        if(altura[b] > altura[a]){
            int temp = a;
            a = b;
            b = temp;
        }

        int niveisDif = altura[a] - altura[b];

        if(niveisDif > 0){ // funcionario a está {niveisDif} niveis abaixo de b
            for(int j = qtdBits; j >= 0; --j){
                if((niveisDif&(1<<j)) != 0){
                    a = chefe[a][j];
                }
            }
        }

        if(a == b){
            cout << a << "\n";
            continue;
        }

        for(int j = qtdBits; j >= 0; --j){
            if(chefe[a][j] != chefe[b][j]){
                a = chefe[a][j];
                b = chefe[b][j];
            }
        }

        cout << chefe[a][0] << "\n";
    }
    
    return 0;
}