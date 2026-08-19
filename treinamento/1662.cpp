/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    map<ll,ll> prefixSum; 
    prefixSum[0] = 1;
    ll curSum = 0, subarrays = 0;

    for(int i = 0; i<n; ++i){
        int num; cin >> num;
        curSum += num;

        ll target = curSum % n;
        if(target < 0)
            target += n;

        auto found = prefixSum.find(target);
        if(found != prefixSum.end())
            subarrays += found->second;
            
        prefixSum[target]++;
    }

    cout << subarrays << endl;

    return 0;
}