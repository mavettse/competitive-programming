/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    long long valor = 1;

    for(int i = 0; i < n; ++i){
        valor <<= 1;
        valor %= 1000000007;
    }

    cout << valor << "\n";

    return 0;
}