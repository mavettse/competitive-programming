/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

int n, m; 
vector<vector<char>> mapa;
vector<vector<int>> visitado;

void dfs(const int& linha, const int& coluna){
    if(visitado[linha][coluna] || mapa[linha][coluna] == '#'){
        return;
    }

    visitado[linha][coluna] = 1;

    dfs(linha, coluna+1); // tenta direita
    dfs(linha+1, coluna); // tenta baixo
    dfs(linha, coluna-1); // tenta esquerda
    dfs(linha-1, coluna); // tenta cima
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    mapa.assign(n+2, vector<char>(m+2, '#'));
    visitado.assign(n+2, vector<int>(m+2, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char estrutura; cin >> estrutura;
            mapa[i][j] = estrutura;
        }
    }

    int comodos = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(mapa[i][j] == '.' && !visitado[i][j]){
                comodos++;
                dfs(i,j);
            }
        }
    }

    cout << comodos << "\n";
    
    return 0;
}