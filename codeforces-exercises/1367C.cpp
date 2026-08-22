/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;

        vector<int> pos;

        for(int i = 0; i < n; ++i)
            if(s[i] == '1')
                pos.push_back(i);

        int lastSeen = -INF, numTables = 0;

        for(int i = 0, j = 0; i < n; ++i){
            int next = j >= pos.size() ? INF : pos[j];

            if(s[i] == '1')
                lastSeen = i;
            else if(k < i-lastSeen && k < next-i){
                lastSeen = i; 
                numTables++;
            }

            if(i == next)
                j++;
        }

        cout << numTables << endl;
    }

    return 0;
}