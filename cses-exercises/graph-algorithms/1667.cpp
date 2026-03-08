/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> adj;
queue<int> fila;
vector<int> visitado;
vector<int> distancia;
vector<int> caminhoPcs;

void bfs(int pc){
    visitado[pc] = 1;
    distancia[pc] = 1;
    fila.push(pc);

    while(!fila.empty()){
        int pc1oFila = fila.front(); 
        fila.pop();

        for(const int& pcAtual : adj[pc1oFila]){
           if(visitado[pcAtual]){
                continue;
           }

           caminhoPcs[pcAtual] = pc1oFila;
           visitado[pcAtual] = 1;
           distancia[pcAtual] = distancia[pc1oFila] + 1;
           fila.push(pcAtual);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    adj.assign(n+1, vector<int>());
    visitado.assign(n+1, 0);
    distancia.assign(n+1, 0);
    caminhoPcs.assign(n+1, 0);

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    if(distancia[n] == 0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << distancia[n] << "\n";

    int atual = n;
    vector<int> rota;

    while(atual != 0){
        rota.push_back(atual);
        atual = caminhoPcs[atual];
    } 

    for(auto caminho = rota.rbegin(); caminho != rota.rend(); ++caminho){
        cout << *caminho << " ";
    }

    cout << "\n";
    
    return 0;
}