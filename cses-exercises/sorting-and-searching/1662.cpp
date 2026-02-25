/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<long long> prefixSum(n+1,0);

    for(int i = 1; i <= n; ++i){
        int num; cin >> num;
        prefixSum[i] = num + prefixSum[i-1];
    }

    vector<int> modNums(n,0);
    long long qtdSubArrays = 0;

    for(int i = 0; i <= n; ++i){
        int resto = ((prefixSum[i] % n) + n) % n; // para tratar os casos em que a soma do prefixo é negativa
        
        qtdSubArrays += modNums[resto];
        modNums[resto]++;
    }

    cout << qtdSubArrays << "\n";

    return 0;
}