/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    string cobra(m, '#');
    string dir(m, '.'); dir.back() = '#';
    string esq(m, '.'); esq.front() = '#';

    for(int i = 0; i < n; ++i)
        if(i % 2 == 0)
            cout << cobra << '\n';
        else if(i % 4 == 1)
            cout << dir << '\n';
        else 
            cout << esq << '\n';

    return 0;
}