/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());

    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    /* IMPLEMENTAÇÃO DO ALGORITMO DE DIJKSTRA ALTERADO */
    priority_queue<pair<long long, int>> fila;
    vector<priority_queue<long long>> custo(n+1);

    fila.push({0,1}); // {-custoAtual, cidadeAtual}
    custo[1].push(0);

    while(!fila.empty()){
        long long custoAtual = (-1)*fila.top().first, a = fila.top().second; fila.pop();

        if(!custo[a].empty() && custoAtual > custo[a].top()){
            continue;
        }

        for(auto [b,c] : adj[a]){
            long long novoCusto = custoAtual + c;

            if((int)custo[b].size() < k){
                custo[b].push(novoCusto);
                fila.push({-novoCusto, b});
            } else if((int)custo[b].size() >= k && novoCusto < custo[b].top()){
                custo[b].push(novoCusto);
                fila.push({-novoCusto, b});
                custo[b].pop();
            }
        }
    }

    vector<long long> resp(k);

    for(int i = 0; i < k; ++i){
        resp[i] = custo[n].top();
        custo[n].pop();
    }

    for(auto it = resp.rbegin(); it != resp.rend(); ++it){
        cout << *it << ' ';
    }

    cout << '\n';
        
    return 0;
}