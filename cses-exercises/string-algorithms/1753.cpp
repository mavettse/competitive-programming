/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int A = 57, B = 1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string s, p; cin >> s >> p;
    int n = s.size(), m = p.size();

    if(m > n){
        cout << "0\n";
        return 0;
    }

    vector<long long> h(n), potencia(n);
    h[0] = s[0], potencia[0] = 1;

    for(int i = 1; i < n; ++i){
        h[i] = ((h[i-1] * A) + s[i]) % B;
        potencia[i] = (potencia[i-1] * A) % B;
    }

    long long hashPadrao = p[0];

    for(int i = 1; i < m; ++i){
        hashPadrao = ((hashPadrao * A) + p[i]) % B;
    }

    int esq = 0, dir = m-1;
    int qtdOcorrencias = 0;

    while(dir < n){
        long long hIntervalo = h[dir];

        if(esq != 0){
            hIntervalo = (hIntervalo - (h[esq-1] * potencia[dir-esq+1])) % B;
        }

        if(hIntervalo < 0){
            hIntervalo += B;
        }

        if(hIntervalo == hashPadrao){
            qtdOcorrencias++;
        }

        esq++; dir++;
    }

    cout << qtdOcorrencias << "\n";
    
    return 0;
}