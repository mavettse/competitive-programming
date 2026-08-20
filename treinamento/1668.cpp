/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> colors;

int n, m;

bool coloring(){
    colors.assign(n+1, -1);
    queue<int> q; 

    for(int i = 1; i <= n; ++i){
        if(colors[i] != -1)
            continue;

        colors[i] = 0;
        q.push(i);
        
        while(!q.empty()){
            int curNode = q.front();
            q.pop();

            for(auto neighbor : adj[curNode]){
                if(colors[neighbor] == colors[curNode])
                    return false;
                    
                if(colors[neighbor] == -1){
                    colors[neighbor] = 1 - colors[curNode];
                    q.push(neighbor);
                }
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    adj.assign(n+1, vector<int>());

    for(int i = 0; i < m; ++i){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(coloring()){
        for(int i = 1; i <= n; ++i)
            cout << colors[i]+1 << ' ';
        cout << '\n';
    } else 
        cout << "IMPOSSIBLE\n";

    return 0;
}