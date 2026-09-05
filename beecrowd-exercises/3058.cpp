/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    double cheaper = 1e5, p;
    int g; 

    while(n--){
        cin >> p >> g;
        cheaper = min(cheaper, p/g);
    }

    cout << fixed << setprecision(2) << cheaper*1000 << endl;

    return 0;
}