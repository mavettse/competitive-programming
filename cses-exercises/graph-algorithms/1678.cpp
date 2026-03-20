/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<vector<int>> adj;
vector<bool> visitado, semSaida;
vector<int> pai;
bool encontrado = 0;
int inicioCiclo, fimCiclo;

void dfs(int noAtual){
    if(encontrado){
        return;
    }

    visitado[noAtual] = 1;
    
    for(const auto& noFilho : adj[noAtual]){
        if(visitado[noFilho] && !semSaida[noFilho] && noFilho != noAtual){
            encontrado = 1;
            inicioCiclo = noFilho;
            fimCiclo = noAtual;
        } else if(!visitado[noFilho]){
            pai[noFilho] = noAtual;
            dfs(noFilho);            
        }

        if(encontrado){
            return;
        }
    }

    semSaida[noAtual] = 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    adj.assign(n+1, vector<int>());
    visitado.assign(n+1, 0);
    semSaida.assign(n+1, 0);
    pai.assign(n+1, 0);

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b); // {cidade, conexão}
    }    

    for(int i = 1; i <= n; ++i){
        if(!visitado[i]){
            pai[i] = 0;
            dfs(i);
        }

        if(encontrado){
            break;
        }
    }

    if(!encontrado){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> rota;
    rota.push_back(inicioCiclo);

    while(fimCiclo != inicioCiclo){
        rota.push_back(fimCiclo);
        fimCiclo = pai[fimCiclo];
    }

    rota.push_back(inicioCiclo);

    cout << rota.size() << '\n';

    for(auto it = rota.rbegin(); it != rota.rend(); ++it){
        cout << *it << ' ';
    }

    cout << '\n';
    
    return 0;
}