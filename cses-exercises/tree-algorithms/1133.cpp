/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> tamanho;
vector<long long> somaDist;

void dfs1(int noPai, int noAnterior){
    tamanho[noPai]++;
    for(int noFilho : adj[noPai]){
        if(noFilho == noAnterior){
            continue;
        }

        dfs1(noFilho, noPai);
        tamanho[noPai] += tamanho[noFilho];
        somaDist[noPai] += somaDist[noFilho] + tamanho[noFilho];
    }
}

int n;
vector<long long> somaTotal;

void dfs2(int noPai, int noAnterior){
    for(int noFilho : adj[noPai]){
        if(noFilho == noAnterior){
            continue;
        }

        somaTotal[noFilho] = somaTotal[noPai] - tamanho[noFilho] + (n - tamanho[noFilho]);
        dfs2(noFilho, noPai);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; 
    adj.assign(n+1, vector<int>());
    tamanho.assign(n+1, 0);
    somaDist.assign(n+1, 0);
    somaTotal.assign(n+1, 0);

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1,0);
    somaTotal[1] = somaDist[1];
    dfs2(1,0);

    for(int i = 1; i <= n; ++i){
        cout << somaTotal[i] << " ";
    }

    cout << "\n";
    
    return 0;
}