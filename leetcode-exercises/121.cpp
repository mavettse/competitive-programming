/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
	     ios::sync_with_stdio(0); cin.tie(0);

        int profit = 0, bought = INT_MAX;

        for(const auto& price : prices){
            if(price < bought) { bought = price; continue; }
            profit = max(profit, price-bought);
        }

        return profit;
    }
};
