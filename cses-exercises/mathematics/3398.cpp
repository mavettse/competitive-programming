/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9+7;
vector<int> maiorExp;

// fatora os números dos ciclos e salva os maiores expoentes de suas respectivas bases no vetor maiorExp 
void fatorar(int n){
    for(int i = 2; i * i <= n; i++){
        int cont = 0;

        while(n % i == 0){
            n /= i;
            cont++;
        }

        maiorExp[i] = max(maiorExp[i], cont);
    }

    // ao final, se n ainda for maior que 1, sobrou um número primo
    if(n > 1)
        maiorExp[n] = max(maiorExp[n], 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<int> p(n+1); 
    maiorExp.assign(n+1, 0);

    for(int i = 1; i <= n; ++i)
        cin >> p[i];

    vector<bool> visitados(n+1, 0);
    vector<int> ciclos;

    for(int i = 1; i <= n; ++i){
        if(visitados[p[i]])
            continue;

        int aux = p[i], cont = 1;

        // encontra, marca como visitado as posições que fazem parte do ciclo e conta quantos rounds precisam passar até que a posição retorne à sua posição inicial 
        while(p[aux] != p[i]){
            visitados[aux] = 1;
            aux = p[aux];
            cont++;
        } visitados[aux] = 1;

        ciclos.emplace_back(cont);
    }

    for(auto ciclo : ciclos)
        fatorar(ciclo);
    
    ll resp = 1;

    for(int i = 2; i <= n; ++i)
        while(maiorExp[i] > 0){
            resp = (resp * i) % MOD;
            maiorExp[i]--; 
        }
    
    cout << resp << '\n';

    return 0;
}