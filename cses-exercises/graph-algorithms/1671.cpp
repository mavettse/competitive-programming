/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<long long,int>>> adj;
vector<long long> distancia;
vector<int> visitado;

void menorCaminho(){
    priority_queue<pair<long long,int>> fila; // {distancia, b}
    distancia[1] = 0;
    fila.push({0,1});

    while(!fila.empty()){
        int a = fila.top().second; 
        fila.pop();

        if(visitado[a]){
            continue;
        }

        visitado[a] = 1;

        for(auto parAtual : adj[a]){
            int b = parAtual.first, c = parAtual.second;

            if(distancia[a] + c < distancia[b]){
                distancia[b] = distancia[a] + c;
                fila.push({-distancia[b], b}); // é feito {-distancia, b} porque a priority_queue é em ordem decrescente; os maiores valores são armazenados primeiro; com o número negativo armazenado, o menor se torna o maior e o menor se torna o maior; os itens com a menor distância estarão em primeiro lugar na fila
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    adj.assign(n+1, vector<pair<long long,int>>());
    distancia.assign(n+1, 1e18);
    visitado.assign(n+1, 0);

    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c}); // a, {b, peso}
    }

    menorCaminho();    

    for(int i = 1; i <= n; ++i){
        cout << distancia[i] << " "; 
    }

    cout << "\n";
        
    return 0;
}