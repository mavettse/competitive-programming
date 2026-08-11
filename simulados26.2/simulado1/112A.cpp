/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    for(int i = 0; i < str1.size(); i++){
        str1[i] = tolower(str1[i]);
        str2[i] = tolower(str2[i]);
    }

    int ans = str1.compare(str2);

    if(ans < 0)
        cout << "-1\n";
    else if(ans > 0)
        cout << "1\n";
    else 
        cout << "0\n";

    return 0;
}