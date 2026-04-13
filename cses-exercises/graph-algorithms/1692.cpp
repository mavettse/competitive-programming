/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
using namespace std;

vector<int> arestas;
set<string> visitados;
string alfabeto = "01";
int k = 2;

void dfs(string atual){
    for(int i = 0; i < k; ++i){
        string novaPonte = atual + alfabeto[i];

        if(visitados.find(novaPonte) == visitados.end()){
            visitados.insert(novaPonte);
            dfs(novaPonte.substr(1));
            arestas.push_back(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    string inicio(n-1, alfabeto[0]);
    dfs(inicio);

    for (int i = 0; i < (1<<n); ++i){
        cout << alfabeto[arestas[i]];
    }

    cout << inicio << '\n';

    return 0;
}