/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, a, b; cin >> n >> a >> b;
    ll maxSum = -1e18;
    vector<ll> prefixSum(n+1, 0);
    multiset<ll> candidates;

    for(int i = 1; i <= n; ++i){
        int num; cin >> num;
        prefixSum[i] = prefixSum[i-1] + num;
    }

    int aux = a;
    while(aux < b)
        candidates.insert(prefixSum[aux++]);

    for(int i = 1; i <= n; ++i){        
        int maxIdx = i+b-1;
        if(maxIdx <= n)
            candidates.insert(prefixSum[maxIdx]);

        if(candidates.empty())
            break;

        maxSum = max(maxSum, *candidates.rbegin() - prefixSum[i-1]);
                
        auto it = candidates.find(prefixSum[i+a-1]);
        if(it != candidates.end())
            candidates.erase(it);
    }

    cout << maxSum << '\n';
    
    return 0;
}