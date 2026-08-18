/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;

    vector<int> nums(n); 
    int curSum = 0, subarrays = 0;

    for(int r = 0, l = 0; r < n; ++r){
        cin >> nums[r]; 

        curSum += nums[r];

        if(curSum < x)
            continue;

        while(curSum > x && l < r)
            curSum -= nums[l++];
                        
        if(curSum == x)
            subarrays++;
    }

    cout << subarrays << endl;

    return 0;
}