/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int dc[] = {-1, 1,  0, 0}; // esquerda, direita, cima, baixo
const int dl[] = { 0, 0, -1, 1};

int n, m;
vector<string> mapa;

void dfs(int l, int c){
    mapa[l][c] = '#';

    for(int i = 0; i < 4; ++i){
        int nl = l + dl[i], nc = c + dc[i];

        if(nl >= 0 && nc >= 0 && nl < n && nc < m && mapa[nl][nc] == '.')
            dfs(nl, nc);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    mapa.resize(n);

    for(int i = 0; i < n; ++i)
        cin >> mapa[i];
    
    int qtdQuartos = 0;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(mapa[i][j] == '.'){
                dfs(i, j);
                qtdQuartos++;
            }

    cout << qtdQuartos << '\n';

    return 0;
}