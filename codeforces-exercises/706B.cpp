/*
Armazenar os preços em ordem crescente; utilizar um upperbound do valor e contar quantos são menores ou iguais a ele (em quantas lojas vai dar pra comprar)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> prices(n);
    for(auto& price : prices) cin >> price;
    sort(prices.begin(), prices.end());

    int q; cin >> q;

    while(q--){
        int m; cin >> m;
        cout << upper_bound(prices.begin(), prices.end(), m) - prices.begin() << '\n';
    }

    return 0;
}