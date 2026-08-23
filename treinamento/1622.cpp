/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> strings;

void makeStrings(string& curString, vector<int>& alphabet){
    if(curString.size() == n)
        strings.push_back(curString);

    for(int i = 0; i < alphabet.size(); ++i){
        if(alphabet[i] <= 0)
            continue;
        
        curString.push_back(i + 'a');
        alphabet[i]--;
        makeStrings(curString, alphabet);
        curString.pop_back();
        alphabet[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    n = s.size();

    vector<int> alphabet(26, 0);

    for(char c : s)
        alphabet[c - 'a']++;

    string aux;
    makeStrings(aux, alphabet);
    
    cout << strings.size() << endl;
    for(auto str : strings)
        cout << str << '\n';

    return 0;
}