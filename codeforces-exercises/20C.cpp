/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<vector<pair<int,int>>> edges;
vector<long long> dist;
vector<int> pais;
vector<int> caminho;

void dijkstra(){
    dist[1] = 0;

    priority_queue<pair<long long,int>> pq; // {-distancia, nó}

    pq.emplace(0,1);

    while(pq.size()){
        auto [ndist, u] = pq.top(); pq.pop();
        
        if(-ndist > dist[u]) continue;

        for(auto [idx, w] : edges[u])
            if(dist[idx] > dist[u] + w){
                dist[idx] = dist[u] + w;
                pq.emplace(-dist[idx], idx);
                pais[idx] = u;
            }
    }
}

void reconstruir_caminho(int fim){
    int atual = fim;

    while(atual != 1 && atual != 0){
        caminho.push_back(atual);
        atual = pais[atual];
    }

    caminho.push_back(1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; 
    cin >> n >> m;

    edges.assign(n+1, vector<pair<int,int>>());
    dist.assign(n+1, INF);
    pais.assign(n+1, 0);

    for(int i = 0; i < m; ++i){
        int a, b, w; cin >> a >> b >> w;

        edges[a].emplace_back(b,w);
        edges[b].emplace_back(a,w);
    }

    dijkstra();

    if(dist[n] == INF){ 
        cout << "-1\n";
        return 0;
    }

    reconstruir_caminho(n);

    for(auto it = caminho.rbegin(); it != caminho.rend(); ++it)
        cout << *it << ' '; 
    
    cout << '\n';

    return 0;
}