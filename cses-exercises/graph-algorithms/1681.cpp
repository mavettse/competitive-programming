/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std; 

const int MODULO = 1e9+7;

int n;
vector<vector<int>> adj;
vector<int> dp;

void dfs(int noAtual){
    dp[noAtual] = 0;

    for(int noFilho : adj[noAtual]){
        if(dp[noFilho] == -1){
            dfs(noFilho);
        }

        dp[noAtual] = (dp[noAtual] + dp[noFilho])%MODULO;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int m; cin >> n >> m;

    adj.assign(n+1, vector<int>());
    dp.assign(n+1, -1);
    dp[n] = 1;

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);

    cout << dp[1] << '\n';
    
    return 0;
}