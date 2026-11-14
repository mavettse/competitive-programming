/*
Se tiver pelo menos 3 células vazias, então o número mínimo será dois; Caso contrário, será a quantidade de células vazias (.)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n, freeCells = 0, count = 0; cin >> n;
        char c; 

        while(n--){
            cin >> c;

            if(count == 3) continue;

            if(c == '.') {
                count++;
                freeCells++;
            } else count = 0;
        }

        cout << (count == 3 ? 2 : freeCells) << '\n';
    }
    

    return 0;
}