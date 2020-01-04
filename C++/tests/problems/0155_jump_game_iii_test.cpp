#include "../../problems/0155_jump_game_iii.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Jump Game III" ) {
    Solution sol;
    
    vector<int> nums1 = {4,2,3,0,3,1,2};
    REQUIRE( sol.canReach(nums1,5) == true );    
    
    vector<int> nums2 = {4,2,3,0,3,1,2};
    REQUIRE( sol.canReach(nums2,0) == true );    

    vector<int> nums3 = {3,0,2,1,2};
    REQUIRE( sol.canReach(nums3,2) == false );     
}