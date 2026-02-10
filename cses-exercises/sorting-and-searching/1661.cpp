/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, alvo; cin >> n >> alvo;

    map<long long,int> prefix_sum; 
    prefix_sum[0] = 1; // {numero, repeticoes}

    long long soma = 0, qtdSubarrays = 0;

    for(int i = 0; i < n; ++i){
        int num; cin >> num;

        soma += num;  
        // nums[i:j] = p[j+1] - p[i] => alvo = p[j+1] - p[i] => p[i] = p[j+1] - alvo
        auto encontrou = prefix_sum.find(soma - alvo);

        if(encontrou != prefix_sum.end()){
            qtdSubarrays += encontrou->second;
        }

        prefix_sum[soma]++;
    }

    cout << qtdSubarrays << "\n";
    
    return 0;
}