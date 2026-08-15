/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        ll a, b = 0, s, fator = 1; cin >> a >> s;

        while(s != 0){
            int aDigit = a % 10, sDigit = s % 10, bDigit;
            a /= 10; s /= 10;
            
            if(sDigit < aDigit){
                sDigit = ((s % 10) * 10) + sDigit;
                s /= 10;
            }

            bDigit = sDigit - aDigit;

            if((s == 0 && a != 0 )|| bDigit > 9 || bDigit < 0){
                b = -1;
                break;
            }

            b = fator*bDigit + b;
            fator *= 10;
        }

        cout << b << '\n';
    }

    return 0;
}