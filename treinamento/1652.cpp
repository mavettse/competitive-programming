/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<vector<int>> trees(n+1, vector<int>(n+1, 0));

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            char c; cin >> c;
            int cur = (c == '*') ? 1 : 0;

            trees[i][j] = cur + trees[i-1][j] + trees[i][j-1] - trees[i-1][j-1];
        }

    while(q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int add = trees[y2][x2] + trees[y1-1][x1-1], rmv = trees[y1-1][x2] + trees[y2][x1-1];
        cout << add - rmv << '\n';
    }

    return 0;
}