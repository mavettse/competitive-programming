/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    int maiorLivro = 0;
    long long somaLivros = 0;

    for(int i = 0; i < n; ++i){
        int livro; cin >> livro;

        somaLivros += livro;

        if(livro > maiorLivro){
            somaLivros = somaLivros - livro + maiorLivro;
            maiorLivro = livro;
        }
    }

    if(maiorLivro > somaLivros){
        cout << 2*maiorLivro << "\n";
    } else {
        cout << somaLivros + maiorLivro << "\n";
    }
    
    return 0;
}