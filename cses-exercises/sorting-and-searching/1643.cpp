/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <limits>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long maxSoma = numeric_limits<int>::min();
    long long somaAtual = maxSoma;

    for(int i = 0; i < n; ++i){
        long long numAtual;
        cin >> numAtual;

        somaAtual = max(numAtual, somaAtual + numAtual);
        maxSoma = max(maxSoma, somaAtual);
    }
    
    cout << maxSoma << "\n";
    
    return 0;
}