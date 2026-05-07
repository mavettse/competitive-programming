/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9+7, N_MAX = 1e6;
ll fat[2*N_MAX+1];

// calcula o fatorial de todos os números até 10^6
void fatorial(){
    fat[0] = 1;

    for(int i = 1; i <= 2*N_MAX; ++i)
        fat[i] = (fat[i-1] * i) % MOD;
}

// exponenciação rápida
ll power(ll x, ll y, ll m){
    ll ret = 1; 

    while(y){
        if(y & 1)
            ret = (ret * x) % m;

        y >>= 1;
        x = (x * x) % m;
    }

    return ret; 
}

// o problema é combinação com repetição: C(n,m) = (n+m-1)! / (m!(n-1)!)
// precisa do pequeno teorema de fermat para calcular a divisão com MOD

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    fatorial();

    // a = (n+m-1)!, b = m!(n-1)!
    ll a = fat[n+m-1], b = (fat[m] * fat[n-1]) % MOD;
    
    // utiliza o pequeno teorema de fermat para a divisão modular (a/b)
    // b^(-1) = b^(MOD-2)) % MOD
    b = power(b, MOD-2, MOD);

    // divisão modular = ((a % MOD) * b^(MOD-2)) % MOD
    cout << ((a % MOD) * b) % MOD << '\n';

    return 0;
}