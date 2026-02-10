/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, alvo; cin >> n >> alvo;
    vector<int> nums;
    nums.reserve(n);

    int inicio = 0, qtdSubarrays = 0;
    long long soma = 0;

    for(int fim = 0; fim < n; ++fim){
        int num; cin >> num;
        nums.push_back(num);        

        soma += nums[fim];

        while(soma > alvo && inicio <= fim){
            soma -= nums[inicio++];
        }

        if(soma == alvo){
            qtdSubarrays++;
        }
    }

    cout << qtdSubarrays << "\n";
    
    return 0;
}