/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> worms(n+1, 0);

    for(int i = 1; i <= n; ++i){
        int num; cin >> num;
        worms[i] = worms[i-1] + num;
    }

    int m; cin >> m; 

    while(m--){
        int label; cin >> label;
        auto it = lower_bound(worms.begin(), worms.end(), label);
        cout << it - worms.begin() << '\n';
    }

    return 0;
}