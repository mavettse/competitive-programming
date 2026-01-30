/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int numMoedas;
    cin >> numMoedas;

    vector<int> moedas;
    moedas.reserve(numMoedas);

    for(int i = 0; i < numMoedas; ++i){
        int aux;
        cin >> aux;

        moedas.push_back(aux);
    }

    sort(moedas.begin(), moedas.end());
    long long somaAtual = 0;

    for(int moeda : moedas){
        if(somaAtual + 1 < moeda){
            break;
        }
        
        somaAtual += moeda;
    }

    cout << somaAtual + 1 << "\n";

    return 0;
}