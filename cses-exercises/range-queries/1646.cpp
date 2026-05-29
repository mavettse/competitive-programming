/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;

    vector<ll> prefixSum(n+1, 0);

    for(int i = 1; i <= n; ++i){
        int atual; cin >> atual;
        prefixSum[i] = prefixSum[i-1] + atual;
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << prefixSum[b] - prefixSum[a-1] << '\n';
    }

    return 0;
}