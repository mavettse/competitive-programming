/* GIOVANNI ESTEVAM DOS SANTOS */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;

    vector<int> desiredSizes(n), apSizes(m);

    for(int i = 0; i < n; ++i)
        cin >> desiredSizes[i];
    sort(desiredSizes.begin(), desiredSizes.end());
        
    for(int i = 0; i < m; ++i)
        cin >> apSizes[i];
    sort(apSizes.begin(), apSizes.end());
        
    int getAp = 0, i = 0, j = 0;

    while(i < m && j < n){
        int maxTol = desiredSizes[j] + k, minTol = desiredSizes[j] - k;

        if(apSizes[i] < minTol)
            i++;
        else if(apSizes[i] > maxTol)
            j++;
        else {
            getAp++;
            i++; j++;
        }
    }

    cout << getAp << '\n';

    return 0;
}