/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    multiset<int> prices;

    for(int i = 0; i < n; ++i){
        int num; cin >> num;
        prices.insert(num);
    }

    for(int i = 0; i < m; ++i){
        int maxPriceCostumer; cin >> maxPriceCostumer;
        
        auto it = prices.upper_bound(maxPriceCostumer);

        if(it != prices.begin()){
            it--;
            cout << *it << '\n';
            prices.erase(it);
        } else 
            cout << "-1\n";
    }

    return 0;
}