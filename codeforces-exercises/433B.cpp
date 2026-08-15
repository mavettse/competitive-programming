/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<long long> prices(n), v(n+1, 0), u(n+1, 0);

    for(int i = 0; i < n; ++i){
        cin >> prices[i];
        v[i+1] = v[i] + prices[i];
    }

    sort(prices.begin(), prices.end());

    for(int i = 0; i < n; ++i)
        u[i+1] = u[i] + prices[i];

    int m; cin >> m;

    while(m--){
        int type, l, r; cin >> type >> l >> r;

        if(type == 1)
            cout << v[r] - v[l-1] << '\n';
        else 
            cout << u[r] - u[l-1] << '\n';
    }

    return 0;
}