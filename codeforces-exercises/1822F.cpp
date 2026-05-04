/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void dfs(int atual, int pai, long long distAtual, vector<long long>& dist){
    dist[atual] = distAtual;

    for(const int filho : adj[atual]){
        if(pai == filho)
            continue;

        dfs(filho, atual, distAtual + 1, dist);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t; 

    while(t--){
        int n, k, c; cin >> n >> k >> c;

        adj.assign(n+1, vector<int>());

        for(int i = 1; i < n; ++i){
            int u, v; cin >> u >> v; 

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // primeiro dfs: calcula distancia de 1 até todos os nós (distâncias da árvore original)
        vector<long long> distOriginal(n+1, 0);
        dfs(1, 0, 0, distOriginal);

        // pega o nó mais distante de 1 (uma ponta do diâmetro)
        int maxDist1 = 1; 
        for(int i = 1; i <= n; ++i){
            if(distOriginal[i] > distOriginal[maxDist1])
                maxDist1 = i;
        }

        // segundo dfs: calcula distancia de maxDist1 até todos os nós
        vector<long long> dist1(n+1, 0);
        dfs(maxDist1, 0, 0, dist1);

        long long lucroMax = 0;

        for(int i = 1; i <= n; ++i){
            long long lucro = (dist1[i] * k) - (distOriginal[i] * c);
            lucroMax = max(lucroMax, lucro);
        }

        cout << lucroMax << '\n';
    }

    return 0;
}