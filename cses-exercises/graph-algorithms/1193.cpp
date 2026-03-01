/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n, m; 
pair<int,int> inicio;
vector<vector<int>> visitado;
vector<vector<char>> labirinto;
vector<vector<char>> passos;
vector<int> dc = {1, -1, 0,  0}, dl = {0,  0, 1, -1}; // {DIR, ESQ, BAIXO, CIMA}
vector<char> direcao = {'R', 'L', 'D', 'U'};
queue<pair<int,int>> fila;
stack<char> passosFinais;

void reconstruirCaminho(int linha, int coluna){
    while(!(linha == inicio.first && coluna == inicio.second)){
        char passo = passos[linha][coluna];
        passosFinais.push(passo);

        switch(passo){
            case 'R':
                coluna--;
                break;
            case 'L':
                coluna++;
                break;
            case 'D':
                linha--;
                break;
            case 'U':
                linha++;
                break;
        }
    }
}

void bfs(int linha, int coluna){
    visitado[linha][coluna] = 1;
    fila.push({linha, coluna});

    while(!fila.empty()){
        pair<int,int> quadrado = fila.front(); 
        fila.pop();

        for(int i = 0; i < 4; ++i){
            int nLinha = quadrado.first+dl[i], nColuna = quadrado.second+dc[i];

            if(visitado[nLinha][nColuna] || labirinto[nLinha][nColuna] == '#'){
                continue;
            }

            visitado[nLinha][nColuna] = 1;
            passos[nLinha][nColuna] = direcao[i];
            fila.push({nLinha, nColuna});

            if(labirinto[nLinha][nColuna] == 'B'){
                reconstruirCaminho(nLinha, nColuna);
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    labirinto.assign(n+2, vector<char>(m+2, '#'));
    visitado.assign(n+2, vector<int>(m+2, 0));
    passos.assign(n+2, vector<char>(m+2, '#'));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char descricao; cin >> descricao;
            labirinto[i][j] = descricao;

            if(descricao == 'A'){
                inicio = {i,j};
            }
        }
    }

    bfs(inicio.first, inicio.second);

    if(passosFinais.empty()){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n" << passosFinais.size() << "\n";

    while(!passosFinais.empty()){
        cout << passosFinais.top();
        passosFinais.pop();
    }

    return 0;
}