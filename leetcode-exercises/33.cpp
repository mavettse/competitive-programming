/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while(l <= r){
            int mid = (l+r)/2;

            if(nums[mid] == target) return mid;

            if(nums[mid] > nums[r]) // meio está ordenado com a esquerda
                if(target >= nums[l] && target < nums[mid]) r = mid-1;
                else l = mid+1;
            else // meio está ordenado com a direita
                if(target > nums[mid] && target <= nums[r]) l = mid+1;
                else r = mid-1;
        }

        return -1;
    }
};
