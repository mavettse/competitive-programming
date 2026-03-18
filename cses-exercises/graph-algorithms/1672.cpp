/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
long long dist[502][502];

void menorCaminho(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q; cin >> n >> m >> q;

    memset(dist, 0, sizeof(dist));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j){
                continue;
            }

            dist[i][j] = 1e18;
        }
    }

    for(int i = 0; i < m; ++i){
        int a, b; long long c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); 
        dist[b][a] = min(dist[b][a], c); 
    }

    menorCaminho();

    for(int i = 0; i < q; ++i){
        int a, b; cin >> a >> b;

        if(dist[a][b] == 1e18){
            cout << "-1\n";
            continue;
        }

        cout << dist[a][b] << "\n";
    }
        
    return 0;
}