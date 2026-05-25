/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;

    // função lambda para inserir no map; 
    // quem tiver maior qtd problemas resolvidos fica antes; se tiverem qtd problemas iguais, quem tiver o menor tempo fica antes
    auto comp = [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    };

    map<pair<int, int>, int, decltype(comp)> times(comp); // times[qtdProblemas, tempo] = qtdTimes

    for(int i = 0; i < n; ++i){
        int p, t; cin >> p >> t;
        times[{p,t}]++;
    }

    int colocacao = 0;

    for(auto [time, qtdTimes] : times){
        auto [p, t] = time;

        colocacao += qtdTimes;

        if(colocacao >= k){
            cout << qtdTimes << '\n';
            break;
        }
    }

    return 0;
}