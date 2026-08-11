/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int s, n; cin >> s >> n;

    vector<pair<int,int>> dragons(n); // dragons[i] = {dragonStrength, defeatBonus}

    for(int i = 0; i < n; ++i)
        cin >> dragons[i].first >> dragons[i].second;
    sort(dragons.begin(), dragons.end());

    for(auto [strength, bonus] : dragons){
        if(s > strength)
            s += bonus;
        else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}