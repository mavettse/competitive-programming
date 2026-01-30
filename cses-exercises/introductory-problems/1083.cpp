#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;

    long long somaEntrada = 0;
    
    long long aux;
    while(cin >> aux){
        somaEntrada += aux;
    }

    long long somaPA = (n * (n + 1LL))/2;

    cout << somaPA - somaEntrada << "\n";

    return 0;
}