/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std; 

vector<bool> visitado;

void dfs(int atual, vector<vector<int>> const& adj){
    visitado[atual] = 1;

    for(const int filho : adj[atual]){
        if(visitado[filho]){
            continue;
        }

        dfs(filho, adj);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>()), adjReversa(n+1, vector<int>());

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adjReversa[b].push_back(a);
    }

    visitado.assign(n+1, 0);

    dfs(1, adj);
    for(int i = 2; i <= n; ++i){
        if(!visitado[i]){
            cout << "NO\n" << 1 << ' ' << i << '\n';
            return 0;
        }
    }

    visitado.assign(n+1, 0);

    dfs(1, adjReversa);
    for(int i = 2; i <= n; ++i){
        if(!visitado[i]){
            cout << "NO\n" << i << ' ' << 1 << '\n';
            return 0;
        }
    }

    cout << "YES\n";
    
    return 0;
}