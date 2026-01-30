/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    long long k; 

    for(int i = 0; i < q; ++i){
        cin >> k;

        long long qtdNum = 9;
        long long digitos = 1;
        long long qtdCarac = 9;

        while(k > qtdCarac){
            k -= qtdCarac;

            qtdNum *= 10;
            digitos ++;
            qtdCarac = qtdNum * digitos;
        }

        k--;

        long long numInteiros = k / digitos;
        long long pos = k % digitos;
        
        long long numero = qtdNum/9 + numInteiros;
        string numPos = to_string(numero);

        cout << numPos[pos] << "\n";
    }

    return 0;
}