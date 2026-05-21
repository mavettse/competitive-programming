/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n; 
    vector<int> precosBebidas;
    precosBebidas.reserve(n);

    while(n--){
        int x; cin >> x; 
        precosBebidas.emplace_back(x);
    } sort(precosBebidas.begin(), precosBebidas.end());

    int q; cin >> q;

    for(int i = 0; i < q; ++i){
        int m; cin >> m;
        cout << (upper_bound(precosBebidas.begin(), precosBebidas.end(), m) - precosBebidas.begin()) << '\n';
    }

    return 0;
}