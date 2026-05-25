/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    vector<int> cartas(n);

    for(int i = 0; i < n; ++i)
        cin >> cartas[i];

    int s = 0, d = 0;

    for(int esq = 0, dir = n-1, count = 0; esq <= dir; ++count){
        int maiorCarta = 0;

        if(cartas[esq] > cartas[dir])
            maiorCarta = cartas[esq++];
        else
            maiorCarta = cartas[dir--];

        if(count % 2 == 0)
            s += maiorCarta;
        else 
            d += maiorCarta;
    }

    cout << s << ' ' << d << '\n';

    return 0;
}