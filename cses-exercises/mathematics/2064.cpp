/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const MOD = 1e9+7, N_MAX = 1e6;
ll fat[N_MAX + 2];

// pré-calcula os fatoriais até N_MAX + 1
void fatorial(){
    fat[0] = 1; 

    for(int i = 1; i <= N_MAX + 1; ++i)
        fat[i] = (fat[i-1] * i) % MOD;
}

// faz a exponenciação rápida: x^y % MOD
ll power(ll x, ll y){
    ll ret = 1;

    while(y){
        if(y & 1)
            ret = (ret * x) % MOD;

        y >>= 1;
        x = (x * x) % MOD;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    if(n % 2 != 0){
        cout << "0\n";
        return 0;
    }

    // o problema possui os números de catalan: fórmula Cn = (2n)! / ( (n+1)! * n! )
    // como resposta para todo n que é um número par
    // como os ímpares não contam, o número de catalan n será o n/2 da entrada, logo:
    n /= 2;

    fatorial();
    ll a = fat[2 * n], b = (fat[n+1] * fat[n]) % MOD;

    // utiliza do pequeno teorema de fermat para fazer a divisão modular: b^(-1) = b^(MOD-2) % MOD
    b = power(b, MOD-2);

    // divisão modular = ( (a % MOD) * (b^(MOD - 2) % MOD)) % MOD
    cout << ( (a % MOD) * b ) % MOD << '\n';

    return 0;
}