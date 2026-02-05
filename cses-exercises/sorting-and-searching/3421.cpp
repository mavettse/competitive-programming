/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <map>

using namespace std;

long long MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int,long long> frequencias;
    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        frequencias[num]++;
    }

    long long total = 1;
    for(auto [num,freq] : frequencias){
        total *= (freq + 1);
        total %= MOD;
    }

    total %= MOD;
    
    cout << total-1 << "\n";

    return 0;
}