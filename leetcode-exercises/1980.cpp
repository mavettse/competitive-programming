/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        string newS(n, '0');

        for(int i = 0; i < n; ++i) if(nums[i][i] == '0') newS[i] = '1';

        return newS;
    }
};
