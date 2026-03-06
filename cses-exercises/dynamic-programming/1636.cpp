/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

const long long MODULO = 1e9 + 7;

using namespace std;

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x; cin >> n >> x;

    vector<int> moedas(n, 0);

    for(int i = 0; i < n; ++i){
        int valorMoeda; cin >> valorMoeda;
        moedas[i] = valorMoeda;
    }

    sort(moedas.begin(), moedas.end());

    vector<long long> dp(x+1, 0);
    dp[0] = 1;

    for(int moeda : moedas){
        for(int i = 1; i <= x; ++i){
            if(i < moeda){
                continue;
            }

            dp[i] = (dp[i] + dp[i - moeda]) % MODULO;
        }
    }

    cout << dp[x] << "\n";

    return 0;
}