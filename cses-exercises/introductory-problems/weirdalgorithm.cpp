#include <iostream>

using namespace std;

int main(){
    unsigned long int n;
    cin >> n;

    while(n != 1){
        cout << n << " ";

        if((n & 1) == 0){
            n >>= 1;
        } else {
            n = (n * 3) + 1;
        }
    }

    cout << n << "\n";

    return 0;
}