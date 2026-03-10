/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> ft;
vector<long long> numeros;

long long soma(int k){
    long long s = 0; 

    while(k >= 1){
        s += ft[k];
        k -= k&-k;
    }

    return s;
}

void trocarElemento(int k, int x){
    long long diferenca = x - numeros[k];
    numeros[k] = x;

    while(k <= n){
        ft[k] += diferenca;
        k += k&-k;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q; cin >> n >> q;

    vector<long long> prefixSum(n+1, 0);
    numeros.assign(n+1, 0);

    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        prefixSum[i] = prefixSum[i-1] + x;
        numeros[i] = x;
    }

    ft.assign(n+1, 0);

    for(int i = 1; i <= n; ++i){
        ft[i] = prefixSum[i] - prefixSum[i - (i&-i)];
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
                cout << soma(b) - soma(a-1) << "\n";
                break;
        }
    }

    return 0;
}