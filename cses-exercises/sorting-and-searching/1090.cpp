/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int numCriancas, pesoMax;
    cin >> numCriancas >> pesoMax;

    vector<int> pesoCriancas;
    pesoCriancas.reserve(numCriancas);

    for(int i = 0; i < numCriancas; ++i){
        int aux;
        cin >> aux;
        
        pesoCriancas.push_back(aux);
    }

    sort(pesoCriancas.begin(), pesoCriancas.end());

    int numGondolas = 0;
    int ptrInicio = 0, ptrFim = numCriancas - 1;

    while(ptrInicio <= ptrFim){
        if(pesoCriancas[ptrInicio] + pesoCriancas[ptrFim] <= pesoMax){
            ptrInicio++;
        }

        ptrFim--;
        numGondolas++;
    }

    cout << numGondolas << "\n";

    return 0;
}