/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long fatorial(int n){
    
    long long fat = 1;
 
    for(int i = n; i > 1; --i){
        fat *= i;
    }
 
    return fat;
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

    for(int i = 0, j = 0; i < 26 && j < n; ++i){
        while(alfabeto[i] > 0){
            s[j] = i + 'a';
            alfabeto[i]--;
            j++;
        }
    }

    do{
        cout << s << "\n";
    } while(next_permutation(s.begin(), s.end()));

    return 0;
}