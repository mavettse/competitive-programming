/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n; 
    vector<int> subsequence; 

    for(int i = 0; i < n; ++i){
        int num; cin >> num;

        auto it = lower_bound(subsequence.begin(), subsequence.end(), num);

        if(it == subsequence.end())
            subsequence.push_back(num);
        else 
            *it = num;
    }

    cout << subsequence.size() << endl;

    return 0;
}