/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, 0));

    for(int i = 1; i <= a; ++i){
        dp[i][1] = i-1;
    }

    for(int j = 1; j <= b; ++j){
        dp[1][j] = j-1;
    }

    for(int i = 2; i <= a; ++i){
        for(int j = 2; j <= b; ++j){
            if(i == j){
                continue;
            }

            dp[i][j] = 1e9;

            for(int k = 1; k < i; ++k){
                dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
            }

            for(int k = 1; k < j; ++k){
                dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
            }
        }
    }

    cout << dp[a][b] << "\n";

    return 0;
}