/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Hospede{
    int chegada; int saida; int indiceOriginal;
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    
    vector<Hospede> hospedes;
    hospedes.reserve(n);

    for(int i = 0; i < n; ++i){
        int c, s; cin >> c >> s;
        hospedes.push_back({c,s,i});
    }
    
    sort(hospedes.begin(), hospedes.end(), [](const Hospede& a, const Hospede& b) {
        return a.chegada < b.chegada;
    });

    int maiorNumQuarto = 0;
    multiset<pair<int,int>> quartos; // {saida, numQuarto}
    vector<int> alocacoes(n,0);

    for(int i = 0; i < n; ++i){
        Hospede& hospede = hospedes[i];
        auto quarto = quartos.begin();
        int numQuartoAtual;

        if(quarto != quartos.end() && quarto->first < hospede.chegada){
            numQuartoAtual = quarto->second;
            quartos.erase(quarto);
        } else {
            numQuartoAtual = ++maiorNumQuarto;
        }

        quartos.insert({hospede.saida, numQuartoAtual});
        alocacoes[hospede.indiceOriginal] = numQuartoAtual;
    }

    cout << maiorNumQuarto << "\n";
    for(int alocacao : alocacoes){
        cout << alocacao << " ";
    } cout << "\n";
    
    return 0;
}