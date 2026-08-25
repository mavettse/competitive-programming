/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, MAX = 1e6+1;
int dp[MAX], diceNums[] = {1,2,3,4,5,6};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i = 1; i <= n; ++i){
        for(auto dice : diceNums){
            if(dice > i)
                break;

            dp[i] = (dp[i] % MOD) + (dp[i-dice] % MOD);
        }
    }

    cout << dp[n] % MOD << endl;

    return 0;
}