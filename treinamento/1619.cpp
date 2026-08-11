/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<pair<int, bool>> times(2*n); // times[n] = {horário, chegada?}

    for(int i = 0; i < 2*n; ++i){
        cin >> times[i].first;
        times[i].second = (i % 2 == 0); // chegada = 1; saída = 0;
    } sort(times.begin(), times.end());

    int maxCustomers = 1, curCustomers = 0;

    for(auto [time, arrive] : times){
        if(arrive)
            curCustomers++;
        else    
            curCustomers--;

        maxCustomers = max(maxCustomers, curCustomers);
    }

    cout << maxCustomers << '\n';

    return 0;
}