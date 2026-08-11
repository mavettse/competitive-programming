/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int x, n; cin >> x >> n;

    set<int> trafficPos;
    multiset<int> lengths; 
    trafficPos.insert(0); trafficPos.insert(x);
    lengths.insert(x);

    while(n--){
        int p; cin >> p;
        
        auto it = trafficPos.upper_bound(p);
        if(it == trafficPos.end()) it--;
        auto next = it, prev = --it;

        auto del = lengths.find(*next - *prev);
        lengths.erase(del);

        lengths.insert(*next - p);
        lengths.insert(p - *prev);
        trafficPos.insert(p);

        cout << *lengths.rbegin() << ' ';
    }

    cout << '\n';

    return 0;
}