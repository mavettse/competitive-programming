/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;

    vector<int> weights(n);

    for(int i = 0; i < n; ++i)
        cin >> weights[i];
    sort(weights.begin(), weights.end());

    int l = 0, r = n-1, minGondolas = 0;

    while(l <= r){
        if(weights[l] + weights[r] <= x)
            l++;

        minGondolas++;
        r--;
    }

    cout << minGondolas << '\n';
    
    return 0;
}