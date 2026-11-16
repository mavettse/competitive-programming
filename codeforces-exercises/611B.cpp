/* 
Meu pensamento inicial foi separar as bordas do meio do intervalo, somar a quantidade de números do meio e, por fim, fazer manualmente a conta da fronteira. Essa solução não funciona porque a função log2 não suportaria a restrição do problema.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll a, b; cin >> a >> b;
    int ans = 0;

    // 60 é o número máximo de bits que um número desse problema pode ter log2(10^18) = 60 aprox
    for(int bits = 60; bits > 1; --bits){
        ll mask = (1LL << bits) - 1;

        for(int j = 0; j < bits-1; ++j){
            // desliga o j-ésimo bit do número binário que só tem 1's e checa se está dentro dos limites das entradas
            ll aux = mask & ~(1LL << j);
            if(aux >= a && aux <= b) ans++;
        }
    }

    cout << ans << '\n';
    
    return 0;
}