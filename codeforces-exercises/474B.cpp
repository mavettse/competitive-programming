/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    vector<int> intervalos(n); // intervalos[pilha] = fimDoIntervalo
    int fim = 0;

    for(int i = 0; i < n; ++i){
        int numVermes; cin >> numVermes;
        fim += numVermes;
        intervalos[i] = fim;
    }

    int m; cin >> m;

    for(int i = 0; i < m; ++i){
        int labelVerme; cin >> labelVerme;
        auto posVerme = lower_bound(intervalos.begin(), intervalos.end(), labelVerme);

        cout << posVerme - intervalos.begin() + 1 << '\n';
    }

    return 0;
}