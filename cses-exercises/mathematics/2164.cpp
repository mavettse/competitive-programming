/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
using namespace std;

int solucao(int n, int k){
    if(n == 1){
        return 1;
    }

    if(k <= n/2){
        return 2*k;
    } 

    int res = solucao(n-n/2, k-n/2);

    if(n % 2 == 0){
        res = 2*res - 1;
    } else if(res == 1){
        res = n;
    } else {
        res = 2*res-3;
    }
    
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;

    for(int i = 0; i < q; ++i){
        int n, k; cin >> n >> k;
        cout << solucao(n,k) << '\n';       
    }
    
    return 0;
}