/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std; 

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> adj(n+1);

    for(int i = 1; i <= n; ++i){
        cin >> adj[i];
    }

    vector<int> dp(n+1, 0), estado(n+1, 0), passos(n+1, 0);

    for(int i = 1; i <= n; ++i){
        if(estado[i] != 0){
            continue;
        }
        
        vector<int> caminho; 

        int atual = i, passo = 0;

        while(estado[atual] == 0){
            estado[atual] = 1; // estados: {0 - nunca visitado; 1 - visitado agora; 2 - visitado e calculado}
            caminho.push_back(atual);
            passos[atual] = ++passo;
            atual = adj[atual];
        }

        int ultimo = caminho.back();

        if(estado[atual] == 1){
            int tamanhoCiclo = passos[ultimo] - passos[atual] + 1;

            do{
                ultimo = caminho.back();
                caminho.pop_back();

                estado[ultimo] = 2;
                dp[ultimo] = tamanhoCiclo;
            } while(ultimo != atual);
        }

        int contador = 1;

        while(!caminho.empty()){
            ultimo = caminho.back();
            caminho.pop_back();

            estado[ultimo] = 2;
            dp[ultimo] = dp[atual] + contador++;
        }
    }
    
    for(int i = 1; i <= n; ++i){
        cout << dp[i] << ' ';
    }

    cout << '\n';
    
    return 0;
}