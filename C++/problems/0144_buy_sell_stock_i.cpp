// Problem Statement
// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction 
// (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Note that you cannot sell a stock before you buy one.

#include "0144_buy_sell_stock_i.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::maxProfit(vector<int> prices) {
    if(prices.empty()) return 0;
    int min_stock = prices[0], result = 0;
    for(int i=1;i<prices.size();i++){
        result = max(result,prices[i]-min_stock);
        min_stock = min(min_stock,prices[i]);
    }
    
    return result;
}