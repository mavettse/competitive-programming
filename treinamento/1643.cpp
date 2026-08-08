/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; cin >> n;
    ll maxCurSum = 0, atual, maxSum = -1e10;

    while(n--){
        cin >> atual;
        maxCurSum = max(atual, atual + maxCurSum);
        maxSum = max(maxSum, maxCurSum);
    }

    cout << maxSum << '\n';

    return 0;
}