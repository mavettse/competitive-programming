#include <iostream>
#include <string>

using namespace std;

int main(){

    string sequencia;
    cin >> sequencia;

    int maxTotal = 1;
    int maxAtual = 1;

    for(size_t i = 1; i < sequencia.length(); ++i){
        
        if(sequencia[i-1] == sequencia[i]){
            maxAtual++;
        } else {
            maxAtual = 1;
        }

        maxTotal = max(maxTotal, maxAtual);
    }

    cout << maxTotal << "\n";

    return 0;
}