/*
Não há permutação possível para n <= 3; Fazer os números pares ficarem nas posições ímpares
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        if(n <= 3){
            cout << "-1\n";
            continue;
        }

        if(n % 2 != 0){
            while(n != 3){
                cout << --n << ' ' << n+1 << ' ';
                n--;
            }

            cout << "2 1 3";
        } else while(n) cout << n-- << ' ';

        cout << '\n';
    }

    return 0;
}