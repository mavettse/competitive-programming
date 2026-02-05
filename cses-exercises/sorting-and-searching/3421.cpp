/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <map>

using namespace std;

long long MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int,long long> frequencia;
    
    for(int i = 0; i < n; ++i){
        int numAtual;
        cin >> numAtual;

        frequencia[numAtual] = (frequencia.find(numAtual) == frequencia.end()) ? 1 : frequencia[numAtual] + 1;
    }

    long long total = 1;

    for(auto num : frequencia){
        total *= (num.second + 1);
        total %= MOD;
    }

    total %= MOD;
    
    cout << total-1 << "\n";

    return 0;
}