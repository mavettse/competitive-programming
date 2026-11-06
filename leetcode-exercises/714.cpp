/* GIOVANNI ESTEVAM DOS SANTOS */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell = 0, buy = -1e6;

        for(const auto& price : prices){
            sell = max(sell, price+buy);
            buy = max(buy, sell-price-fee);
        }

        return sell;
    }
};
