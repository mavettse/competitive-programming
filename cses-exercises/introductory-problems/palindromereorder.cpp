/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    string palavra;
    cin >> palavra;

    int alfabeto[26] = {0};

    for(char letra : palavra){
        alfabeto[letra - 'A']++;
    }

    int impares = 0;

    for(int i = 0; i < 26; ++i){
        if(alfabeto[i] & 1){
            impares++;
        }
    }

    int n = palavra.size();

    if((n & 1 && impares != 1) || (!(n & 1) && impares != 0)){
        cout << "NO SOLUTION\n";
        return 0;
    }

    for(int i = 0; i < 26; ++i){    // metade esquerda
        int aux = 0;

        if(alfabeto[i] != 0 && !(alfabeto[i] & 1)){
            while(aux*2 < alfabeto[i]){
                char letra = i + 'A';
                cout << letra;
                aux++;
            }
        }
    }

    if(impares != 0){               // meio (se houver)
        for(int i = 0; i < 26; ++i){
            int aux = 0;

            if(alfabeto[i] != 0 && alfabeto[i] & 1){
                while(aux < alfabeto[i]){
                char letra = i + 'A';
                    cout << letra;
                    aux++;
                }
            }
        }
    }
    

    for(int i = 25; i >= 0; --i){   // metade direita
        int aux = 0;

        if(alfabeto[i] != 0 && !(alfabeto[i] & 1)){
            while(aux*2 < alfabeto[i]){
                char letra = i + 'A';
                cout << letra;
                aux++;
            }
        }
    }

    cout << "\n";    

    return 0;
}