#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;

    if((n <= 3) && (n > 1)){
        cout << "NO SOLUTION\n";
        return 0;
    }

    int impar, par;

    if(n & 1){
        impar = n;
        par = n-1;
    } else {
        impar = n-1;
        par = n;
    }

    while(impar >= 1){
        cout << impar << " ";
        impar-=2;
    }

    while(par >= 1){
        cout << par << " ";
        par-=2;
    }

    cout << "\n";

    return 0;
}