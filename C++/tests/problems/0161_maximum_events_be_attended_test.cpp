#include "../../problems/0161_maximum_events_be_attended.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Maximum Number of Events That Can Be Attended" ) {
    Solution sol;
    
    vector<vector<int>> arr1 = {{1,2},{2,3},{3,4}};
    REQUIRE( sol.maxEvents(arr1) == 3 );   

    vector<vector<int>> arr2 = {{1,2},{2,3},{3,4},{1,2}};
    REQUIRE( sol.maxEvents(arr2) == 4 );    

    vector<vector<int>> arr3 = {{1,4},{4,4},{2,2},{3,4},{1,1}};
    REQUIRE( sol.maxEvents(arr3) == 4 );  

    vector<vector<int>> arr4 = {{1,100000}};
    REQUIRE( sol.maxEvents(arr4) == 1 );   

    vector<vector<int>> arr5 = {{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};
    REQUIRE( sol.maxEvents(arr5) == 7 );       
}