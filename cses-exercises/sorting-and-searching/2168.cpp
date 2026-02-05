/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Intervalo{
    int inicio; int fim; int idx;
};

bool aIgual_bMaior(const Intervalo &a, const Intervalo &b){
    if(a.inicio == b.inicio){
        return a.fim > b.fim;
    }

    return a.inicio < b.inicio;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<Intervalo> intervalos;
    intervalos.reserve(n);
    
    for(int i = 0; i < n; ++i){
        int a,b; cin >> a >> b;
        intervalos.push_back({a,b,i});
    }

    sort(intervalos.begin(), intervalos.end(), aIgual_bMaior);

    // LOGICA PARA VERIFICAR SE UM INTERVALO CONTEM OUTRO
    vector<int> contem;
    contem.resize(n);

    int minFim = intervalos[n-1].fim;
    contem[intervalos[n-1].idx] = 0;
    
    for(int i = n-2; i >= 0; --i){
        Intervalo intervalo = intervalos[i];
        contem[intervalo.idx] = intervalo.fim >= minFim;
        minFim = min(minFim, intervalo.fim);
    }

    for(auto& res : contem){
        cout << res << " ";
    }
    cout << "\n";

    // LOGICA PARA VERIFICAR SE UM INTERVALO ESTA CONTIDO EM OUTRO
    vector<int> contido;
    contido.resize(n);

    int maxFim = intervalos[0].fim;
    contido[intervalos[0].idx] = 0;

    for(int i = 1; i < n; ++i){
        Intervalo intervalo = intervalos[i];
        contido[intervalo.idx] = intervalo.fim <= maxFim;
        maxFim = max(maxFim, intervalo.fim);
    }

    for(auto& res : contido){
        cout << res << " ";
    }
    cout << "\n"; 
    
    return 0;
}