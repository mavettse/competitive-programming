/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));

        dp[0][1] = nums[0]; // dp[0] -> rob this house; // dp[1] -> dont rob this house

        for(int i=1; i<n; ++i){
            dp[0][i+1] = nums[i]+dp[1][i]; // if im robbing this house, i cant have rob the house before 
            dp[1][i+1] = max(dp[0][i], dp[0][i-1]); // im choosing the greatest value of stolen one of the last two houses
        }

        return max(dp[0][n], dp[1][n]);
    }
};
