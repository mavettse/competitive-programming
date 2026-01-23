/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

int tabuleiro[8][8] = {0};
int numManeiras = 0;

bool colunas[8] = {false};
bool diags1[15] = {false};
bool diags2[15] = {false};

int solucao(int linha){
    if(linha == 8){
        return ++numManeiras;
    }

    for(int coluna = 0; coluna < 8; ++coluna){
        if(!colunas[coluna] && tabuleiro[linha][coluna] == 0 && !diags1[linha - coluna + 7] && !diags2[linha + coluna]){
            
            colunas[coluna] = true;
            tabuleiro[linha][coluna] = 1;
            diags1[linha - coluna + 7] = true;
            diags2[linha + coluna] = true;
            
            solucao(linha + 1);     

            colunas[coluna] = false;
            tabuleiro[linha][coluna] = 0;
            diags1[linha - coluna + 7] = false;
            diags2[linha + coluna] = false;
        }
    }

    return numManeiras;
}

int main(){

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            char c; 
            cin >> c;

            if(c == '*'){
                tabuleiro[i][j] = -1;
            }
        }
    }

    cout << solucao(0) << "\n";

    return 0;
}