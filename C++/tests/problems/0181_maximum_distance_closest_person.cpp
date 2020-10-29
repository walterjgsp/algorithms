#include "../../problems/0181_maximum_distance_closest_person.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Maximize Distance to Closest Person" ) {
    Solution sol;
   
    vector<int> arr1= {1,0,0,0,1,0,1};
    REQUIRE(sol.maxDistToClosest(arr1) == 2);

    vector<int> arr2= {1,0,0,0};
    REQUIRE(sol.maxDistToClosest(arr2) == 3);

    vector<int> arr3= {0,1};
    REQUIRE(sol.maxDistToClosest(arr3) == 1);
}