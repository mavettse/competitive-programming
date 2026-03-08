/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> times;
int impossivel = 0;

void bfs(int aluno){
    if(times[aluno] != -1 || impossivel){
        return;
    }

    times[aluno] = 0;
    queue<int> fila;
    fila.push(aluno);

    while(!fila.empty()){
        int aluno1oFila = fila.front(); 
        fila.pop();
        
        for(const int& amigo : adj[aluno1oFila]){
            if(times[amigo] == times[aluno1oFila]){
                impossivel = 1;
                return;
            }

            if(times[amigo] != -1){
                continue;
            }

            times[amigo] = !times[aluno1oFila];
            fila.push(amigo);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    adj.assign(n+1, vector<int>());
    times.assign(n+1, -1);

    for(int j = 0; j < m; ++j){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        bfs(i);
    }

    if(impossivel){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(int i = 1; i <= n; ++i){
        cout << times[i] + 1 << " ";
    }

    cout << "\n";
    
    return 0;
}