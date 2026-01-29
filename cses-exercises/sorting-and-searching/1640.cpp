/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <map>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, alvo;
    cin >> n >> alvo;

    map<int,int> numeros;
    
    for(int i = 0; i < n; ++i){
        int aux;
        cin >> aux;

        auto posicao = numeros.find(alvo - aux);

        if(posicao != numeros.end()){
            cout << i + 1 << " " << posicao->second + 1 << "\n";
            return 0;
        }

        numeros.insert({aux, i});
    }

    cout << "IMPOSSIBLE\n";
    
    return 0;
}