#include "../../problems/0144_buy_sell_stock_i.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Best Time to Buy and Sell Stock" ) {
    Solution sol;
    REQUIRE( sol.maxProfit({7,1,5,3,6,4}) == 5 );
    REQUIRE( sol.maxProfit({7,6,4,3,1}) == 0 );
    REQUIRE( sol.maxProfit({}) == 0 );
}