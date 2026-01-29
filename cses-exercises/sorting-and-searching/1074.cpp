/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> comprimentos;
    comprimentos.reserve(n);
    
    for(int i = 0; i < n; ++i){
        int aux;
        cin >> aux;

        comprimentos.push_back(aux);
    }

    sort(comprimentos.begin(), comprimentos.end());

    int mediana = comprimentos[n/2];
    long long custo = 0;

    for(int comprimento : comprimentos){
        custo += abs(comprimento - mediana);
    }

    cout << custo << "\n";
        
    return 0;
}