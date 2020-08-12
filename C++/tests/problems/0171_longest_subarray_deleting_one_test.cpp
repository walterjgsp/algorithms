#include "../../problems/0171_longest_subarray_deleting_one.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Longest Subarray of 1's After Deleting One Element" ) {
    Solution sol;
    
    vector<int> arr1 = {1,1,0,1};
    REQUIRE(sol.longestSubarray(arr1) == 3);   

    vector<int> arr2 = {0,1,1,1,0,1,1,0,1};
    REQUIRE(sol.longestSubarray(arr2) == 5);   
    
    vector<int> arr3 = {1,1,1};
    REQUIRE(sol.longestSubarray(arr3) == 2);  

    vector<int> arr4 = {1,1,0,0,1,1,1,0,1};
    REQUIRE(sol.longestSubarray(arr4) == 4); 

    vector<int> arr5 = {0,0,0};
    REQUIRE(sol.longestSubarray(arr5) == 0); 
}