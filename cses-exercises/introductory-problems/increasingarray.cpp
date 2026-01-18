#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    long long numAnterior, numAtual, valorMin = 0;

    cin >> numAnterior;

    for(int i = 1; i < n; ++i){
        cin >> numAtual;

        if(numAtual < numAnterior){
            long long diferenca = numAnterior - numAtual;
            valorMin += diferenca;
            numAtual += diferenca;
        }

        numAnterior = numAtual;
    }

    cout << valorMin << "\n";

    return 0;
}