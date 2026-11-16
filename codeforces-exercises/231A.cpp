/*
Usa portas lógicas pra incrementar a resposta
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, ans = 0; cin >> n;

    while(n--){
        int p, v, t; cin >> p >> v >> t;
        ans += (p&v | p&t | v&t);
    }

    cout << ans << '\n';

    return 0;
}