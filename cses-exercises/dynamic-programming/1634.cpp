/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> moedas(n, 0);

    for(int i = 0; i < n; ++i){
        int aux; cin >> aux;
        moedas[i] = aux;
    }

    sort(moedas.begin(), moedas.end());

    vector<int> dp(x+1, -1);
    dp[0] = 0;

    for(int i = 1; i <= x; ++i){
        int minMoedas = numeric_limits<int>::max();

        for(const int& moeda : moedas){
            if(moeda > i){
                break;
            }

            if(dp[i-moeda] == -1){
                continue;
            }

            minMoedas = min(minMoedas, dp[i-moeda]);
            dp[i] = minMoedas + 1;
        }
    }

    cout << dp[x] << "\n";
    
    return 0;
}