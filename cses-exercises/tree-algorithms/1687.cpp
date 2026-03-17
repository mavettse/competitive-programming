/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int chefe[200001][20];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    int qtdBits = log2(n) + 1;

    memset(chefe, 0, sizeof(chefe));
    chefe[1][0] = -1;

    for(int i = 2; i <= n; ++i){
        cin >> chefe[i][0];
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
        int x, k; cin >> x >> k;

        for(int j = qtdBits; j >= 0; --j){
            if((k&(1<<j)) != 0){
                if(x == -1){
                    break;
                }

                x = chefe[x][j];
            }
        }

        cout << x << "\n";
    }
    
    return 0;
}