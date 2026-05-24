/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;

    int alfabeto[26] = {0};
    int charDistintos = 0;

    for(int i = 0; i < s.size(); ++i){
        if(alfabeto[s[i] - 'a'] == 0)
            charDistintos++;
        
        alfabeto[s[i] - 'a']++;
    }

    if(charDistintos % 2 == 0)
        cout << "CHAT WITH HER!\n";
    else 
        cout << "IGNORE HIM!\n";

    return 0;
}