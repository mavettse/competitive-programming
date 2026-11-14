/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n, k, cur, prev; cin >> n >> k >> cur;
        bool canBe = 1;

        while(--n){
            prev = cur;
            cin >> cur;

            if(canBe && k == 1 && prev > cur) canBe = 0;
        }

        cout << (canBe ? "YES\n" : "NO\n");
    }

    return 0;
}