/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, maxValDist; cin >> n >> maxValDist;

    vector<int> valores;

    for(int i = 0; i < n; ++i){
        int valor; cin >> valor;
        valores.push_back(valor);
    }

    unordered_map<int,int> intervalo; // {valor, quantidade}
    int ptrInicio = 0;
    long long qtdSubArrays = 0;

    for(int ptrFim = 0; ptrFim < n; ++ptrFim){
        int valor = valores[ptrFim];
        intervalo[valor]++;

        while((int)intervalo.size() > maxValDist){
            int valorInicio = valores[ptrInicio];
            intervalo[valorInicio]--;

            if(intervalo[valorInicio] == 0){
                intervalo.erase(valorInicio);
            }

            ptrInicio++;
        }

        qtdSubArrays += ptrFim - ptrInicio + 1;
    }

    cout << qtdSubArrays << "\n";

    return 0;
}