/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> visitado, pai;
int cicloInicio = -1, cicloFim = -1;

void dfs(int cidade){
    if(cicloInicio != -1){
        return;
    }

    visitado[cidade] = 1;

    for(const int& vizinha : adj[cidade]){
        if(visitado[vizinha] && vizinha != pai[cidade]){
            cicloInicio = vizinha;
            cicloFim = cidade;
            return;
        }

        if(!visitado[vizinha]){
            pai[vizinha] = cidade;
            dfs(vizinha);
            
            if(cicloInicio != -1){
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    adj.assign(n+1, vector<int>());
    visitado.assign(n+1,0);
    pai.assign(n+1,0);

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        if(!visitado[i]){
            dfs(i);
        }
    }

    if(cicloInicio == -1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> rota;

    int atual = cicloFim;
    rota.push_back(cicloInicio);

    while(atual != cicloInicio){
        rota.push_back(atual);
        atual = pai[atual];
    }

    rota.push_back(cicloInicio);

    cout << rota.size() << "\n";

    for(auto resposta = rota.rbegin(); resposta != rota.rend(); ++resposta){
        cout << *resposta << " ";
    }

    cout << "\n";
    
    return 0;
}