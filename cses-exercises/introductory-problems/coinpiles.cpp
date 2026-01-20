/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    long long a,b;

    for(int i = 0; i < t; ++i){
        cin >> a >> b;
        long long soma = a + b;

        if(!(2*a < b || 2*b < a) && (soma%3 == 0)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}