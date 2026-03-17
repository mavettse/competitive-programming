/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <cstring>

using namespace std;

char floresta[1005][1005];
int soma[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(floresta, '.', sizeof(floresta));
    memset(soma, 0, sizeof(soma));

    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> floresta[i][j];

            int temArvore = (floresta[i][j] == '*') ? 1 : 0;
            soma[i][j] = temArvore + (soma[i-1][j] + soma[i][j-1]) - soma[i-1][j-1];
        }
    }

    for(int i = 0; i < q; ++i){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << soma[y2][x2] + soma[y1-1][x1-1] - (soma[y1-1][x2] + soma[y2][x1-1]) << "\n";
    }

    return 0;
}