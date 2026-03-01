/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> visitado;

void dfs(int cidade){
    visitado[cidade] = 1;

    for(const int& vizinha : adj[cidade]){
        if(!visitado[vizinha]){
            dfs(vizinha);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    
    adj.assign(n+1, vector<int>());
    visitado.assign(n+1, 0);

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> representantes;

    for(int i = 1; i <= n; ++i){
        if(!visitado[i]){
            representantes.push_back(i);
            dfs(i);
        }
    }

    int qtdEstradas = representantes.size() - 1; 

    cout << qtdEstradas << "\n";

    for(int i = 0; i < qtdEstradas; ++i){
        cout << representantes[i] << " " << representantes[i+1] << "\n";
    }
    
    return 0;
}