/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // adj[pai] = {filhos}
vector<int> qtdBrancos, qtdPretos, cores; // 0 -> preto; 1 -> branco
int qtdBalanceadas = 0;

void dfs(int atual){
    for(const auto& filho : adj[atual]){
        dfs(filho);

        qtdBrancos[atual] += qtdBrancos[filho];
        qtdPretos[atual] += qtdPretos[filho];
    }

    if(cores[atual])
        qtdBrancos[atual]++;
    else 
        qtdPretos[atual]++;

    if(qtdBrancos[atual] == qtdPretos[atual])
        qtdBalanceadas++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t; 

    while(t--){
        int n; cin >> n;

        adj.assign(n+1, vector<int>());
        qtdBrancos.assign(n+1, 0);
        qtdPretos.assign(n+1, 0);
        cores.assign(n+1, 0);
        qtdBalanceadas = 0;

        for(int i = 2; i <= n; ++i){
            int pai; cin >> pai;
            adj[pai].push_back(i);
        }

        for(int i = 1; i <= n; ++i){
            char cor; cin >> cor;
            cores[i] = (cor == 'W') ? 1 : 0;
        }

        dfs(1);
        
        cout << qtdBalanceadas << '\n';
    }

    return 0;
}