/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

const int A = 53, B = 1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int n = s.size();

    vector<long long> h(n), potencia(n);
    h[0] = s[0], potencia[0] = 1;

    for(int i = 1; i < n; ++i){
        h[i] = ((h[i-1] * A) + s[i]) % B;
        potencia[i] = (potencia[i-1] * A) % B;
    }

    int inicio = 0, fim = n-1;
    vector<int> tamanhos;

    while(inicio < n-1){        
        long long hFim = (h[n-1] - (h[fim-1] * potencia[n-fim])) % B;

        if(hFim < 0){
            hFim += B;
        }

        if(h[inicio] == hFim){
            tamanhos.push_back(inicio+1);
        }

        inicio++; fim--;
    }

    sort(tamanhos.begin(), tamanhos.end());

    for(auto const& tamanho : tamanhos){
        cout << tamanho << ' ';
    }

    cout << '\n';
    
    return 0;
}