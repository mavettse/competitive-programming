/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int rounds = 0;
    vector<int> posicoes(n+1, 0);
    vector<int> valores(n+1, 0);

    for(int i = 1; i <= n; ++i){
        int numAtual;
        cin >> numAtual;

        if(!posicoes[numAtual - 1]){
            rounds++;
        }

        valores[i] = numAtual;
        posicoes[numAtual] = i;
    }

    for(int i = 0; i < m; ++i){
        int pos1, pos2;
        cin >> pos1 >> pos2;

        set<pair<int,int>> pares;

        int val1 = valores[pos1];
        int val2 = valores[pos2];

        if(val1-1 != 0){
            pares.insert({val1-1, val1});
        }

        if(val1+1 <= n){
            pares.insert({val1,val1+1});
        }

        if(val2-1 != 0){
            pares.insert({val2-1, val2});
        }

        if(val2+1 <= n){
            pares.insert({val2,val2+1});
        }

        for(auto par : pares){ // teste antes da troca
            if(posicoes[par.second] < posicoes[par.first]){
                rounds--;
            }
        }

        val1 = valores[pos2];
        val2 = valores[pos1];

        valores[pos1] = val1; 
        valores[pos2] = val2;

        posicoes[val1] = pos1;
        posicoes[val2] = pos2;

        for(auto par : pares){ // teste depois da troca
            if(posicoes[par.second] < posicoes[par.first]){
                rounds++;
            }
        }
       
        cout << rounds << "\n";           
    }
    
    return 0;
}