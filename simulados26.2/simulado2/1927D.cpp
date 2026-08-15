/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        int prevNum; cin >> prevNum;

        vector<int> diffLeft(n+1, -1);

        for(int i = 2; i <= n; ++i){
            int curNum; cin >> curNum;
            diffLeft[i] = prevNum != curNum ? i-1 : diffLeft[i-1];
            prevNum = curNum;
        }

        int q; cin >> q;

        while(q--){
            int l, r; cin >> l >> r;
            
            if(diffLeft[r] >= l)
                cout << diffLeft[r] << ' ' << r << '\n';
            else 
                cout << "-1 -1\n";
        }

        cout << '\n';
    }

    return 0;
}