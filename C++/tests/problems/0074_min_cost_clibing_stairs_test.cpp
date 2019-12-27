#include "../../problems/0074_min_cost_clibing_stairs.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Min Cost Clibing Stairs" ) {
    Solution sol;

    vector<int> arr1 = {10, 15, 20};
    REQUIRE( sol.minCostClimbingStairs(arr1) == 15 );
    
    vector<int> arr2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    REQUIRE( sol.minCostClimbingStairs(arr2) == 6 );

    vector<int> arr3 = {0,0,0,0,0,0};
    REQUIRE( sol.minCostClimbingStairs(arr3) == 0 );
}