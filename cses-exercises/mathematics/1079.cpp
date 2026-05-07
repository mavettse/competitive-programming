/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9+7, MAX = 1e6;
ll fat[MAX+1];

// calcula fatorial até 10^6
void fatorial(){
    fat[0] = 1;

    for(int i = 1; i <= MAX; ++i)
        fat[i] = (fat[i-1] * i) % MOD;
}

// faz a exponenciação rapida
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

// retorna o coeficiente binomial ( a! / (b!(a-b)!) )
ll binomialCoefficient(int a, int b){
    // pega o numerador a! e o denominador b! * (a-b)!
    ll num = fat[a], den = (fat[b] * fat[a-b]) % MOD; 
    
    // ajusta o denominador para se adequar ao pequeno teorema de fermat
    // e retorna ((numerador % MOD) * denominador^(MOD-2)) % MOD
    den = power(den, MOD-2);
    return ((num % MOD) * den) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fatorial();
    
    int n; cin >> n;

    while(n--){
        int a, b; cin >> a >> b;
        cout << binomialCoefficient(a, b) << '\n';
    }

    return 0;
}