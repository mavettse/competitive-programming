/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
vector<vector<int>> adj;
vector<set<int>> coresAbaixo;
vector<int> corInicial, resposta;

void dfs(int atual, int pai){
    coresAbaixo[atual].insert(corInicial[atual]);
    
    for(const int filho : adj[atual]){
        if(filho == pai){
            continue;
        }

        dfs(filho, atual);

        if(coresAbaixo[atual].size() < coresAbaixo[filho].size()){
            swap(coresAbaixo[atual], coresAbaixo[filho]);
        }

        for(const int cor : coresAbaixo[filho]){
            coresAbaixo[atual].insert(cor);
        }
    }

    resposta[atual] = coresAbaixo[atual].size();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    adj.assign(n+1, vector<int>());
    corInicial.resize(n+1);
    coresAbaixo.resize(n+1);
    resposta.resize(n+1);

    for(int i = 1; i <= n; ++i){
        cin >> corInicial[i];
    }

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    for(int i = 1; i <= n; ++i){
        cout << resposta[i] << ' ';
    }
    
    cout << '\n';
    
    return 0;
}