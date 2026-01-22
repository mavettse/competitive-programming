/* GIOVANNI ESTEVAM DOS SANTOS */

using namespace std;

#include <iostream>

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int movimentos = (1 << n) - 1;
    cout << movimentos << "\n";

    int posicaoDiscos[17];
    for(int i = 0; i < n; ++i){ // todas os discos iniciam na torre 1
        posicaoDiscos[i] = 1;
    }

    for(int i = 1; i <= movimentos; ++i){

        int qtdZero = 0;
        while(!(i >> qtdZero & 1)){ // para saber qual disco se move
            qtdZero++;
        }

        cout << posicaoDiscos[qtdZero] << " "; // imprime a posição inicial do disco que se move

        int disco = qtdZero + 1;

        if((disco & 1) == (n & 1)){ // se as paridades do número do disco que se move e do número total de discos forem iguais, o disco pula duas casas, se não, o disco pula somente uma
            posicaoDiscos[qtdZero] += 2;
        } else {
            posicaoDiscos[qtdZero] += 1;
        }

       if(posicaoDiscos[qtdZero] > 3){
            posicaoDiscos[qtdZero] %= 3;
       }

        cout << posicaoDiscos[qtdZero] << "\n"; // imprime a posicao final da disco que se move
    
    }

    return 0;
}