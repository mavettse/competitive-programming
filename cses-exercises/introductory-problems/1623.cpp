/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

int n;
long long macas[20];

long long divisaoMacas(int i, long long grupo1, long long grupo2){
    if(i == n){
        return abs(grupo1 - grupo2);
    }

    return min(divisaoMacas(i + 1, grupo1 + macas[i], grupo2), divisaoMacas(i + 1, grupo1, grupo2 + macas[i]));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> macas[i];
    }

    cout << divisaoMacas(0, 0, 0) << "\n";

    return 0;
}