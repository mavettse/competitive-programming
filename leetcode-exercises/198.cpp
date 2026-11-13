/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), curMaxStolen = nums[0], lastStolen = nums[0], lastStolen2 = 0;

        for(int i=1; i<n; ++i) {
            curMaxStolen = max(lastStolen2 + nums[i], lastStolen);
            lastStolen2 = lastStolen;
            lastStolen = curMaxStolen;
        }

        return curMaxStolen;
    }
};
