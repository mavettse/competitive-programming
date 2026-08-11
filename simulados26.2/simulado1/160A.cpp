/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    int left = 0;
    vector<int> coins;

    while(n--){
        int num; cin >> num;
        left += num;
        coins.emplace_back(num);
    } sort(coins.begin(), coins.end());

    int numCoins = 0, taken = 0;

    for(auto coin = coins.rbegin(); coin != coins.rend(); coin++){
        taken += *coin;
        left -= *coin;
        numCoins++;

        if(taken > left)
            break;
    }

    cout << numCoins << '\n';

    return 0;
}