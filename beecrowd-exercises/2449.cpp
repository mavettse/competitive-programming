/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, mov = 0, prev = 0; cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        int cur; cin >> cur;
        cur += prev; 
        prev = m - cur;
        mov += abs(prev);
    }

    cout << mov << '\n';
    
    return 0;
}