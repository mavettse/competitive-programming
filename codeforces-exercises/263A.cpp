/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x = -1, y = -1;

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            int num; cin >> num;

            if(num == 1){
                x = i; 
                y = j;
            }
        }
    }

    cout << abs(2-x) + abs(2-y) << '\n';

    return 0;
}