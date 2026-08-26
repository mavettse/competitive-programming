/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> arr;
int n, k;

bool isPossible(ll mid){
    int curSubarrays = 1;
    ll curSum = 0;

    for(int i = 0; i < n; ++i){
        if(curSum + arr[i] > mid){
            curSubarrays++;
            curSum = 0;
        } 

        curSum += arr[i];
    }

    return curSubarrays <= k;
}

ll binarySearch(ll l, ll r){
    ll ans = 0;

    while(l <= r){
        ll mid = (r-l)/2 + l;

        if(isPossible(mid)){
            ans = mid;
            r = mid - 1;
        } else 
            l = mid + 1;
    }

    return ans; 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    arr.assign(n, 0);
    ll r = 0, l = 0;

    for(auto& num : arr){
        cin >> num;
        l = max(num, l);
        r += num;
    }

    cout << binarySearch(l, r) << endl;

    return 0;
}