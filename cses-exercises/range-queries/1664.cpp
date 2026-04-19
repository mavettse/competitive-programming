/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int TEMPO_MAX = 1e6+1;
const int LOG_TEMPO = 20;

int dp[(int)1e6][20]; // dp[tempoAtual][2^qtdFilmes] = horarioTérmino

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q; 

    for(int i = 0; i < TEMPO_MAX; ++i){
        dp[i][0] = TEMPO_MAX;
    }

    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        dp[a][0] = min(dp[a][0], b); // fica com o menor horário de término possível, para o caso de ter dois filmes com o mesmo horário de início
    }

    for(int i = TEMPO_MAX - 2; i >= 0; --i){
        dp[i][0] = min(dp[i+1][0], dp[i][0]); // propaga o menor horário de término a depender do horário de chegada
    }

    for(int j = 1; j < LOG_TEMPO; ++j){
        for(int i = 1; i < TEMPO_MAX; ++i){
            if(dp[i][j-1] < TEMPO_MAX){
                dp[i][j] = dp[ dp[i][j-1] ][j-1];
            } else {
                dp[i][j] = TEMPO_MAX; // não é possível assistir a essa quantidade de filems
            }
        }
    }

    for(int i = 0; i < q; ++i){
        int chegada, saida; cin >> chegada >> saida;

        int qtdFilmes = 0, tempoAtual = chegada;

        for(int j = LOG_TEMPO-1; j >= 0; --j){
            if(dp[tempoAtual][j] <= saida){
                tempoAtual = dp[tempoAtual][j];
                qtdFilmes += (1<<j); // soma 2^j filmes
            }
        }

        cout << qtdFilmes << '\n';
    }

    return 0;
}