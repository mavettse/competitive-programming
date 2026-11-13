/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int robber(vector<int>& nums, int start, int end){
        int cur = 0, pre = 0;

        for(int i = start; i < end; ++i){
            int aux = max(cur, pre+nums[i]);
            pre = cur;
            cur = aux;
        }

        return cur;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        return max(robber(nums, 0, n-1), robber(nums, 1, n));
    }
};
