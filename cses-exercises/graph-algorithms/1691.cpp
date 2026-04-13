/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<bool> visitado; 

void dfs(int atual, vector<vector<pair<int,int>>>& adj){
    visitado[atual] = 1;

    for(const auto& [id, filho] : adj[atual]){
        if(!visitado[filho]){
            dfs(filho, adj);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back({i, b}); // {id, b}
        adj[b].push_back({i, a}); // {id, a}
    }

    vector<int> grau(n+1, 0);
    visitado.assign(n+1, 0);
    dfs(1, adj);

    bool impossivel = 0;

    for(int i = 1; i <= n; ++i){
        if(adj[i].size() % 2 != 0 || (adj[i].size() > 0 && !visitado[i])){
            impossivel = 1;
        }
    }

    if(impossivel){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    stack<int> pilha; 
    pilha.push(1);
    vector<int> ciclo;
    vector<bool> ruaVisitada(m, 0);

    while(!pilha.empty()){
        int atual = pilha.top();

        while(!adj[atual].empty() && ruaVisitada[adj[atual].back().first]){
            adj[atual].pop_back();
        }

        if(!adj[atual].empty()){
            auto [id,filho] = adj[atual].back();
            ruaVisitada[id] = 1;
            pilha.push(filho);
        } else {
            ciclo.push_back(atual);
            pilha.pop();
        }
    }    

    for(auto it = ciclo.rbegin(); it != ciclo.rend(); ++it){
        cout << *it << ' ';
    }

    cout << '\n';

    return 0;
}