/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, q; cin >> n >> q;
    vector<long long> prefixSum(n+1, 0);

    for(int i = 1; i <= n; ++i){
        int aux; cin >> aux;
        prefixSum[i] = prefixSum[i-1] + aux;
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << prefixSum[b] - prefixSum[a-1] << '\n';
    }

    return 0;
}