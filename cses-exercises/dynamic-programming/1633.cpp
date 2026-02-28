/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

const long long MODULO = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<long long> dp(n+1, 0);
    dp[0] = 1;

    long long janela = dp[0];

    for(int i = 1; i <= n; ++i){
        if(i <= 6){
            dp[i] = janela;
            janela += dp[i];
            continue;
        }

        janela = (janela - dp[i-7] + MODULO) % MODULO;
        dp[i] = janela;
        janela = (janela + dp[i]) % MODULO;
    }

    cout << dp[n] << "\n";
    
    return 0;
}