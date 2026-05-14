/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    int n = s.size();

    // dp[posicao] = qtdSubsequencias
    // dp[0] = 1 conta a subsequencia vazia (será retirada no final)
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    // guarda a última posição que as letras apareceram na string s
    vector<int> ultimaPosChar(26, 0);

    for(int i = 1; i <= n; ++i){
        // a qtd de subsequencias disponiveis com a letra atual é o dobro da qtd de subsequencias da letra anterior
        dp[i] = (2 * dp[i-1]) % MOD;

        // seleciona a posição (letra) atual
        int j = s[i-1] - 'a';

        // se a letra atual já tiver aparecido antes, subtrai todas as "colas" feitas nela 
        if(ultimaPosChar[j] != 0)
            // ajusta o index para o 0 based da dp
            dp[i] = (dp[i] - dp[ultimaPosChar[j] - 1] + MOD) % MOD; 

        // atualiza a última posição da letra para a posição atual (1 based)
        ultimaPosChar[j] = i;
    }

    // subtrai o vazio incluído na contagme
    cout << (dp[n] - 1 + MOD) % MOD << '\n';

    return 0;
}