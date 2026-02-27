/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<pair<int,int>> horarios; // {horarioFim, horarioInicio}
    horarios.reserve(n);

    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        horarios.push_back({b, a});
    }

    sort(horarios.begin(), horarios.end());

    multiset<int> membrosAssistindo; // {horarioFim}
    int ultimoMembro = 0, qtdFilmes = 0;

    for(int i = 0; i < n; ++i){
        int inicio = horarios[i].second, fim = horarios[i].first;

        auto membroLivre = membrosAssistindo.upper_bound(inicio);

        if(membroLivre != membrosAssistindo.begin()){
            membroLivre--;
            membrosAssistindo.erase(membroLivre);
        } else if(ultimoMembro < k){
            ultimoMembro++;
        } else {
            continue;
        }

        membrosAssistindo.insert(fim);
        qtdFilmes++;
    }

    cout << qtdFilmes << "\n";
    
    return 0;
}