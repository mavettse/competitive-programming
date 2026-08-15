/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> frequency(MAX, 0);
    vector<long long> dp(MAX, 0);

    while(n--){
        int num; cin >> num;
        frequency[num]++;
    }

    dp[1] = frequency[1];

    for(int i = 2; i < MAX; ++i)
        dp[i] = max(dp[i-1], (long long)i * frequency[i] + dp[i-2]);
    
    cout << dp[MAX-1] << '\n';

    return 0;
}