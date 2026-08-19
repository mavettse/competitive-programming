/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;

    map<ll, int> prefixSum; // prefixSum[sum] = frequency
    prefixSum[0] = 1;
    ll curSum = 0, subarrays = 0;

    for(int i = 0; i < n; ++i){
        int num; cin >> num;
        curSum += num;
        
        auto found = prefixSum.find(curSum - x);
        
        if(found != prefixSum.end())
            subarrays += found->second;

        prefixSum[curSum]++;
    }

    cout << subarrays << endl;

    return 0;
}