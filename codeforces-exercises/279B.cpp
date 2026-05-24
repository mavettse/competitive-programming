/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, t; cin >> n >> t;

    vector<int> tempoLivros(n);

    for(int i = 0; i < n; ++i){
        cin >> tempoLivros[i];
    }

    int esq = 0, dir = 0, tempoAtual = 0, qtdLivros = 0, qtdLivrosMax = 0;

    while(dir < n){
        tempoAtual += tempoLivros[dir];
        qtdLivros++;

        while(tempoAtual > t){
            tempoAtual -= tempoLivros[esq];
            qtdLivros--;
            esq++;
        }

        qtdLivrosMax = max(qtdLivrosMax, qtdLivros);
        dir++;
    }

    cout << qtdLivrosMax << '\n';

    return 0;
}