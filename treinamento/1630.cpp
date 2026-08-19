/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<pair<int,int>> tasks(n);

    for(int i = 0; i < n; ++i){
        int a, d; cin >> a >> d;
        tasks[i] = {a,d};
    } sort(tasks.begin(), tasks.end());

    ll reward = 0, f = 0;

    for(auto [a,d] : tasks){
        f += a;
        reward += d-f;
    }

    cout << reward << endl;

    return 0;
}