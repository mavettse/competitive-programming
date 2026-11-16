/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, ans = 1; cin >> n;

    for(int i = 2, f = 4; i <= n; ++i, f+=4) ans += f;

    cout << ans << '\n';

    return 0;
}