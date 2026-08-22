/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> a(n,0), b(n,0);
    
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n; ++i)
        cin >> b[i];

    ll l = 0, r = 2000, maxCookies = 0;

    while(l <= r){
        ll totalDebt = 0, x = (l+r)/2;

        for(int i = 0; i < n; ++i){
            ll debt = a[i]*x - b[i];

            if(debt > 0)
                totalDebt += debt;

            if(totalDebt > k){
                r = x-1;
                break;
            }
        }
        
        if(totalDebt <= k){
            maxCookies = max(maxCookies, x);
            l = x+1; 
        }
    }
        
    cout << maxCookies << '\n';
    
    return 0;
}