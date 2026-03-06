/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;

    vector<int> h(n+1,0), s(n+1,0);

    for(int i = 1; i <= n; ++i){
        int valor; cin >> valor;
        h[i] = valor;
    }

    for(int i = 1; i <= n; ++i){
        int paginas; cin >> paginas;
        s[i] = paginas;
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1,0));

    for(int i = 1; i <= n; ++i){ // i: livro atual, j: orçamento atual
        for(int j = 0; j <= x; ++j){
            if(j - h[i] >= 0){
                dp[i][j] = dp[i - 1][j - h[i]] + s[i];
            }

            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    cout << dp[n][x] << "\n";

    return 0;
}