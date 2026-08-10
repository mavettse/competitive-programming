/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int length = s.size();
    vector<int> letters(26, 0);

    for(char c : s)
        letters[c - 'A']++;

    int odds = 0; char c = ' ';

    for(int i = 0; i < 26; ++i)
        if(letters[i] % 2 != 0){
            odds++; c = i + 'A';
        }

    if(odds > 1 || (length % 2 == 0 && odds != 0) || (length % 2 != 0 && odds != 1)){
        cout << "NO SOLUTION\n";
        return 0;
    }
    
    string p(length, ' ');

    int lPtr = 0, rPtr = length-1, aPtr = 0;
    while(lPtr < rPtr){
        while(aPtr < 26 && letters[aPtr] <= 1)
            aPtr++;

        if(aPtr == 26)
            break;

        p[lPtr++] = p[rPtr--] = aPtr + 'A';

        letters[aPtr] -= 2;
    }

    if(lPtr == rPtr)
        p[lPtr] = c;

    cout << p << '\n';

    return 0;
}