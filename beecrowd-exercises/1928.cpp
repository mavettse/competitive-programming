/* 
O grafo é uma árvore (N nós e N-1 arestas); Utilizar Binary Lifting para encontrar o LCA entre os dois nós de mesmo valor; A busca para o LCA é feita com a manipulação de bits entre os dois nós
*/

#include <bits/stdc++.h>
using namespace std;

int maxColumn;
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;
vector<pair<int,int>> cards;

void dfs(int node, int parent){
    for(int j = 1; j < maxColumn; ++j) up[node][j] = up[up[node][j-1]][j-1];

    for(const auto& son : adj[node]){
        if(son == parent) continue;

        up[son][0] = node;
        depth[son] = depth[node] + 1;
        dfs(son, node);
    }
}

int search_lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];

    for(int j = 0; j < maxColumn; ++j)
        if(diff & (1 << j)) u = up[u][j];

    if(u == v) return u;

    for(int j = maxColumn - 1; j >= 0; --j){
        if(up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    maxColumn = ceil(log2(n)) + 1;
    adj.assign(n+1, vector<int>());
    up.assign(n+1, vector<int>(maxColumn, 1));
    depth.assign(n+1, 0);
    cards.assign(n/2 + 1, pair<int,int>({0,0}));

    for(int i = 1; i <= n; ++i){
        int num; cin >> num;

        if(cards[num].first == 0) cards[num].first = i;
        else cards[num].second = i;
    } 

    for(int i = 0; i < n-1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);

    int maxPoints = 0;

    for(int i = 1; i <= n/2; ++i){
        auto const& [u, v] = cards[i];
        maxPoints += (depth[u] + depth[v] - 2*depth[search_lca(u,v)]);
    }

    cout << maxPoints << '\n';
    
    return 0;
}