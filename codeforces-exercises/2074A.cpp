/*
Só é um quadrado se a distância da origem até os 4 pontos forem iguais
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        int l, r, d, u; cin >> l >> r >> d >> u;

        if(l+r == d+u && l == r && d == u) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}