//
//  main.cpp
//  best_time_to_buy_and_sell_stock.leetcode
//
//  Created by Liangchuan Gu on 15/12/2017.
//  Copyright © 2017 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); ++i)
        {
            if(minPrice > prices[i]) minPrice = prices[i];
            if(maxProfit < (prices[i] - minPrice)) maxProfit = prices[i] - minPrice;
        }
        
        return maxProfit;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << s.maxProfit(prices) << std::endl;
    return 0;
}
