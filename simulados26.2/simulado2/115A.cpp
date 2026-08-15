/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int maxDepth = 0;

void dfs(int superior, int curDepth){
    maxDepth = max(maxDepth, curDepth);
    
    for(int subordinado : adj[superior])
        dfs(subordinado, curDepth + 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    adj.assign(n+1, vector<int>()); // adj[superior] = {subordinates}
    vector<int> roots;

    for(int i = 1; i <= n; ++i){
        int superior; cin >> superior;

        if(superior == -1)
            roots.push_back(i);
        else 
            adj[superior].push_back(i);
    }

    for(int root : roots)
        dfs(root, 1);

    cout << maxDepth << '\n';

    return 0;
}