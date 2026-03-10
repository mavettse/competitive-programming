/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> contagem;

void dfs(int funcionario, int funcionarioAnterior){
    for(auto subordinado : adj[funcionario]){
        contagem[funcionario]++;
        dfs(subordinado, funcionario);
        contagem[funcionario] += contagem[subordinado];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    adj.assign(n+1, vector<int>());
    contagem.assign(n+1, 0);

    for(int subordinado = 2; subordinado <= n; ++subordinado){
        int chefe; cin >> chefe; 
        adj[chefe].push_back(subordinado);
    }

    dfs(1,0);

    for(int i = 1; i <= n; ++i){
        cout << contagem[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}