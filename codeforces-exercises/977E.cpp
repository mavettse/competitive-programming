/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; 
vector<int> parent;
int numComponents = 0;
bool valid;

void dfs(int node){
    if(adj[node].size() != 2)
        valid = 0;

    for(int neighbor : adj[node]){
        if(parent[neighbor] == -1){
            parent[neighbor] = node;
            dfs(neighbor);
        } else if(parent[neighbor] == node)
                valid = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    adj.assign(n+1, vector<int>());
    parent.assign(n+1, -1);

    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i){
        if(parent[i] != -1)
            continue;

        valid = 1;
        parent[i] = 0;
        dfs(i);

        if(valid)
            numComponents++;
    }
    
    cout << numComponents << endl;

    return 0;
}