/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        ll sumYasser = 0, sumAdel, curSum, maxSum;

        for(int i = 0; i < n; ++i){
            cin >> a[i];
            sumYasser += a[i];
        }

        curSum = maxSum = a[1];

        for(int i = 2; i < n; ++i){
            curSum = max(curSum + a[i], a[i]);
            maxSum = max(maxSum, curSum);
        }

        sumAdel = maxSum;
        curSum = maxSum = a[0];

        for(int i = 1; i < n-1; ++i){
            curSum = max(curSum + a[i], a[i]);
            maxSum = max(maxSum, curSum);
        } 

        sumAdel = max(sumAdel, maxSum);

        cout << (sumYasser > sumAdel ? "YES\n" : "NO\n");
    }

    return 0;
}