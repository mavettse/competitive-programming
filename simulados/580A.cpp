/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    int maxSeg = 0, curSeg = 0, prevNum = 0;

    while(n--){
        int curNum; cin >> curNum;

        if(curNum >= prevNum){
            curSeg++;
            maxSeg = max(maxSeg, curSeg);
        } else
            curSeg = 1;    

        prevNum = curNum;
    }

    cout << maxSeg << '\n';

    return 0;
}