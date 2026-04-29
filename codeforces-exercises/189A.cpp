/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int w[3];

void knapsack(int cap){
    for(int i = 0; i < 3; ++i) 
        for(int j = w[i]; j <= cap; ++j)
            if(j - w[i] >= 0)
                dp[j] = max(dp[j], dp[j - w[i]] + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int cap; cin >> cap; 

    dp.assign(cap+1, -1e9);
    dp[0] = 0;

    for(int i = 0; i < 3; ++i)
        cin >> w[i];
    
    knapsack(cap);

    cout << dp[cap] << '\n';
    
    return 0;
}