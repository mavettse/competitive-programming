/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <string>

using namespace std;

long long fatorial(int n){
    
    long long fat = 1;

    for(int i = n; i > 1; --i){
        fat *= i;
    }

    return fat;
}

void imprimirStrings(int n, string& atual, int alfabeto[]){
    
    if((int)atual.size() == n){
        cout << atual << "\n";
        return;
    }

    for(int i = 0; i < 26; ++i){
        if(alfabeto[i] > 0){
            atual.push_back(i + 'a');
            alfabeto[i]--;
            imprimirStrings(n, atual, alfabeto);
            atual.pop_back();
            alfabeto[i]++;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int alfabeto[26] = {0};

    for(char c : s){ 
        alfabeto[c - 'a']++;
    }

    int denominador = 1;

    for(int qtdLetras : alfabeto){
        if(qtdLetras > 1){
            denominador *= fatorial(qtdLetras);
        }
    }

    int n = s.size();
    long long linhas = fatorial(n)/denominador;
    
    cout << linhas << "\n";

    string palavra;
    imprimirStrings(n, palavra, alfabeto);

    return 0;
}