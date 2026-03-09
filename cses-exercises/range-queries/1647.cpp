/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> logs(n+1, 0);

    for(int i = 2; i <= n; ++i){
        logs[i] = logs[i/2] + 1;
    }

    vector<vector<int>> st(n+1, vector<int>(logs[n])); // [posição][tamanho (k = 2^j, k <= n)]

    for(int i = 1; i <= n; ++i){ // caso base: valor mínimo do intervalo [i,i] é o proprio número; (2^j = 2^0 = 1)
        cin >> st[i][0];
    }

    for(int j = 1; (1<<j) <= n; ++j){
        int k = 1<<j;

        for(int i = 1; i+k-1 <= n; ++i){
            st[i][j] = min(st[i][j-1], st[i + k/2][j-1]);
        }
    }

    for(int i = 0; i < q; ++i){
        int a, b; cin >> a >> b;
        int tamIntervalo = b-a+1;
        int j = logs[tamIntervalo];
        int k = 1<<j;

        cout << min(st[a][j], st[b-k+1][j]) << "\n";
    }

    return 0;
}