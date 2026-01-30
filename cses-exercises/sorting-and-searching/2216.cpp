/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int rounds = 0;
    vector<int> numerosLidos(n+1, 0);

    for(int i = 1; i <= n; ++i){
        int numAtual;
        cin >> numAtual;

        if(!numerosLidos[numAtual - 1]){
            rounds++;
        }

        numerosLidos[numAtual] = 1;
    }

    cout << rounds << "\n";
    
    return 0;
}