/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> subsequencia;

    for(int i = 0; i < n; ++i){
        int num; cin >> num;

        auto it = lower_bound(subsequencia.begin(), subsequencia.end(), num);

        if(it == subsequencia.end()){
            subsequencia.push_back(num);
        } else {
            *it = num;
        }
    }

    cout << subsequencia.size() << "\n";

    return 0;
}