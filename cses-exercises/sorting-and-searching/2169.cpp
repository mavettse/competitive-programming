/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// INCLUSÃO PARA USO DE ordered_multiset
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

struct Intervalo{
    int inicio; int fim; int indiceOriginal;
};

bool organizarIntervalos(const Intervalo& a, const Intervalo& b){
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
        int inicio, fim; cin >> inicio >> fim;
        intervalos.push_back({inicio, fim, i});
    }

    sort(intervalos.begin(), intervalos.end(), organizarIntervalos);

    // LÓGICA PARA CONTAGEM DE INTERVALOS CONTENDO OUTROS
    vector<int> contem(n,0);
    ordered_multiset finsOrdenados;

    for(int i = n-1; i >= 0; --i){
        const Intervalo& intervalo = intervalos[i];

        // order_of_key retorna (qtd elmnts < atual); fazendo order_of_key(fim + 1), o retorno será (qtd elmnts <= atual)
        auto qtdFinsMenores = finsOrdenados.order_of_key(intervalo.fim + 1);
        contem[intervalo.indiceOriginal] = qtdFinsMenores;
        finsOrdenados.insert(intervalo.fim);
    }

    // LÓGICA PARA CONTAGEM DE INTERVALOS CONTIDOS EM OUTROS
    vector<int> contidos(n,0);
    finsOrdenados.clear();

    for(int i = 0; i < n; ++i){
        const Intervalo& intervalo = intervalos[i];

        // order_of_key retorna (qtd elmnts < atual); fazendo (total elmnts - order_of_key(fim)), tem-se (qtd elmnts >= atual); 
        auto qtdFinsMenores = finsOrdenados.order_of_key(intervalo.fim);
        contidos[intervalo.indiceOriginal] = finsOrdenados.size() - qtdFinsMenores;
        finsOrdenados.insert(intervalo.fim);
    }

    // IMPRESSÃO DOS RESULTADOS
    for(int num : contem){
        cout << num << " ";
    } cout << "\n";

    for(int num : contidos){
        cout << num << " ";
    } cout << "\n";

    return 0;
}