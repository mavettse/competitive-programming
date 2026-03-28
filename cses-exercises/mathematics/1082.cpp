/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
using namespace std;

const int MODULO = 1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    long long soma = 0, esq = 1, dir;

    while(esq <= n){
        long long divisores = n/esq;
        dir = n/divisores;

        long long qtdTermos = dir-esq+1, somaTermos = esq+dir;

        if(qtdTermos % 2 == 0){
            qtdTermos /= 2;
        } else {
            somaTermos /= 2;
        }

        long long somaGauss = ((qtdTermos % MODULO) * (somaTermos % MODULO)) % MODULO;

        soma = (soma + (somaGauss * divisores)) % MODULO;

        esq = dir + 1;
    }

    cout << soma << '\n';

    return 0;
}