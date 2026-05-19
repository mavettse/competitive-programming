/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    vector<vector<int>> adj(n+1, vector<int>());

    // variaveis para fazer compressao de indices
    map<ll, int> idx; // indices[numeroOriginal] = numeroConvertido
    vector<ll> idxOriginais(n+1, 0); // indicesOriginais[numeroConvertido] = numeroOriginal
    int indice = 0;

    for(int i = 0; i < n; ++i){
        ll a, b; cin >> a >> b;

        // faz a compressao de indices e armazena os originais
        if(idx.find(a) == idx.end()){
            idx[a] = indice;
            idxOriginais[indice] = a;
            indice++;
        }
        
        if(idx.find(b) == idx.end()){
            idx[b] = indice;
            idxOriginais[indice] = b;
            indice++;
        }
        
        // pega os indices comprimidos
        int idxA = idx[a], idxB = idx[b];

        // faz o grafo nao direcional
        adj[idxA].emplace_back(idxB);
        adj[idxB].emplace_back(idxA);
    }

    // encontra um nó de grau 1 (uma "ponta", indepente se for esquerda ou direita); a ponta tem somente um outro nó ligado a ela
    int idxAtual, idxPai = -1;

    for(int i = 0; i <= n; ++i)
        if(adj[i].size() == 1){
            idxAtual = i;
            break;
        }

    vector<ll> caminho; caminho.reserve(n+1);

    int t = n+1;

    // constrói o caminho a partir da ponta
    while(t--){
        caminho.emplace_back(idxOriginais[idxAtual]);

        for(auto idxFilho : adj[idxAtual]){
            if(idxFilho == idxPai)
                continue;
            
            idxPai = idxAtual;
            idxAtual = idxFilho;
            break;
        }
    }
    
    // imprime a rota
    for(auto rota : caminho)
        cout << rota << ' ';
    cout << '\n';

    return 0;
}