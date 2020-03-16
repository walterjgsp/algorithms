#include "../../problems/0162_time_needed_inform_employees.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Time Needed to Inform All Employees" ) {
    Solution sol;
    
    vector<int> manager1 = {-1}, informTime1 = {0};
    REQUIRE( sol.numOfMinutes(1,0,manager1,informTime1) == 0 );   

    vector<int> manager2 = {2,2,-1,2,2,2}, informTime2 = {0,0,1,0,0,0};
    REQUIRE( sol.numOfMinutes(6,2,manager2,informTime2) == 1 );  

    vector<int> manager3 = {1,2,3,4,5,6,-1}, informTime3 = {0,6,5,4,3,2,1};
    REQUIRE( sol.numOfMinutes(7,6,manager3,informTime3) == 21 );

    vector<int> manager4 = {-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6}, informTime4 = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
    REQUIRE( sol.numOfMinutes(15,0,manager4,informTime4) == 3 );
}