/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

string txt, pat;
vector<int> lps;

void constructLps(){
    int i = 1, len = 0;

    while(i < pat.size())
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        } else if(len > 0)
            len = lps[len-1];
        else {
            lps[i] = 0;
            i++;
        }
}

int findPatterns(){
    lps.assign(pat.size(), 0);

    constructLps();

    int i = 0, j = 0, occurrences = 0;

    while(i < txt.size()){
        if(txt[i] == pat[j]){
            i++; j++;

            if(j == pat.size())
                occurrences++;
        } else
            if(j > 0) 
                j = lps[j-1];
            else 
                i++;
    }

    return occurrences;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> txt >> pat; 

    cout << findPatterns() << '\n';

    return 0;
}