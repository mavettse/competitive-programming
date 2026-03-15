/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Projeto{
    int inicio;
    int fim;
    int recompensa;
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n; 
    vector<Projeto> projetos(n);

    for(int i = 0; i < n; ++i){
        cin >> projetos[i].inicio >> projetos[i].fim >> projetos[i].recompensa;
    }

    sort(projetos.begin(), projetos.end(), [](const Projeto& a, const Projeto& b) {
        return a.fim < b.fim;
    });

    vector<long long> dp(n+1, 0);

    for(int i = 0; i < n; ++i){
        int esq = 0, dir = i - 1, melhorIndice = -1;

        while(esq <= dir){
            int meio = esq + (dir - esq)/2;

            if(projetos[meio].fim < projetos[i].inicio){
                melhorIndice = meio;
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }
        }

        long long recProjAnt = 0;

        if(melhorIndice != -1){
            recProjAnt = dp[melhorIndice + 1];
        }

        dp[i+1] = max(dp[i], projetos[i].recompensa + recProjAnt);
    }

    cout << dp[n] << "\n";

    return 0;
}