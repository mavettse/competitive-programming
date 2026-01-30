/* GIOVANNI ESTEVAM DOS SANTOS */
 
#include <iostream>
#include <string>
 
using namespace std;

bool ehValido(int indiceAtual, char letraAtual, string &novaString){
    
    if(indiceAtual == 0){
        return true;
    }

    return novaString[indiceAtual - 1] != letraAtual;
}
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string s;
    cin >> s;
 
    int alfabeto[26] = {};
    
    for(char c : s){
        alfabeto[c - 'A']++;
    }
 
    int n = s.length();
    string sNova(n, ' ');
 
    for(int i = 0; i < n; ++i){

        int letrasRestantes = n-i;
        int maxLetras = letrasRestantes/2 + 1;
        int letraSel = -1;
        
        for(int j = 0; j < 26; ++j){ // encontrando letra urgente

            if(alfabeto[j] == 0 || alfabeto[j] < maxLetras){
                continue;
            }
 
            if(alfabeto[j] > (n+1)/2 || alfabeto[j] > maxLetras){
                cout << "-1\n";
                return 0;
            }
 
            if(ehValido(i, j + 'A', sNova)){
                letraSel = j + 'A';
                break;
            }
        }
 
        if(letraSel == -1){

            for(int j = 0; j < 26; ++j){ // se não tiver letra urgente, seleciona em ordem
                
                if(alfabeto[j] == 0){
                    continue;            
                }
 
                if(ehValido(i, j + 'A', sNova)){
                    letraSel = j + 'A';
                    break;
                }
            }
        }
 
        sNova[i] = letraSel;
        alfabeto[letraSel - 'A']--;
    }
 
    cout << sNova << "\n";
 
    return 0;

}