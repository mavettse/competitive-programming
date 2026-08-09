/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> sumH(n+1, 0);

    for(int i = 1; i <= n; ++i){
        int h; cin >> h;
        sumH[i] = sumH[i-1] + h;
    }

    int minH = 2e9, idx = -1;

    for(int i = 1; i + k - 1 <= n; ++i){
        int curH = sumH[i+k-1] - sumH[i-1];

        if(curH < minH){
            minH = curH;
            idx = i;
        }
    }

    cout << idx << '\n';

    return 0;
}