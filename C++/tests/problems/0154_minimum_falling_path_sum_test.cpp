#include "../../problems/0154_minimum_falling_path_sum.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Minimum Falling Path Sum" ) {
    Solution sol;
    
    vector<vector<int>> nums1 = {{1,2,3},{4,5,6},{7,8,9}};
    REQUIRE( sol.minFallingPathSum(nums1) == 12 );    
    
    vector<vector<int>> nums2 = {{2,2,3},{4,3,6},{7,5,9}};
    REQUIRE( sol.minFallingPathSum(nums2) == 10 );    

    vector<vector<int>> nums3 = {{0}};
    REQUIRE( sol.minFallingPathSum(nums3) == 0 );     
}