/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

const long long MODULO = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<char>> grade(n+1, vector<char>(n+1,' '));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            char quadrado; cin >> quadrado;
            grade[i][j] = quadrado;
        }
    }

    if(grade[1][1] == '*' || grade[n][n] == '*'){
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    dp[1][1] = 1;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(grade[i][j] != '*'){
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % MODULO;
            }
        }
    }

    cout << dp[n][n] << "\n";

    return 0;
}