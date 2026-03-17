/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
int chefe[200001][20];
int altura[200001];
vector<vector<int>> adj;

void dfs(int noAtual, int noPai){
    chefe[noAtual][0] = noPai;

    for(const int& filho : adj[noAtual]){
        if(filho == noPai){
            continue;
        }

        altura[filho] = altura[noAtual] + 1;
        dfs(filho, noAtual);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    memset(chefe, 0, sizeof(chefe)); memset(altura, 0, sizeof(altura));
    altura[1] = 0;

    int n, q; cin >> n >> q;
    int qtdBits = log2(n) + 1;

    adj.assign(n+1, vector<int>());

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    for(int i = 1; i <= qtdBits; ++i){ // pré-processamento dos chefes 
        for(int x = 1; x <= n; ++x){
            int chefeAnterior = chefe[x][i-1];

            if(chefeAnterior == 0){
                chefe[x][i] = 0;
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
        int lac = a;

        if(niveisDif > 0){ // funcionario {a} está {niveisDif} abaixo de {b}
            for(int j = qtdBits; j >= 0; --j){
                if((niveisDif&(1<<j)) != 0){
                    lac = chefe[lac][j];
                }
            }
        }

        if(lac == b){
            cout << (altura[a] + altura[b] - 2 * altura[lac]) << "\n";
            continue;
        }

        int aux = b;

        for(int j = qtdBits; j >= 0; --j){
            if(chefe[lac][j] != chefe[aux][j]){
                lac = chefe[lac][j];
                aux = chefe[aux][j];
            }
        }

        cout << (altura[a] + altura[b] - 2 * altura[chefe[lac][0]]) << "\n";
    }

    return 0;
}