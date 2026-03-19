/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

const int MODULO = 1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; ++i){
        long long a, b; int c; cin >> a >> b >> c;
        long long exp = 1, resp = 1;

        while(c > 0){
            if(c % 2 == 1){
                exp = ((exp%(MODULO-1)) * (b%(MODULO-1)))%(MODULO-1);
            }

            b = ((b%(MODULO-1)) * (b%(MODULO-1)))%(MODULO-1);
            c /= 2;
        }

        while(exp > 0){
            if(exp % 2 == 1){
                resp = ((resp%MODULO) * (a%MODULO))%MODULO;
            }

            a = ((a%MODULO) * (a%MODULO))%MODULO;
            exp /= 2;
        }

        cout << resp << "\n";
    }
    
    return 0;
}