#include "../../problems/0167_build_array_stack_operations.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"
#include "../../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Build an Array With Stack Operations" ) {
    Solution sol;
    
    vector<string> result1 = {"Push","Push","Pop","Push"};
    vector<int> target1 = {1,3};
    REQUIRE(areVectorsEqual(sol.buildArray(target1,3),result1));   

    vector<string> result2 = {"Push","Push","Push"};
    vector<int> target2 = {1,2,3};
    REQUIRE(areVectorsEqual(sol.buildArray(target2,3),result2));   

    vector<string> result3 = {"Push","Push"};
    vector<int> target3 = {1,2};
    REQUIRE(areVectorsEqual(sol.buildArray(target3,4),result3));   

    vector<string> result4 = {"Push","Pop","Push","Push","Push"};
    vector<int> target4 = {2,3,4};
    REQUIRE(areVectorsEqual(sol.buildArray(target4,4),result4));   

}