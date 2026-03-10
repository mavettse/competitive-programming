/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ft;

void trocarElemento(int k, int u){
    k--;
    k += n;
    ft[k] = u;

    for(k /= 2; k >= 1; k /= 2){
        ft[k] = min(ft[2*k], ft[2*k + 1]);
    }
}

int menor(int a, int b){
    a--; b--;
    a += n; b += n;
    int resultado = 1e9;

    while(a <= b){
        if(a%2 == 1){ 
            resultado = min(resultado, ft[a++]);
        }
        if(b%2 == 0){
            resultado = min(resultado, ft[b--]);
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
        ft[i] = min(ft[2*i], ft[2*i + 1]);
    }

    for(int i = 0; i < q; ++i){
        int opcao; cin >> opcao;

        switch(opcao){
            case 1:
                int k, u; cin >> k >> u;
                trocarElemento(k, u);
                break;
            case 2:
                int a, b; cin >> a >> b;
                cout << menor(a, b) << "\n";
                break;
        }
    }

    return 0;
}