/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ft;

int somaXor(int a, int b){
    a--; b--;
    a += n; b += n;
    int resultado = 0;

    while(a <= b){
        if(a%2 == 1){ 
            resultado ^= ft[a++];
        }
        if(b%2 == 0){
            resultado ^= ft[b--];
        }

        a /= 2; b /= 2;
    }

    return resultado;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q; cin >> n >> q; 

    ft.assign(2*n, 0);

    for(int i = 0; i < n; ++i){
        cin >> ft[i+n];
    }

    for(int i = n-1; i > 0; --i){
        ft[i] = ft[2*i] ^ ft[2*i + 1];
    }

    for(int i = 0; i < q; ++i){
        int a, b; cin >> a >> b;
        cout << somaXor(a, b) << "\n";
    }

    return 0;
}