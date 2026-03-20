/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visitado, valido;
vector<int> resp;
bool impossivel = 0;

void dfs(int curso){
    visitado[curso] = 1;

    for(auto const& preRequisito : adj[curso]){
        if(!visitado[preRequisito]){
            dfs(preRequisito);
        }

        if(!valido[preRequisito]){
            impossivel = 1;
            return;
        }
    }

    if(impossivel){
        return;
    }

    valido[curso] = 1;
    resp.push_back(curso);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    adj.assign(n+1, vector<int>());
    visitado.assign(n+1, 0);
    resp.reserve(n+1);
    valido.assign(n+1, 0);

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[b].push_back(a); // curso b requer o a; {curso, pré-requisito}
    }

    for(int i = 1; i <= n; ++i){
        if(!visitado[i]){
            dfs(i);
        }

        if(impossivel){
            cout << "IMPOSSIBLE\n";
            return 0;
        }    
    }
    
    for(auto const& curso : resp){
        cout << curso << ' ';
    }
    
    cout << '\n';
    
    return 0;
}