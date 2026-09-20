/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int deg = 0;

        for(int i = 0; i < s.length(); ++i)
            deg += (i+1) * (26 - (s[i] - 97));

        return deg;        
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    Solution sol;

    string s; 

    while (cin >> s){
        int ans = sol.reverseDegree(s);
        cout << ans << '\n';
    }
        
    return 0;
}