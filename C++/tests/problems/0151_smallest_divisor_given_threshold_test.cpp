#include "../../problems/0151_smallest_divisor_given_threshold.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Find the Smallest Divisor Given a Threshold" ) {
    Solution sol;
    
    vector<int> nums1 = {1,2,5,9};
    REQUIRE( sol.smallestDivisor(nums1,6) == 5 );    
    
    vector<int> nums2 = {2,3,5,7,11};
    REQUIRE( sol.smallestDivisor(nums2,11) == 3 );    

    vector<int> nums3 = {19};
    REQUIRE( sol.smallestDivisor(nums3,5) == 4 );     
}