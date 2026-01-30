/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long somaPA = (1LL+n) * n / 2;

    if(somaPA & 1){
        cout << "NO\n";
        return 0;
    }

    long long valorSet = somaPA/2;
    long long aux = 0;

    vector<int> set1, set2;

    for(int i = n; i >= 1; --i){
        if(aux + i <= valorSet){
            set1.push_back(i);
            aux += i;
        } else {
            set2.push_back(i);
        }
    }

    cout << "YES\n" << set1.size() << "\n";

    for(int i : set1){
        cout << i << " ";
    }

    cout << "\n" << set2.size() << "\n";

    for(int i : set2){
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}