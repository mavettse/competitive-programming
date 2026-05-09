/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int n, m;

const int dx[] = {1, -1,  0, 0}; // esquerda, direita, cima e baixo
const int dy[] = {0,  0, -1, 1};

vector<vector<char>> grid;
vector<vector<bool>> visitado;
vector<vector<int>> qtdKs;
bool encontrado = 0;

bool possible(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y < m)
        return true;
    
    return false;
}

void dfs(pair<int, int> atual, pair<int, int> pai){
    auto [x, y] = atual;
    auto [xPai, yPai] = pai;

    visitado[x][y] = 1;

    for(int i = 0; i < 4; ++i){
        // se já encontrou um ciclo, retorna
        if(encontrado)
            return;

        int xn = x + dx[i], yn = y + dy[i];

        // vai para a próxima se for a casa pai ou se não for possível pular para essa nova casa
        if(xn == xPai && yn == yPai || !possible(xn, yn))
            continue;   

        // verifica se as letras são iguais
        if(grid[x][y] == grid[xn][yn]){

            // se a casa atual já foi visitada e a quantidade de k's encontrados for maior ou igual a 4, encontramos um ciclo
            if(visitado[xn][yn] && qtdKs[x][y] >= 3){
                encontrado = 1;
                return;
            } else if(!visitado[xn][yn]){
                qtdKs[xn][yn] = qtdKs[x][y] + 1;

                // faz o dfs da próxima casa se a casa atual não foi visitada
                dfs(make_pair(xn, yn), make_pair(x, y));
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    grid.assign(n+1, vector<char>(m+1));
    visitado.assign(n+1, vector<bool>(m+1, 0));
    qtdKs.assign(n+1, vector<int>(m+1, 0));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];

    for(int i = 0; i < n && !encontrado; ++i)
        for(int j = 0; j < m && !encontrado; ++j)
            if(!visitado[i][j])
                dfs(make_pair(i, j), make_pair(-1, -1));

    if(encontrado)
        cout << "Yes\n";
    else 
        cout << "No\n";

    return 0;
}