/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18, MAX = 1e5+3;

ll d[MAX];
vector<pair<int,ll>> adj[MAX];

int n; 

void dijkstra(){
    for(int i = 1; i <= n; ++i)
        d[i] = INF;

    d[1] = 0;

    priority_queue<pair<ll, int>> pq;
    pq.emplace(0,1);

    while(pq.size()){
        auto [ndist, u] = pq.top();
        pq.pop();

        if(-ndist > d[u]) 
            continue;
            
        for(auto [idx, w] : adj[u])
            if(d[idx] > d[u] + w){
                d[idx] = d[u] + w;
                pq.emplace(-d[idx], idx);
            }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int m; cin >> n >> m; 

    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b,c);
    }

    dijkstra();

    for(int i = 1; i <= n; ++i)
        cout << d[i] << ' ';
    cout << endl;

    return 0;
}