/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    string timeA = "", timeB = ""; 
    int qtdGolsA = 0, qtdGolsB = 0;

    while(n--){
        string time; cin >> time;

        if(timeA == "")
            timeA = time;
        
        if(timeB == "" && time != timeA)
            timeB = time;

        if(timeA == time)
            qtdGolsA++;
        else if(timeB == time)
            qtdGolsB++;
    }

    cout << ((qtdGolsA > qtdGolsB) ? timeA : timeB) << '\n';

    return 0;
}