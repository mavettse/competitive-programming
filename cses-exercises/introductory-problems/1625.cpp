/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <string>

using namespace std;

string descricao;
bool visitados[9][9] = {0};
int caminhosEncontrados = 0; 
int dc[] = {1, -1, 0,  0};
int dl[] = {0,  0, 1, -1};
char dir[] = {'R', 'L', 'D', 'U'};

void solucao(int passos, int l, int c){    
    
    if(l == 7 && c == 1){
        if(passos == 48){
            caminhosEncontrados++;
        }
        return;
    }

    // se houver uma parede ou um quadrado já ocupado na frente e o espaço na direita e na esquerda da posição atual estiverem livres, retorna 0 (não passou por todos os caminhosEncontrados da grade e vai acabar em um caminho sem saída)
    if(visitados[l+1][c] && visitados[l-1][c] && !visitados[l][c+1] && !visitados[l][c-1]){
        return;
    }

    if(visitados[l][c+1] && visitados[l][c-1] && !visitados[l+1][c] && !visitados[l-1][c]){
        return;
    }

    visitados[l][c] = true;

    if(descricao[passos] == '?'){
        for(int i = 0; i < 4; ++i){
            int nl = l + dl[i];
            int nc = c + dc[i];

            if(!visitados[l + dl[i]][c + dc[i]]){
                solucao(passos + 1, nl, nc);
            }
        }
    } else {
        for(int i = 0; i < 4; ++i){
            int nl = l + dl[i];
            int nc = c + dc[i];

            if((dir[i] == descricao[passos]) && !visitados[l + dl[i]][c + dc[i]]){
                solucao(passos + 1, nl, nc);
                break;
            }
        }
    }

    visitados[l][c] = false;
    
    return;    
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> descricao;
    
    for(int i = 0; i < 9; ++i){
        visitados[i][0] = true;
        visitados[i][8] = true;
        visitados[0][i] = true;
        visitados[8][i] = true;
    }

    solucao(0, 1, 1);
    cout << caminhosEncontrados << "\n";

    return 0;
}