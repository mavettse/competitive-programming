/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    set<int> sizes;

    for(int i = 0; i < 3; ++i){
        int ribbon; cin >> ribbon;
        sizes.insert(ribbon);
    }

    vector<int> dp(n+1, -1);
    dp[0] = 0;

    for(int i = 1; i <= n; ++i)
        for(auto j : sizes)
            if(i - j >= 0 && dp[i-j] != -1)
                dp[i] = max(dp[i-j] + 1, dp[i]);
  

    cout << dp[n] << '\n';

    return 0;
}