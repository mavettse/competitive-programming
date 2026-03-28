/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

const int MODULO = 1e9+7;

int n;
vector<vector<pair<int, int>>> adj;
vector<long long> dist; 
vector<int> rotas, minVoos, maxVoos;

void dijkstra(){
    vector<bool> visitados(n+1, false);
    priority_queue<pair<long long, int>> fila;
    
    dist[1] = 0; 
    rotas[1] = 1;

    fila.push({0,1}); // {-distancia, nó}

    while(!fila.empty()){
        int a = fila.top().second; fila.pop();

        if(visitados[a]){
            continue;
        }

        visitados[a] = true;

        for(auto vizinho : adj[a]){
            int b = vizinho.first, c = vizinho.second;
            
            if(dist[a]+c < dist[b]){
                dist[b] = dist[a]+c;
                rotas[b] = rotas[a];
                minVoos[b] = minVoos[a]+1; 
                maxVoos[b] = maxVoos[a]+1;
                fila.push({-dist[b], b});
            } else if(dist[a]+c == dist[b]){
                rotas[b] = (rotas[b] + rotas[a])%MODULO;
                minVoos[b] = min(minVoos[b], minVoos[a]+1);
                maxVoos[b] = max(maxVoos[b], maxVoos[a]+1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int m; cin >> n >> m;

    adj.assign(n+1, vector<pair<int, int>>());
    dist.assign(n+1, 1e18+7);
    rotas.assign(n+1, 0); minVoos.assign(n+1, 0); maxVoos.assign(n+1, 0);

    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijkstra();

    cout << dist[n] << ' ' << rotas[n] << ' ' << minVoos[n] << ' ' << maxVoos[n] << '\n';

    return 0;
}