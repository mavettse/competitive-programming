/*
Salvar as diferenças das fronteiras de quantos sorveteiros estão naquela área
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int p, s, cont = 1;

    while((cin >> p >> s) && (p != 0 || s != 0)){
        vector<int> diff(p+1, 0);

        while(s--){
            int u, v; cin >> u >> v;
            diff[u]++;
            diff[v]--;
        }

        cout << "Teste " << cont++ << '\n';

        for(int i = 0, sum = 0, start = 0; i <= p; ++i){
            sum += diff[i];

            if(!start && sum > 0){
                start = 1;
                cout << i << ' ';
            } else if(sum == 0 && start){
                start = 0;
                cout << i << '\n';
            }
        }

        cout << '\n';
    }

    return 0;
}