/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int dl[] = {1, -1,  0, 0};
const int dc[] = {0,  0, -1, 1};

int n, m;
vector<string> mapa; 

void dfs(int l, int c){
    mapa[l][c] = '#';

    for(int i = 0; i < 4; ++i){
        int nl = l + dl[i], nc = c + dc[i];

        if(mapa[nl][nc] == '.')
            dfs(nl, nc);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    mapa.resize(n+2);
    mapa[0] = mapa[n+1] = string(m+2, '#');

    for(int i = 1; i <= n; ++i){
        string s; cin >> s;
        mapa[i] = '#' + s + '#';
    }

    int rooms = 0;
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(mapa[i][j] == '.'){
                dfs(i, j);
                rooms++;
            }
        
    cout << rooms << '\n';

    return 0;
}