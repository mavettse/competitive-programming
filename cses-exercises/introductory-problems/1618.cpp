/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

int main(){

    long long n;
    cin >> n;

    int qtdZero = 0;
    long long fator5 = 5;
    long long aux = n/fator5;

    while(aux > 0){
        qtdZero += aux;
        fator5 *= 5;
        aux = n/fator5;
    }

    cout << qtdZero << "\n";

    return 0;
}