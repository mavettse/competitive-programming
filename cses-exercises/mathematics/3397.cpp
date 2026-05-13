/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fat[21];
vector<int> p, numDisp;

// pré-calcula os fatoriais até 20
void fatorial(){
    fat[0] = 1;

    for(int i = 1; i <= 20; ++i)
        fat[i] = fat[i-1] * i;
}

// preenche o vetor p  
void tipo1(int n, ll k){
    // para a recursão quando n chega a 0
    if(!n)
        return;

    // fixando o primeiro número, descobrimos o tamanho de cada bloco (quantas vezes o primeiro número se repete até mudar)
    ll tamBloco = fat[n-1];

    // pega o dígito que será inserido no vetor
    int digito = (k + tamBloco - 1)/tamBloco;
    // calcula o novo k: a nova posição a ser buscada dentro de n-1
    k = (k % tamBloco == 0) ? tamBloco : k % tamBloco;

    // insere o dígito no vetor e remove-o do vetor dos números disponíveis
    p.emplace_back(numDisp[digito - 1]);
    numDisp.erase(numDisp.begin() + (digito - 1));

    tipo1(n-1, k);
}

// faz a engenharia reversa: dado um vetor p, descobre o k para chegar até ele (e o retorna)
ll tipo2(int n, ll k){
    // para a recursão quando n chega a 0
    if(!n)
        return k;
        
    ll tamBloco = fat[n-1];

    // pega o dígito mais significativo do vetor p e o remove do vetor
    int digito = p[0];
    p.erase(p.begin());

    // pega a qtd de números estritamente menores que ainda estão disponíveis no vetor de números disponíveis
    int qtdNumMenor = 0;

    for( ; numDisp[qtdNumMenor] < digito; ++qtdNumMenor);

    // retira o número encontrado do vetor de numeros disponiveis
    numDisp.erase(numDisp.begin() + qtdNumMenor);

    // a quantidade de blocos pulados é qtdNumMenor * tamBloco 
    k += qtdNumMenor * tamBloco;

    return tipo2(n-1, k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fatorial();
    
    int t; cin >> t;

    while(t--){
        p.clear();
        
        int op, n; cin >> op >> n;
        p.reserve(n);
        numDisp.reserve(n);

        // insere os números disponíveis no vetor [1, n]
        for(int i = 1; i <= n; ++i)
            numDisp.emplace_back(i);

        switch(op){
            case 1:
                ll k; cin >> k;
                tipo1(n, k);

                for(auto it = p.begin(); it != p.end(); ++it)
                    cout << *it << ' ';
                cout << '\n';

                break;

            case 2:
                for(int i = 0; i < n; ++i)
                    cin >> p.emplace_back();
                    cout << tipo2(n, 0) + 1 << '\n';
                break;

            default: 
                break;
        }
    }

    return 0;
}