#include "../../problems/0153_divide_array_set_k_consecutive.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Divide Array in Sets of K Consecutive Numbers" ) {
    Solution sol;
    
    vector<int> nums1 = {1,2,3,3,4,4,5,6};
    REQUIRE( sol.isPossibleDivide(nums1,4) == true );    
    
    vector<int> nums2 = {3,2,1,2,3,4,3,4,5,9,10,11};
    REQUIRE( sol.isPossibleDivide(nums2,3) == true );    

    vector<int> nums3 = {3,3,2,2,1,1};
    REQUIRE( sol.isPossibleDivide(nums3,3) == true );     

    vector<int> nums4 = {1,2,3,4};
    REQUIRE( sol.isPossibleDivide(nums4,3) == false );
}