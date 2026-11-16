/*
É um grafo implícito. Cada nó é um valor diferente, as arestas são as transições de dobrar ou de subtrair. Assim que encontra o alvo, o código para de rodar, o bfs foi usado para isso
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> dist(2e4 + 1, 0);
    queue<int> q; q.push(n);
    
    while(!q.empty()){
        int num = q.front(); 
        q.pop();

        if(num == m) {
            cout << dist[num] << '\n';
            break;
        }

        if(num-1 > 0 && !dist[num-1]) {
            q.push(num-1);
            dist[num-1] = dist[num] + 1;
        }

        if(num*2 <= 2e4 && !dist[num*2]){
            q.push(num*2);
            dist[num*2] = dist[num] + 1;
        } 
    }

    return 0;
}