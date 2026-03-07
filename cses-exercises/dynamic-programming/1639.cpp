/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; ++i){
        dp[i][0] = i;
    }

    for(int j = 1; j <= m; ++j){
        dp[0][j] = j;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int distMin = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
            distMin = min(distMin, dp[i-1][j-1] + (a[i-1] != b[j-1]));

            dp[i][j] = distMin;
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}