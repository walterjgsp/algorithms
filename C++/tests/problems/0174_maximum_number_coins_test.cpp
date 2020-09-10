#include "../../problems/0174_maximum_number_coins.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Maximum Number of Coins You Can Get" ) {
    Solution sol;

    vector<int> arr1 = {2,4,1,2,7,8};
    REQUIRE(sol.maxCoins(arr1)==9);   
    
    vector<int> arr2 = {2,4,5};
    REQUIRE(sol.maxCoins(arr2)==4);

    vector<int> arr3 = {9,8,7,6,5,1,2,3,4};
    REQUIRE(sol.maxCoins(arr3)==18);
}