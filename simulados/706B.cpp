/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> prices;
    while(n--){
        int price; cin >> price;
        prices.push_back(price);
    } sort(prices.begin(), prices.end());

    int q; cin >> q;
    
    while(q--){
        int budget; cin >> budget;
        auto it = upper_bound(prices.begin(), prices.end(), budget);
        cout << it - prices.begin() << '\n';
    }

    return 0;
}