/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string limite;
long long dp[20][10][2][2];

long long solucao(int pos, int ultimoDigito, bool comecou, bool teto){
    if(pos == (int)limite.size()){
        return 1;
    }

    if(dp[pos][ultimoDigito][comecou][teto] != -1){
        return dp[pos][ultimoDigito][comecou][teto];
    }

    long long total = 0;
    int limiteDigito = teto ? limite[pos] - '0' : 9;

    for(int digito = 0; digito <= limiteDigito; ++digito){
        if(comecou && digito == ultimoDigito){
            continue;
        }

        bool novoComecou = comecou || (digito > 0);
        bool novoTeto = teto && (digito == limiteDigito);
        
        total += solucao(pos + 1, digito, novoComecou, novoTeto);
    }

    return dp[pos][ultimoDigito][comecou][teto] = total;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    long long a, b; cin >> a >> b;

    limite = to_string(b);
    memset(dp, -1, sizeof(dp));

    long long resB = solucao(0, 0, 0, 1), resA = 0;

    if(a > 0){
        limite = to_string(a-1);
        memset(dp, -1, sizeof(dp));
        resA = solucao(0, 0, 0, 1);
    }

    cout << resB - resA << "\n";

    return 0;
}