/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
using namespace std;

const int MODULO = 1e9 + 7;

int dp[(1<<20)][20]; 

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b; a--; b--;
        adj[b].push_back(a);
    }

    dp[1][0] = 1; 

    for(int mask = 2; mask < (1<<n); ++mask){
        if(!(mask & 1)){
            continue;
        }

        for(int atual = 0; atual < n; ++atual){
            if(!(mask & (1<<atual))){
                continue;
            }

            int maskAnterior = mask ^ (1<<atual);

            for(int anterior : adj[atual]){
                if(maskAnterior & (1<<anterior)){
                    dp[mask][atual] = (dp[mask][atual] + dp[maskAnterior][anterior])%MODULO;
                }
            }
        }
    }

    cout << dp[(1<<n)-1][n-1] << '\n';

    return 0;
}