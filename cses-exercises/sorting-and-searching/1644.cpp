/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <set>
#include <limits>
using namespace std; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> prefixSum(n+1,0);

    for(int i = 1; i <= n; ++i){
        int num; cin >> num;
        prefixSum[i] = prefixSum[i-1] + num;
    }

    multiset<long long> janelaPrefixos;
    long long somaMax = numeric_limits<long long>::min();

    for(int i = 1; i <= n; ++i){
        int idxMin = i-b, idxMax = i-a;

        if(idxMax < 0){
            continue;
        }

        janelaPrefixos.insert(prefixSum[idxMax]);

        int tamanhoJanela = janelaPrefixos.size();

        if(tamanhoJanela > b-a+1){
            auto deletar = janelaPrefixos.find(prefixSum[idxMin-1]);
            janelaPrefixos.erase(deletar);
        }

        long long maiorSomaAtual = prefixSum[i] - *janelaPrefixos.begin();
        somaMax = max(somaMax, maiorSomaAtual);
    }

    cout << somaMax << "\n";

    return 0;
}