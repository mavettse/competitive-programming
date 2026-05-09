/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, qtdRest = 0;
vector<int> dp;
vector<vector<int>> adj;
vector<bool> ehFolha;

void dfs(int atual, int pai){
    for(const int filho : adj[atual]){
        if(pai == filho)
            continue;

        ehFolha[atual] = 0;

        if(dp[filho]){
            dp[filho] += dp[atual];

            if(dp[filho] > m)
                continue;
        }

        dfs(filho, atual);
    }        

    if(ehFolha[atual] && dp[atual] <= m){
        qtdRest++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    adj.assign(n+1, vector<int>());
    dp.assign(n+1, 0);
    ehFolha.assign(n+1, 1);

    // dp[i] inicial é 1 ou 0 - ou contem ou não contem um gato
    for(int i = 1; i <= n; ++i)
        cin >> dp[i];

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);
    cout << qtdRest << '\n';

    return 0;
}