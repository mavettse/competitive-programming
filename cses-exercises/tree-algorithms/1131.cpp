/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
queue<int> fila;
vector<int> distancia;

void bfs(int noOrigem){
    distancia[noOrigem] = 0;
    fila.push(noOrigem);

    while(!fila.empty()){
        int noPai = fila.front(); 
        fila.pop();

        for(int noFilho : adj[noPai]){
            if(distancia[noFilho] != -1){
                continue;
            }

            distancia[noFilho] = distancia[noPai] + 1;
            fila.push(noFilho);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; 
    adj.assign(n+1, vector<int>());
    distancia.assign(n+1, -1);

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
    int distB = 0, b = 0;

    for(int i = 1; i <= n; ++i){
        if(distancia[i] <= distB){
            continue;
        }

        distB = distancia[i];
        b = i;
    }

    fill(distancia.begin(), distancia.end(), -1);
    bfs(b);
    
    int distC = 0;

    for(int i = 1; i <= n; ++i){
        distC = max(distC, distancia[i]);
    }

    cout << distC << "\n";
    
    return 0;
}