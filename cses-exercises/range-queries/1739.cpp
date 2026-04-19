/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1001;

int n;
bool florest [N_MAX][N_MAX]; // tem árvore = 1; não tem arvore = 0
long long BIT [N_MAX][N_MAX];

void update(int x, int y, long long val){
    for(int i = x; i <= n; i += i&-i)
        for(int j = y; j <= n; j += j&-j)
            BIT[i][j] += val;
}

long long query(int x, int y){
    long long sum = 0;
    
    for(int i = x; i > 0; i -= i&-i)
        for(int j = y; j > 0; j -= j&-j)
            sum += BIT[i][j];

    return sum;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q; cin >> n >> q;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            char c; cin >> c;

            if(c == '*'){
                florest[i][j] = 1;
                update(i,j,1);
            }
        }
    
    for(int i = 0, op, y1, x1, y2, x2, delta; i < q; ++i){
        cin >> op >> x1 >> y1;

        switch(op){
            case 1:
                delta = florest[x1][y1] ? -1 : 1;
                florest[x1][y1] = !florest[x1][y1];
                update(x1,y1,delta);
                break;

            case 2:
                cin >> x2 >> y2;
                cout << query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1) << '\n';
                break;
        }
    }

    return 0;
}