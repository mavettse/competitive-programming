/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <cstring>

using namespace std;

int n, m; 
long long dp[1001][1<<10]; // {coluna, máscara}
const int MODULO = 1e9 + 7;
long long qtdFormasAtuais;

void dfs(int linhaAtual, int colunaAtual, int mascaraAtual, int proxMascara){
    if(linhaAtual == n){
        dp[colunaAtual+1][proxMascara] = (dp[colunaAtual+1][proxMascara] + qtdFormasAtuais)%MODULO;
        return;
    }

    if((mascaraAtual & (1<<linhaAtual)) != 0){ // o quadrado atual está ocupado
        dfs(linhaAtual+1, colunaAtual, mascaraAtual, proxMascara);
    } else { // o quadrado atual não está ocupado; 2 opções: inserir um ladrilho deitado ou um ladrilho vertical
        
        if(colunaAtual+1 < m){ // deitado checa se a coluna seguinte não é a última
            dfs(linhaAtual+1, colunaAtual, mascaraAtual | (1<<linhaAtual), proxMascara | (1<<linhaAtual));
        }

        if(linhaAtual+1 < n && (mascaraAtual & 1<<(linhaAtual+1)) == 0){ // vertical checa se a linha seguinte existe E está vazia
            dfs(linhaAtual+2, colunaAtual, mascaraAtual | (1<<linhaAtual) | (1<<(linhaAtual+1)), proxMascara);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int coluna = 0; coluna < m; ++coluna){
        for(int mascara = 0; mascara < (1<<n); ++mascara){
            if(dp[coluna][mascara] > 0){
                qtdFormasAtuais = dp[coluna][mascara];
                dfs(0, coluna, mascara, 0);
            }
        }
    }

    cout << dp[m][0] << "\n";

    return 0;
}