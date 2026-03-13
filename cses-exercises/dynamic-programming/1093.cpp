/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

const int MODULO = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    long long somaGauss = ((1 + n) * n)/2;

    if(somaGauss%2 != 0){
        cout << "0\n";
        return 0;
    }

    int valorSets = somaGauss/2;
    vector<int> dp(valorSets+1, 0);
    dp[0] = 1;

    for(int i = 1; i < n; ++i){
        for(int j = valorSets; j >= i; --j){
            dp[j] = (dp[j] + dp[j-i])%MODULO;
        }
    }

    cout << dp[valorSets] << "\n";

    return 0;
}