/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1, maxArea = 0;

        while(l < r){
            int area = (r-l) * min(heights[l], heights[r]);
            maxArea = max(area, maxArea);

            if(heights[l] < heights[r]) l++; else r--;
        }

        return maxArea;
    }
};
