/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k; cin >> n >> m >> k;

    vector<int> tamDesejado(n), tamApts(m);

    for(int i = 0; i < n; ++i)
        cin >> tamDesejado[i];
    sort(tamDesejado.begin(), tamDesejado.end());

    for(int i = 0; i < m; ++i)
        cin >> tamApts[i];
    sort(tamApts.begin(), tamApts.end());

    int ptrDsj = 0, ptrApts = 0, qtdMoradores = 0;

    while(ptrDsj < n && ptrApts < m){
        int a = tamDesejado[ptrDsj] - k, b = tamDesejado[ptrDsj] + k;

        if(a > tamApts[ptrApts])
            ptrApts++;
        else if(b < tamApts[ptrApts])
            ptrDsj++;
        else {
            qtdMoradores++;
            ptrApts++;
            ptrDsj++;
        }
    }

    cout << qtdMoradores << '\n';

    return 0;
}