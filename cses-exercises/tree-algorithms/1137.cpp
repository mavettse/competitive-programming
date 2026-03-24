/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

struct No{
    long long valor;
    int posTree;
    int tamSubTree;
};

int n;
vector<vector<int>> adj;
vector<long long> ft; 
vector<No> arvore;

int tempo = 1;

void dfs(int noAtual, int noPai){  
    arvore[noAtual].posTree = tempo++;
    arvore[noAtual].tamSubTree = 1;
    
    for(auto const& noFilho : adj[noAtual]){
        if(noFilho == noPai){
            continue;
        }

        dfs(noFilho, noAtual);
        arvore[noAtual].tamSubTree += arvore[noFilho].tamSubTree;
    }
}

long long soma(int k){
    long long s = 0;

    while(k >= 1){
        s += ft[k];
        k -= k&-k;
    }

    return s;
}

void add(int k, long long x){
    while(k <= n){
        ft[k] += x;
        k += k&-k;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> n >> q;
    adj.assign(n+1, vector<int>()); 
    arvore.resize(n+1);
    ft.resize(n+1, 0);

    for(int i = 1; i <= n; ++i){
        int val; cin >> val;
        arvore[i].valor = val;
    }

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b); // {nó, filhos}
        adj[b].push_back(a);
    }

    dfs(1,0);

    for(int i = 1; i <= n; ++i){
        add(arvore[i].posTree, arvore[i].valor);
    }

    for(int i = 0; i < q; ++i){
        int opcao; cin >> opcao;
        int s, x, inicio, qtd, fim;
        long long dif;

        switch(opcao){
            
            case 1: 
                cin >> s >> x;
                dif = x - arvore[s].valor;
                arvore[s].valor = x;
                add(arvore[s].posTree, dif);
                break;
            
            case 2:
                cin >> s;
                inicio = arvore[s].posTree;
                qtd = arvore[s].tamSubTree;
                fim = inicio + qtd - 1;
                cout << soma(fim) - soma(inicio - 1) << '\n';
                break;
        }
    }
    
    return 0;
}