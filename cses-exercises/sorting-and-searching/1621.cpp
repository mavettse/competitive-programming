/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> numeros;
    numeros.reserve(n);

    for(int i = 0; i < n; ++i){
        int aux;
        cin >> aux;

        numeros.push_back(aux);
    }

    sort(numeros.begin(), numeros.end());

    int distintos = 1;

    for(int i = 0; i < n-1; ++i){
        if(numeros[i] != numeros[i+1]){
            distintos++;
        }
    }

    cout << distintos << "\n";

    return 0;
}