/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> dp(n+1, MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; ++i){
        int copy = i; 

        while(copy != 0){
            int aux = copy%10;
            copy/=10;
            dp[i] = min(dp[i-aux] + 1, dp[i]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}