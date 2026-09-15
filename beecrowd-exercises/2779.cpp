/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

bool hasStcks[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    int remainingStcks = n;

    while(m--){
        int x; cin >> x;

        if(!hasStcks[x]){
            hasStcks[x] = 1;
            remainingStcks--;
        }
    }

    cout << remainingStcks << '\n';
    
    return 0;
}