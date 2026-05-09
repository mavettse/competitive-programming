/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

const int MOD = 1e9+7, N_MAX = 1e6;
ll dp[N_MAX+1]; // dp[qtd crianças] = num combinações possíveis

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // inicializando valores iniciais da quantidade de combinações para qtd crianças menor que 3
    dp[0] = 0; dp[1] = 0; dp[2] = 1;

    int n; cin >> n;

    // uma criança inicial i tem i-1 crianças para dar o seu presente. esse criança que recebe o presente da primeira criança tem duas escolhas: retribuir o presente que foi lhe dado, o que faz com que as outras crianças i-2 crianças tenham que dar o presente entre elas; dar o presente para qualquer outra criança, o que faz com que i-1 crianças tenham que dar o presente entre elas
    for(int i = 3; i <= n; ++i)
        dp[i] = ( (i-1) * ((dp[i-1] + dp[i-2]) % MOD) ) % MOD;
    
    cout << dp[n] << '\n';

    return 0;
}