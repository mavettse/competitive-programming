/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

const long long MODULO = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+2, 0));

    int num; cin >> num;

    if(num == 0){
        for(int j = 1; j <= m; ++j){
            dp[1][j] = 1;
        }
    } else {
        dp[1][num] = 1;
    }

    for(int i = 2; i <= n; ++i){
        cin >> num;

        if(num != 0){
            dp[i][num] = ((dp[i-1][num-1] + dp[i-1][num])%MODULO + dp[i-1][num+1])%MODULO;
            continue;
        }

        for(int j = 1; j <= m; ++j){
            dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%MODULO + dp[i-1][j+1])%MODULO;
        }
    }

    int valorFinal = 0;

    for(int j = 1; j <= m; ++j){
        valorFinal = (valorFinal + dp[n][j])%MODULO;
    }

    cout << valorFinal << "\n";

    return 0;
}