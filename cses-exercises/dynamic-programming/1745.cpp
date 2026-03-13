/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> moedas(n);
    int somaMax = 0;

    for(int i = 0; i < n; ++i){
        cin >> moedas[i];
        somaMax += moedas[i];
    }

    vector<bool> dp(somaMax + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; ++i){
        for(int j = somaMax-moedas[i]; j >= 0; --j){
            if(dp[j]){
                dp[j+moedas[i]] = 1;
            }
        }
    }

    int k = 0;
    vector<int> respostas;

    for(int i = 1; i <= somaMax; ++i){
        if(dp[i]){
            respostas.push_back(i);
            ++k;
        }
    }

    cout << k << "\n";

    for(const int& resposta : respostas){
        cout << resposta << " ";
    }

    cout << "\n";

    return 0;
}