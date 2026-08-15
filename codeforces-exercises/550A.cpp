/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    bool case1 = 0, case2 = 0;
    size_t posAB = s.find("AB");

    if(posAB != string::npos)
        if(s.find("BA", posAB+2) != string::npos)
            case1 = 1;

    size_t posBA = s.find("BA");

    if(posBA != string::npos)
        if(s.find("AB", posBA+2) != string::npos)
            case2 = 1;

    cout << (case1 || case2 ? "YES\n" : "NO\n");
    
    return 0;
}