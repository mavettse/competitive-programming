/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int numCompradores, numAPs, tolerancia;
    cin >> numCompradores >> numAPs >> tolerancia;

    vector<int> tamanhoDesejado;
    tamanhoDesejado.reserve(numCompradores);

    vector<int> tamanhoAPs;
    tamanhoAPs.reserve(numAPs);

    for(int i = 0; i < numCompradores; ++i){
        int aux;
        cin >> aux;
        
        tamanhoDesejado.push_back(aux);
    }    

    for(int i = 0; i < numAPs; ++i){
        int aux;
        cin >> aux;
        
        tamanhoAPs.push_back(aux);
    }    

    sort(tamanhoDesejado.begin(), tamanhoDesejado.end());
    sort(tamanhoAPs.begin(), tamanhoAPs.end());

    int pessoasComAp = 0;

    int ptrTamDsj = 0, ptrTamAPs = 0;

    while(ptrTamDsj < numCompradores && ptrTamAPs < numAPs){
        int maxAceitavel = tamanhoDesejado[ptrTamDsj] + tolerancia;
        int minAceitavel = tamanhoDesejado[ptrTamDsj] - tolerancia;
        int tamAP = tamanhoAPs[ptrTamAPs];

        if(tamAP < minAceitavel){
            ptrTamAPs++;
        } else if(tamAP > maxAceitavel){
            ptrTamDsj++;
        } else {
            pessoasComAp++;
            ptrTamDsj++;
            ptrTamAPs++;
        }
    }

    cout << pessoasComAp << "\n";

    return 0;
}