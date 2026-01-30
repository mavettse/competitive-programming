/* GIOVANNI ESTEVAM DOS SANTOS*/

#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i){
        unsigned long long x, y;   // coluna x e linha y
        cin >> y >> x;

        unsigned long long camada = max(y,x);
        unsigned long long quadrado = camada * camada;
        unsigned long long diferenca;

        if(camada & 1){ // se a camada for ímpar, o quadrado dela está localizado na linha 1 (1,camada)
            diferenca = (y-1) + (camada-x);
        } else { // se a camada for par, o quadrado dela está localizado na coluna 1 (camada,1)
            diferenca = (camada-y) + (x-1);
        }

        cout << quadrado - diferenca << "\n";

    }

    return 0;
}