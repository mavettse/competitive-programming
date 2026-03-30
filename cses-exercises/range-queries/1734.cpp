/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Query{
    int inicio;
    int fim;
    int indice;
};

int n;
vector<int> ft;

int sum(int k){
    int s = 0;

    while(k >= 1){
        s += ft[k];
        k -= k&-k;
    }

    return s;
}

void add(int k, int x){
    while(k <= n){
        ft[k] += x;
        k += k&-k;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> n >> q;

    vector<int> numeros(n+1, 0);
    ft.assign(n+1, 0);

    for(int i = 1; i <= n; ++i){
        cin >> numeros[i];
    }

    vector<Query> queries(q);

    for(int i = 0; i < q; ++i){
        int a, b; cin >> a >> b;
        queries[i] = {a,b,i};
    }

    sort(queries.begin(), queries.end(), [](const Query& q1, const Query& q2) { // ordenando as queries em relação ao fim
        return q1.fim < q2.fim;
    });

    vector<int> distintos(n+1);
    vector<int> resp(q);
    map<int,int> ultimoVisto; // {número, ultimoIndiceVisto}
    
    for(int i = 1, j = 0; i <= n; ++i){
        int atual = numeros[i];

        if(ultimoVisto.find(atual) != ultimoVisto.end()){
            int indiceAntigo = ultimoVisto[atual];
            distintos[indiceAntigo] = 0;
            add(indiceAntigo, -1);
        }

        ultimoVisto[atual] = i;
        distintos[i] = 1;
        add(i, 1);

        while(j < q && queries[j].fim == i){
            int a = queries[j].inicio, b = queries[j].fim, indiceOriginal = queries[j].indice;
            resp[indiceOriginal] = sum(b) - sum(a-1); 
            j++;
        }
    }

    for(int i = 0; i < q; ++i){
        cout << resp[i] << '\n';
    }

    return 0;
}