/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> entradas(n+1, 0), saidas(n+1, 0);

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        saidas[a]++;
        entradas[b]++;
    }

    bool impossivel = 0;

    if(saidas[1] - entradas[1] != 1 || entradas[n] - saidas[n] != 1){
        impossivel = 1;
    }

    if(!impossivel){
        for(int i = 2; i < n; ++i){
            if(entradas[i] != saidas[i]){
                impossivel = 1;
                break;
            }
        }        
    }

    if(impossivel){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> resposta; 
    resposta.reserve(m+1);
    stack<int> pilha;
    pilha.push(1);

    while(!pilha.empty()){
        int atual = pilha.top();

        if(adj[atual].empty()){
            resposta.push_back(atual);
            pilha.pop();
        } else {
            int filho = adj[atual].back();
            adj[atual].pop_back();
            pilha.push(filho);
        }
    }

    if((int)resposta.size() != m+1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(auto it = resposta.rbegin(); it != resposta.rend(); ++it){
        cout << *it << ' ';
    }

    cout << '\n';

    return 0;
}