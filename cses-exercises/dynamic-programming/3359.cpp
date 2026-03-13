/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> grid;
vector<vector<int>> visitado; 
vector<char> caminho;

void bfs(){
    vector<pair<int, int>> nivelAtual, proxNivel;

    nivelAtual.push_back({0,0});

    while(!nivelAtual.empty()){
        char letraMin = 'Z' + 1;

        for(auto atual : nivelAtual){
            int l = atual.first, c = atual.second;
            letraMin = min(letraMin, grid[l][c]);
        }

        caminho.push_back(letraMin);

        for(auto atual : nivelAtual){
            int l = atual.first, c = atual.second;

            if(grid[l][c] == letraMin){
                if(!visitado[l+1][c]){
                    visitado[l+1][c] = 1;
                    proxNivel.push_back({l+1,c});
                }

                if(!visitado[l][c+1]){
                    visitado[l][c+1] = 1;
                    proxNivel.push_back({l,c+1});
                }           
            }
        }

        nivelAtual = proxNivel;
        proxNivel.clear();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    grid.assign(n+1, vector<char>(n+1, 'Z'+1));
    visitado.assign(n+1, vector<int>(n+1, 0));
    caminho.reserve(2*n - 1);

    for(int i = 0; i <= n; ++i){
        visitado[i][n] = 1;
    }

    for(int j = 0; j <= n; ++j){
        visitado[n][j] = 1;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> grid[i][j];
        }
    }

    bfs();

    for(char c : caminho){
        cout << c;
    }

    cout << "\n";

    return 0;
}