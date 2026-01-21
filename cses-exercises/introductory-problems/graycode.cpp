/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; 
    cin >> n;

    int doisN = 1 << n;

    for(int i = 0; i < doisN; ++i){

        int grayCode = i ^ (i >> 1);

        for(int j = n-1; j >= 0; --j){
            if(grayCode >> (j) & 1){
                cout << "1";
            } else {
                cout << "0";
            }

        }

        cout << "\n";
    }

    return 0;
}