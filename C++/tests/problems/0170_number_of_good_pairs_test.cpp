#include "../../problems/0170_number_of_good_pairs.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Number of Good Pairs" ) {
    Solution sol;
    
    vector<int> arr1 = {1,2,3,1,1,3};
    REQUIRE(sol.numIdenticalPairs(arr1) == 4);   

    vector<int> arr2 = {1,1,1,1};
    REQUIRE(sol.numIdenticalPairs(arr2) == 6);   
    
    vector<int> arr3 = {1,2,3};
    REQUIRE(sol.numIdenticalPairs(arr3) == 0);   
}