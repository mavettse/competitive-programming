/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> numeros(n,0);

    long long somaMax = 0, somaMin = 0;

    for(int i = 0; i < n; ++i){
        long long num; cin >> num;
        numeros[i] = num;
        somaMax += num;
        somaMin = max(somaMin, num);
    }

    while(somaMax > somaMin){
        long long soma = (somaMax-somaMin)/2 + somaMin;

        long long qtdSubArrays = 1, somaSubArray = 0;

        for(int i = 0; i < n; ++i){
            if(somaSubArray + numeros[i] > soma){
                somaSubArray = numeros[i];
                qtdSubArrays++;
            } else {
                somaSubArray += numeros[i];
            }
        }

        if(qtdSubArrays <= k){
            somaMax = soma;
        } else {
            somaMin = soma + 1;
        } 
    }

    cout << somaMin << "\n"; 
    
    return 0;
}