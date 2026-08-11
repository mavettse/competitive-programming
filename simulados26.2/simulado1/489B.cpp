/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> boys(n);
    for(int i = 0; i < n; ++i)
        cin >> boys[i]; 
    sort(boys.begin(), boys.end());

    int m; cin >> m;
    vector<int> girls(m);
    for(int i = 0; i < m; ++i)
        cin >> girls[i];
    sort(girls.begin(), girls.end());

    int ptrBoys = 0, ptrGirls = 0, pairs = 0;

    while(ptrBoys < n && ptrGirls < m){
        int dif = boys[ptrBoys] - girls[ptrGirls];

        if(dif > 1)
            ptrGirls++;
        else if(dif < -1)
            ptrBoys++;
        else {
            pairs++;
            ptrGirls++;
            ptrBoys++;
        }
    }

    cout << pairs << '\n';

    return 0;
}