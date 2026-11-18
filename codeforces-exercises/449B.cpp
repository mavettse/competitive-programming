// Fazer a lista de adjacências com flag para descobrir se a viagem foi feita por trem. Utilizar o dijkstra pra encontrar o menor caminho da capital até as outras cidades; criar variável que conta quantas viagens foram feitas por trem; no fim, so subtrai o total das encontradas

#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef tuple<ll, bool, int> cityTransport; // {distance, trainFlag, vertice}

const ll INF = 1e18+1;

int n, m, k, usedTrains = 0;
vector<vector<cityTransport>> adj; // adj[cur] = {dist, flag, v1}, {dist, flag, v2}, ...

void dijkstra(){
    vector<pair<ll, bool>> dist(n+1, pair<ll, bool>(INF, 0)); // dist[node] = {curDistToRoot, trainFlag}
    vector<bool> visited(n+1, 0);
    dist[1] = {0, 0};

    priority_queue<cityTransport, vector<cityTransport>, greater<cityTransport>> pq; // min-heap
    pq.push({0, 0, 1});

    while(!pq.empty()){
        auto [nodeDist, nodeFlag, node] = pq.top();
        pq.pop();
        
        if(visited[node]) continue; // se um nó já foi visitado, ele já foi relaxado (sua distância é mínima)
        
        visited[node] = 1;
        
        if(nodeFlag) usedTrains++; // se a flag estiver ligada, incrementa a variavel que armazena a qtd de trens usados

        for(auto [curDist, curFlag, cur] : adj[node]){
            pair<ll, bool> candidate = {dist[node].first + curDist, curFlag};

            if(dist[cur] > candidate){
                dist[cur] = candidate;
                pq.push({candidate.first, candidate.second, cur});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    adj.assign(n+1, vector<cityTransport>());

    // viagens de estrada tem a flag 0
    for(int i = 0; i < m; ++i){
        int u, v, x; cin >> u >> v >> x;
        adj[u].push_back({x, 0, v});
        adj[v].push_back({x, 0, u});
    }

    // viagens de trem tem a flag 1
    for(int i = 0; i < k; ++i){
        int s, y; cin >> s >> y;
        adj[1].push_back({y, 1, s}); // como a capital começa com distância 0, não tem porquê inserir o caminho de retorno das outras cidades - nenhuma aresta chegando na capital vai ser usada
    }

    dijkstra();

    cout << k-usedTrains << '\n';
    
    return 0;
}