#include "../../problems/0176_min_deletion_avoid_repeting.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Minimum Deletion Cost to Avoid Repeating Letters" ) {
    Solution sol;

    vector<int> cost1 = {1,2,3,4,5};
    REQUIRE(sol.minCost("abaac",cost1)==3); 
    
    vector<int> cost2 = {1,2,3};
    REQUIRE(sol.minCost("abc",cost2)==0); 

    vector<int> cost3 = {1,2,3,4,1};
    REQUIRE(sol.minCost("aabaa",cost3)==2); 
}