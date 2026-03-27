/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int freq[1000001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int numMax = 1;

    for(int i = 0; i < n; ++i){
        int num; cin >> num;
        freq[num]++;
        numMax = max(numMax, num);
    }

    for(int i = numMax; i > 0; --i){
        int aux = i, contador = 0;

        while(aux <= numMax){
            contador += freq[aux];
            aux += i;

            if(contador > 1){
                cout << i << '\n';
                return 0;
            }
        }
    }

    return 0;
}