/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    ll somaAtual = -1e10, somaGlobal = -1e10;

    for(int i = 0; i < n; ++i){
        int numAtual; cin >> numAtual;

        somaAtual = max((ll)numAtual, somaAtual + numAtual);
        somaGlobal = max(somaGlobal, somaAtual);
    }

    cout << somaGlobal << '\n';

    return 0;
}