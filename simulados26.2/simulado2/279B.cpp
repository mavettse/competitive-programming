/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, t; cin >> n >> t;

    vector<int> books(n);
    int maxBooks = 0;

    for(int r = 0, l = 0, curTime = 0; r < n; ++r){
        cin >> books[r];

        curTime += books[r];
        
        while(curTime > t && l <= r)
            curTime -= books[l++];

        maxBooks = max(maxBooks, r-l+1);
    }
    
    cout << maxBooks << '\n';

    return 0;
}