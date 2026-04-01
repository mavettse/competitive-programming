/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

vector<int> tamanhos;
vector<int> pai;
int totalConjuntos, qtdMax = 1;

void fazerConjunto(int no){
    pai[no] = no;
    tamanhos[no] = 1;
}

int encontrarPai(int no){
    if(pai[no] == no){
        return no;
    }

    return pai[no] = encontrarPai(pai[no]);
}

void juntarConjuntos(int noA, int noB){
    int paiA = encontrarPai(noA);
    int paiB = encontrarPai(noB);

    if(paiA != paiB){
        if(tamanhos[paiA] < tamanhos[paiB]){
            swap(paiA, paiB);
        }

        pai[paiB] = paiA;
        tamanhos[paiA] += tamanhos[paiB];
        totalConjuntos--;
        qtdMax = max(qtdMax, tamanhos[paiA]);
    }
}

int main(){
    int n, m; cin >> n >> m;

    pai.assign(n+1, 0);
    tamanhos.assign(n+1, 0);
    totalConjuntos = n;

    for(int i = 1; i <= n; ++i){
        fazerConjunto(i);
    }

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        juntarConjuntos(a,b);
        cout << totalConjuntos << ' ' << qtdMax << '\n';
    }
    
    return 0;
}