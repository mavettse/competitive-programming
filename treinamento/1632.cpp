/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    vector<pair<int,int>> movies(n);

    for(int i = 0; i < n; ++i){
        cin >> movies[i].second;
        cin >> movies[i].first;
    } sort(movies.begin(), movies.end());

    multiset<int> freeMembers;
    int maxMovies = 0;

    for(auto [b,a] : movies){
        auto member = freeMembers.upper_bound(a);

        if(member != freeMembers.begin()){
            member--;
            freeMembers.erase(member);
        } else if(freeMembers.size() >= k)
            continue;
        
        freeMembers.insert(b);
        maxMovies++;
    }

    cout << maxMovies << endl;

    return 0;
}