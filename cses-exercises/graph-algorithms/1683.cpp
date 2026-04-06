/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

int qtdReinos = 0;
vector<bool> visitado;
vector<int> reinos, ordemDFS;

void dfsOrdenar(int atual, vector<vector<int>>& adj){
    visitado[atual] = 1;

    for(const int filho : adj[atual]){
        if(visitado[filho]){
            continue;
        }

        dfsOrdenar(filho, adj);
    }

    ordemDFS.push_back(atual);
}

void dfs(int atual, vector<vector<int>>& adj){
    visitado[atual] = 1;

    for(const int filho : adj[atual]){
        if(visitado[filho]){
            continue;
        }

        reinos[filho] = reinos[atual];
        dfs(filho, adj);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>()), adjRev(n+1, vector<int>());

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adjRev[b].push_back(a);
    }

    visitado.assign(n+1, 0);
    reinos.resize(n+1);
    ordemDFS.reserve(n);

    for(int i = 1; i <= n; ++i){
        if(!visitado[i]){
            dfsOrdenar(i, adj);
        }
    }

    visitado.assign(n+1, 0);

    for(auto it = ordemDFS.rbegin(); it != ordemDFS.rend(); ++it){
        if(!visitado[*it]){
            reinos[*it] = ++qtdReinos;
            dfs(*it, adjRev);
        }
    }

    cout << qtdReinos << '\n';

    for(int i = 1; i <= n; ++i){
        cout << reinos[i] << ' ';
    }

    cout << '\n';
    
    return 0;
}