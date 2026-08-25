/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, MAX = 1005;
int dp[MAX][MAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            char c; cin >> c; 

            if(c == '*'){
                if(i == 1 && j == 1)
                    break;
            
                continue;
            }

            dp[i][j] = (dp[i-1][j] % MOD) + (dp[i][j-1] % MOD);
        }
    }

    cout << dp[n][n] % MOD << '\n';

    return 0;
}