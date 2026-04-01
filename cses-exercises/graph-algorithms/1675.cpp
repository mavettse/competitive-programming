/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int componentes;
long long custoMax = 0;
vector<int> pais, tamanhos;
vector<tuple<int,int,int>> estradas; // {custo, a, b}

void criarConjunto(int no){
    pais[no] = no;
    tamanhos[no] = 1;
}

int encontrarPai(int no){
    if(pais[no] == no){
        return no;
    }

    return pais[no] = encontrarPai(pais[no]);
}

void juntarConjuntos(int a, int b, int custo){
    int paiA = encontrarPai(a);
    int paiB = encontrarPai(b);

    if(paiA != paiB){
        if(tamanhos[paiA] < tamanhos[paiB]){
            swap(paiA, paiB);
        }

        componentes--;
        custoMax += custo;
        pais[paiB] = paiA;
        tamanhos[paiA] += tamanhos[paiB];
    }
}

int main(){
    int n, m; cin >> n >> m;

    componentes = n;
    pais.resize(n+1);
    tamanhos.resize(n+1);
    estradas.reserve(m);

    for(int i = 1; i <= n; ++i){
        criarConjunto(i);
    }

    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        estradas.push_back({c,a,b});
    }
    
    sort(estradas.begin(), estradas.end());

    for(auto [c,a,b] : estradas){
        juntarConjuntos(a,b,c);
    }

    if(componentes == 1){
        cout << custoMax << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}