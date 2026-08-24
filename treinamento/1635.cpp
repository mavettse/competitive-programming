/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> dp(x+1, 0), coins(n);
    dp[0] = 1;

    for(int i = 0; i < n; ++i)
        cin >> coins[i];
    sort(coins.begin(), coins.end());

    for(int i = 1; i <= x; ++i){
        for(auto coin : coins){
            if(coin > i)
                break;

            dp[i] = (dp[i] + dp[i-coin]) % MOD;
        }
    }

    cout << dp[x] << endl;

    return 0;
}