/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

const int MODULO = 1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; ++i){
        long long a; int b; cin >> a >> b;
        long long resp = 1;

        while(b > 0){
            if(b % 2 == 1){
                resp = ((resp%MODULO) * (a%MODULO))%MODULO;
            }

            a = ((a%MODULO) * (a%MODULO))%MODULO;
            b /= 2;
        }

        cout << resp << "\n";
    }
    
    return 0;
}