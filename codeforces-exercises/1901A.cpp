/*
maior distância entre postos (incluindo a distância entre o último posto + ida e volta até o ponto x)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n, x, maxDist = 0, pre = 0, cur; cin >> n >> x;

        while(n--){
            cin >> cur;
            maxDist = max(maxDist, cur-pre);
            pre = cur;
        }

        cout << max(maxDist, (x-cur)*2) << '\n';
    }

    return 0;
}