/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

struct No{
    long long valor;
    int idFT;
    int tamSubTree;
};

int n;
vector<vector<int>> adj;
vector<long long> ft;
vector<No> arvore;

int i = 1;

void dfs(int noAtual, int noPai){
    arvore[noAtual].tamSubTree = 1;
    arvore[noAtual].idFT = i++;
    
    for(auto const& noFilho : adj[noAtual]){
        if(noFilho == noPai){
            continue;
        }

        dfs(noFilho, noAtual);
        arvore[noAtual].tamSubTree += arvore[noFilho].tamSubTree;
    }
}

long long sum(int k){
    long long s = 0;

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
    adj.assign(n+1, vector<int>());
    ft.resize(n+1, 0);
    arvore.resize(n+1);

    for(int i = 1; i <= n; ++i){
        cin >> arvore[i].valor;
    }

    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    for(int i = 1; i <= n; ++i){
        int idFT = arvore[i].idFT, valor = arvore[i].valor;
        add(idFT, valor);

        int fimSubTree = idFT + arvore[i].tamSubTree;
        add(fimSubTree, -valor);
    }

    for(int i = 0; i < q; ++i){
        int opcao, s; cin >> opcao >> s;

        if(opcao == 1){
            int x; cin >> x;

            int idFT = arvore[s].idFT, delta = x - arvore[s].valor;
            arvore[s].valor = x;
            add(idFT, delta);

            int fimSubTree = idFT + arvore[s].tamSubTree;
            add(fimSubTree, -delta);
        } else if(opcao == 2){
            int idFT = arvore[s].idFT;
            cout << sum(idFT) << '\n';
        }
    }
    
    return 0;
}