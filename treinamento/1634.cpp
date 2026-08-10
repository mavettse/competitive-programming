/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> coins(n, 0);

    for(int& coin : coins)
        cin >> coin;
    sort(coins.begin(), coins.end());

    vector<int> dp(x+1, INF);
    dp[0] = 0;

    for(int i = 1; i <= x; ++i)
        for(auto it = coins.rbegin(); it != coins.rend(); ++it)
            if(i - *it >= 0 && dp[i - *it] != INF)
                dp[i] = min(dp[i], dp[i - *it] + 1);

    cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
                
    return 0;
}