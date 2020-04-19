#include "../../problems/0165_minimum_value_positive_step_by_sum.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Minimum Value to Get Positive Step by Step Sum" ) {
    Solution sol;
    
    vector<int> vec1 = {-3,2,-3,4,2};
    REQUIRE( sol.minStartValue(vec1) == 5 );   
  
    vector<int> vec2 = {1,2};
    REQUIRE( sol.minStartValue(vec2) == 1 );  

    vector<int> vec3 = {1,-2,-3};
    REQUIRE( sol.minStartValue(vec3) == 5 );   
}