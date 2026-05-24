/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    
    vector<int> alturas(n);

    for(int i = 0; i < n; ++i)
        cin >> alturas[i];

    int esq = 0, dir = 0, minSoma = 1e9, soma = 0, idx = -1;

    while(dir < n){
        while(dir - esq + 1 < k){
            soma += alturas[dir];
            dir++;
        }

        soma += alturas[dir];

        if(soma < minSoma){
            idx = esq;
            minSoma = min(minSoma, soma);
        }

        dir++;
        soma -= alturas[esq];
        esq++;
    }

    cout << idx + 1 << '\n';

    return 0;
}