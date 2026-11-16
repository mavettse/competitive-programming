/*
Se um número X é par, a resposta dele depende de X/2; se é ímpar, depende de X-1. Fazer esse retorno até chegar em X=1, que retorna 1. Essa questão é contar quantos bits 1 existem no número X; A função __builtin_popcount(int x) faz isso
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int x, ans = 0; cin >> x; 

    while(x){
        ans += (x & 1);
        x >>= 1;
    }

    cout << ans << '\n';

    return 0;
}