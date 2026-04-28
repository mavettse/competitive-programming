/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    for(int i = 0; i < t; ++i){
        long long a, b = 0, s; cin >> a >> s;
        bool impossivel = 0;

        for(long long a_atual, b_atual, s_atual, fator = 1; s > 0; fator *= 10){
            a_atual = a % 10; a /= 10;
            s_atual = s % 10; s /= 10;

            if(a_atual > s_atual && s != 0){
                s_atual += (s % 10) * 10;
                s /= 10;
            }

            b_atual = s_atual - a_atual;
        
            if(b_atual > 9 || b_atual < 0 || (s == 0 && a != 0)){
                cout << "-1\n";
                impossivel = 1;
                break;
            }

            b += (b_atual)*fator;
        }

        if(!impossivel) cout << b << '\n';
    }

    return 0;
}