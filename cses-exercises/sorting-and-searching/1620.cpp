/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, t; cin >> n >> t;

    vector<int> tempoMaquinas(n,0);

    for(int i = 0; i < n; ++i){
        int tempoMaquina; cin >> tempoMaquina;
        tempoMaquinas[i] = tempoMaquina;
    }

    long long tempoMin = 1, tempoMax = 1e18, candidato = 1e18;

    while(tempoMin <= tempoMax){
        long long produtos = 0;
        long long tempo = tempoMin + (tempoMax - tempoMin)/2;

        for(int tempoMaquina : tempoMaquinas){
            produtos += tempo/tempoMaquina;
            if(produtos >= t){
                break;
            }
        }

        if(produtos < t){
            tempoMin = tempo + 1;
        } else if (produtos >= t){
            tempoMax = tempo - 1;
            candidato = min(candidato, tempo);
        }
    }

    cout << candidato << "\n";
    
    return 0;
}