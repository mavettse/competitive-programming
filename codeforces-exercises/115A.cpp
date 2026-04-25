/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; 
vector<int> profundidade;
int maiorProfundidade = 1;

void dfs(int atual){
    for(const int filho : adj[atual]){
        profundidade[filho] = profundidade[filho] + profundidade[atual];
        maiorProfundidade = max(maiorProfundidade, profundidade[filho]);
        dfs(filho);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    adj.assign(n+1, vector<int>());
    profundidade.assign(n+1, 1);
    vector<int> chefes;

    for(int i = 1; i <= n; ++i){
        int chefe; cin >> chefe;
        
        if(chefe == -1){
            chefes.push_back(i);
            continue;
        }

        adj[chefe].push_back(i);
    }

    for(const int chefe : chefes){
        dfs(chefe);
    }

    cout << maiorProfundidade << '\n';

    return 0;
}