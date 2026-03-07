/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> array1(n, 0), array2(m, 0);

    for(int i = 0; i < n; ++i){
        cin >> array1[i];
    }

    for(int j = 0; j < m; ++j){
        cin >> array2[j];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[i][j] = (array1[i-1] == array2[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << "\n";

    int i = n, j = m;

    vector<int> subsequencia;
    subsequencia.reserve(dp[n][m]);

    while(i != 0 && j != 0){
        if(array1[i-1] == array2[j-1]){
            subsequencia.push_back(array1[i-1]);
            i--; j--;
        } else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        } else {
            j--;
        }
    }

    for(auto num = subsequencia.rbegin(); num != subsequencia.rend(); ++num){
        cout << *num << " ";
    } cout << "\n";

    return 0;
}