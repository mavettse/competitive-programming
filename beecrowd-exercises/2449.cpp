/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> measures(n);

    for(auto& measure : measures) cin >> measure;

    int mov = 0, prev = 0;

    for(int i = 0; i < measures.size()-1; ++i){
        measures[i] += prev;
        prev = m - measures[i];
        mov += abs(prev);
    }

    cout << mov << '\n';
    
    return 0;
}