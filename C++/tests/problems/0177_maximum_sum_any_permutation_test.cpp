#include "../../problems/0177_maximum_sum_any_permutation.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Maximum Sum Obtained of Any Permutation" ) {
    Solution sol;

    vector<int> nums1 = {1,2,3,4,5}; 
    vector<vector<int>> requests1 = {{1,3},{0,1}};
    REQUIRE(sol.maxSumRangeQuery(nums1,requests1)==19); 

    vector<int> nums2 = {1,2,3,4,5,6}; 
    vector<vector<int>> requests2 = {{0,1}};
    REQUIRE(sol.maxSumRangeQuery(nums2,requests2)==11); 

    vector<int> nums3 = {1,2,3,4,5,10}; 
    vector<vector<int>> requests3 = {{0,2},{1,3},{1,1}};
    REQUIRE(sol.maxSumRangeQuery(nums3,requests3)==47);    
}