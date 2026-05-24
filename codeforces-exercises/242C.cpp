/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9+1;
const int dx[] = {1, -1, 0,  0, 1,  1, -1, -1}; // 8 movimentos possíveis: baixo, cima, direita, esquerda,
const int dy[] = {0,  0, 1, -1, 1, -1,  1, -1}; // diag dir baixo, diag esq baixo, diag dir cima, diag esq cima

set<pair<int,int>> permitido;
map<pair<int,int>, int> dist; // dist[x0, y0] = distancia do inicio

bool possible(int x, int y){
    if(x >= 1 && y >= 1 && x < MAX && y < MAX)
        return true;
    
    return false;
}

void bfs(pair<int, int> inicio, pair<int, int> fim){
    queue<pair<int,int>> fila;

    dist[inicio] = 0;
    fila.push(inicio);

    while(!fila.empty()){
        pair<int,int> atual = fila.front();
        auto [x, y] = atual;
        fila.pop();

        if(atual == fim)
            return;

        for(int i = 0; i < 8; ++i){
            int xn = x + dx[i], yn = y + dy[i];
            pair<int, int> vizinho = {xn, yn};

            // se está fora do grid ou não tá no set de permitidos ou já foi visitada, pula pra proxima
            if(!possible(xn, yn) || permitido.find(vizinho) == permitido.end() || dist.find(vizinho) != dist.end())
                continue;

            dist[vizinho] = dist[atual] + 1;
            fila.push(vizinho);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pair<int,int> inicio, fim;
    cin >> inicio.first; cin >> inicio.second; // inicio = {x0, y0}
    cin >> fim.first; cin >> fim.second; // fim = {xf, yf}

    int n; cin >> n;

    for(int i = 0; i < n; ++i){
        int r, a, b; cin >> r >> a >> b;

        for(int col = a; col <= b; ++col)
            permitido.insert({r, col});
    }

    bfs(inicio, fim);

    if(dist.find(fim) == dist.end())
        cout << "-1\n";
    else 
        cout << dist[fim] << '\n';

    return 0;
}