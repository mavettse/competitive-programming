/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x; cin >> n >> x;

    vector<int> moedas(n);

    for(int i = 0; i < n; ++i)
        cin >> moedas[i];
    sort(moedas.begin(), moedas.end());

    vector<int> dp(x+1, 1e7);
    dp[0] = 0;

    for(int i = 1; i <= x; ++i)
        for(const int& moeda : moedas){
            if(moeda > i)
                break;
            
            dp[i] = min(dp[i - moeda] + 1, dp[i]);
        }
    
    cout << ((dp[x] == 1e7) ? -1 : dp[x]) << '\n';

    return 0;
}