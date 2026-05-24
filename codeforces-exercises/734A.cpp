/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    char anton = 'A', danik = 'D'; 
    int qtdVitoriasA = 0, qtdVitoriasD = 0;

    while(n--){
        char vencedor; cin >> vencedor;

        if(vencedor == anton)
            qtdVitoriasA++;
        else if(vencedor == danik)
            qtdVitoriasD++;
    }

    string resp;

    if(qtdVitoriasA > qtdVitoriasD)
        resp = "Anton\n";
    else if(qtdVitoriasD > qtdVitoriasA)
        resp = "Danik\n";
    else 
        resp = "Friendship\n";

    cout << resp;

    return 0;
}