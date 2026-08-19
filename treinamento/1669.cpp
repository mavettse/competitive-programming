/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent, ans;
bool found = 0;
int auxNode = 0;

void backtracking(){
    int aux = auxNode;

    while(aux != *ans.begin()){
        ans.push_back(aux);
        aux = parent[aux];
    }

    ans.push_back(aux);
}

void dfs(int node){
    for(auto v : adj[node]){
        if(found)   
            return;

        if(parent[v] == -1){
            parent[v] = node;
            dfs(v);
        } else if(parent[node] != v){
            found = 1; 
            ans.push_back(v);
            auxNode = node;
            backtracking();
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    adj.assign(n+1, vector<int>());
    parent.assign(n+1, -1);

    while(m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        if(found)
            break;
        
        if(parent[i] == -1){
            parent[i] = 0;
            dfs(i);
        }
    } 

    if(found){
        cout << ans.size() << endl;
        for(auto it = ans.rbegin(); it != ans.rend(); it++)
            cout << *it << ' ';
        cout << endl;
    } else 
        cout << "IMPOSSIBLE\n";

    return 0;
}