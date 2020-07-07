#include "../../problems/0169_check_array_pairs_divisible_k.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Check If Array Pairs Are Divisible by k" ) {
    Solution sol;
    
    vector<int> arr1 = {1,2,3,4,5,10,6,7,8,9};
    REQUIRE(sol.canArrange(arr1,5) == true);   

    vector<int> arr2 = {1,2,3,4,5,6};
    REQUIRE(sol.canArrange(arr2,7) == true);   
    
    vector<int> arr3 = {1,2,3,4,5,6};
    REQUIRE(sol.canArrange(arr3,10) == false);   
    
    vector<int> arr4 = {-10,10};
    REQUIRE(sol.canArrange(arr4,2) == true);   

    vector<int> arr5 = {-1,1,-2,2,-3,3,-4,4};
    REQUIRE(sol.canArrange(arr5,3) == true);
}