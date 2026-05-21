/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    char curC, prevC; cin >> prevC;
    int qtdRetiradas = 0;

    for(int i = 1; i < n; ++i){
        cin >> curC;
        
        if(curC == prevC)
            qtdRetiradas++;

        prevC = curC;
    }

    cout << qtdRetiradas << '\n';

    return 0;
}