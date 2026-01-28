/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int numClientes;
    cin >> numClientes;

    pair<int, int> eventos;
    vector<pair<int,int>> horarios;
    horarios.reserve(numClientes << 1);

    for(int i = 0; i < (numClientes << 1); ++i){
        int aux;
        cin >> aux;

        eventos.first = aux;
        eventos.second = (i & 1) ? -1 : 1; // 1 se for chegada, -1 se for saída

        horarios.push_back(eventos);
    }

    sort(horarios.begin(), horarios.end());

    int maxClientes = 0;

    for(int i = 0, atual = 0; i < (numClientes << 1); ++i){
        if(horarios[i].second > 0){
            atual++;
        } else {
            atual--;
        }

        if(atual > maxClientes){
            maxClientes = atual;
        }
    }

    cout << maxClientes << "\n";

    return 0;
}