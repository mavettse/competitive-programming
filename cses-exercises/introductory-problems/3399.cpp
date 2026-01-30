/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int n, a, b;

    for(int i = 0; i < t; ++i){

        cin >> n >> a >> b;
        
        if(a+b > n || (a == 0 && b != 0) || (b == 0 && a != 0)){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for(int i = 1; i <= n; ++i){
            cout << i << " ";
        }

        cout << "\n";

        int empates = n - (a+b);

        for(int i = 1; i <= empates; ++i){
            cout << i << " ";    
        }

        for(int i = n-b+1; i <= n; ++i){
            cout << i << " ";
        }

        int cartaMax = n-b;
        int cartaMin = empates+1;

        for(int i = cartaMin; i <= cartaMax; ++i){
            cout << i << " ";
        }
    
        cout << "\n";
    }

    return 0;
}