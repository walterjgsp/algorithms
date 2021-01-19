#include "../../problems/0183_maximum_units_truck.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Maximum Units on a Truck" ) {
    Solution sol;

    vector<vector<int>> box1 = {{1,3},{2,2},{3,1}};
    REQUIRE(sol.maximumUnits(box1,4) == 8);

    vector<vector<int>> box2 = {{5,10},{2,5},{4,7},{3,9}};
    REQUIRE(sol.maximumUnits(box2,10) == 91);
}