/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){

        long long tabuleiro = i * i;
        long long posAtaque = ((i-2) * (i-1)) * 2 * 2;

        long long qtdModos = ((tabuleiro * (tabuleiro-1))/2) - posAtaque;

        cout << qtdModos << "\n";
    }

    return 0;
}