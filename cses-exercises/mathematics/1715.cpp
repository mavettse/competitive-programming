/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N_MAX = 1e6, MOD = 1e9+7;
ll fat[N_MAX+1];

// computa os fatoriais de 0 até 10^6 em off
void fatorial(){
    fat[0] = 1;

    for(int i = 1; i <= N_MAX; ++i)
        fat[i] = (fat[i-1] * i) % MOD;
}

// exponenciação rápida
// x^y mod m
ll power(ll x, ll y, ll m){
    ll ret = 1;

    while(y){
        if(y & 1)
            ret = (ret * x) % m;
        y >>= 1;
        x = (x*x) % m;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fatorial();

    string s; cin >> s;
    int n = s.length();

    int alfabeto[26];
    memset(alfabeto, 0, sizeof(alfabeto));

    for(char c : s)
        alfabeto[c - 'a']++;

    ll diffStr = fat[n];

    for(int qtd : alfabeto)
        if(qtd > 1)
            diffStr = ((diffStr % MOD) * power(fat[qtd], MOD-2, MOD)) % MOD;
        
    cout << diffStr << '\n';

    return 0;
}