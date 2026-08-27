/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

string txt;
vector<int> lps;

void constructLps(){
    lps.assign(txt.size(), 0);
    int i = 1, len = 0;

    while(i < txt.size()){
        if(txt[i] == txt[len]){
            len++;
            lps[i] = len;
            i++;
        } else 
            if(len > 0)
                len = lps[len-1];
            else 
                i++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> txt;

    constructLps();

    vector<int> ans;

    int i = lps[txt.size() - 1];

    while(i > 0){
        ans.emplace_back(i);
        i = lps[i-1];
    }    

    for(auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << ' ';
    cout << '\n';

    return 0;
}