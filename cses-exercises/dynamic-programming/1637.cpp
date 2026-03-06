/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 0;

    for(int i = 1; i <= n; ++i){
        int maiorDigito = 0, digito = i;

        while(digito != 0){
            int resto = digito % 10; 

            maiorDigito = max(maiorDigito, resto);
            digito /= 10;
        }

        dp[i] = dp[i - maiorDigito] + 1;
    }

    cout << dp[n] << "\n";

    return 0;
}