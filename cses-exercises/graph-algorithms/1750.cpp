/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std; 

const int MAXN = 2e5+1;
const int MAXLOG = 30;
int salto[MAXN][MAXLOG];
int adj[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; ++i){
        cin >> adj[i];
        salto[i][0] = adj[i];
    }

    for(int i = 1; i < 30; ++i){
        for(int x = 1; x <= n; ++x){
            salto[x][i] = salto[ salto[x][i-1] ][i-1];
        }
    }

    for(int i = 0; i < q; ++i){
        int x, k; cin >> x >> k;

        for(int j = 0; j < 30; ++j){
            if(k & (1<<j)){
                x = salto[x][j];
            }
        }

        cout << x << '\n';
    }
    
    return 0;
}