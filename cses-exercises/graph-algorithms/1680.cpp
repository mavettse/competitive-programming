/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std; 

int n;
vector<vector<int>> adj;
vector<int> dist, melhorCaminho;

void dfs(int cidadeAtual){
    if(cidadeAtual == n){
        dist[cidadeAtual] = 1;
        return;
    }

    for(const auto& conexao : adj[cidadeAtual]){
        if(dist[conexao] == 0){
            dfs(conexao);
        }

        if(dist[conexao] != -1 && dist[conexao]+1 > dist[cidadeAtual]){
            dist[cidadeAtual] = dist[conexao]+1;
            melhorCaminho[cidadeAtual] = conexao;
        }
    }

    if(dist[cidadeAtual] == 0){
        dist[cidadeAtual] = -1;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int m; cin >> n >> m;
    adj.assign(n+1, vector<int>());
    dist.assign(n+1, 0); // armazena a maior distância possível da cidade i até a n;
    melhorCaminho.reserve(n+1);

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b); // {cidade, voos diretos para outras cidades}
    }

    dfs(1);

    if(dist[1] < 1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int aux = 1;
    vector<int> rota;

    while(aux != n){
        rota.push_back(aux);
        aux = melhorCaminho[aux];
    }

    rota.push_back(aux);

    cout << rota.size() << '\n';

    for(const auto r : rota){
        cout << r << ' ';
    }

    cout << '\n';
    
    return 0;
}