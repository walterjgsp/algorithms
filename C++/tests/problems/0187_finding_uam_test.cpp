#include "../../problems/0187_finding_uam.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"
#include "../../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Finding the Users Active Minutes" ) {
    Solution sol;

    vector<vector<int>> log1 = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    vector<int> result1 = {0,2,0,0,0};
    REQUIRE(areVectorsEqual(sol.findingUsersActiveMinutes(log1,5),result1));

    vector<vector<int>> log2 = {{1,1},{2,2},{2,3}};
    vector<int> result2 = {1,1,0,0};
    REQUIRE(areVectorsEqual(sol.findingUsersActiveMinutes(log2,4),result2));
}
