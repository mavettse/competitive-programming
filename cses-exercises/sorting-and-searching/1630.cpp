/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<pair<int,int>> tarefas; // {duração, prazo}
    tarefas.reserve(n);

    for(int i = 0; i < n; ++i){
        int duracao, prazo; cin >> duracao >> prazo;
        tarefas.push_back({duracao, prazo});
    }

    sort(tarefas.begin(), tarefas.end());

    long long recompensa = 0, tempoFim = 0;
    
    for(const auto& [duracao,prazo] : tarefas){
        tempoFim += duracao;
        recompensa += (prazo - tempoFim);
    }

    cout << recompensa << "\n";
    
    return 0;
}