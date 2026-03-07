/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

const long long MODULO = 1e9 + 7;
const int JUNTOS = 0, SEPARADOS = 1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    vector<int> testes(t,0);
    int maiorN = 1;

    for(int i = 0; i < t; ++i){
        int n; cin >> n;

        maiorN = max(maiorN, n);
        testes[i] = n;
    }

    vector<vector<long long>> dp(maiorN+1, vector<long long>(2, 0)); // dp[andar][juntos: 0 / separados: 1] = número de torres difrentes
    dp[1] = {1,1};

    for(int i = 2; i <= maiorN; ++i){
        dp[i][JUNTOS] = ((dp[i-1][JUNTOS]*2)%MODULO + dp[i-1][SEPARADOS])%MODULO;
        dp[i][SEPARADOS] = ((dp[i-1][SEPARADOS]*4)%MODULO + dp[i-1][JUNTOS])%MODULO;
    }

    for(int n : testes){
        cout << (dp[n][JUNTOS] + dp[n][SEPARADOS])%MODULO << "\n";
    }

    return 0;
}