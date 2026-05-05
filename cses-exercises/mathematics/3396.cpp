/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPrime(ll n){
    if(n == 1)
        return false;

    if(n == 2)
        return true;
    
    if(n % 2 == 0)
        return false;

    for(ll i = 3; i*i <= n; i+=2)
        if(n % i == 0)
            return false;

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--){
        ll n; cin >> n;

        for(ll i = n+1; ; ++i)
            if(isPrime(i)){
                cout << i << '\n'; 
                break;
            }
    }

    return 0;
}