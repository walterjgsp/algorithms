#include "../../problems/0179_jump_game.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Jump Game" ) {
    Solution sol;

    vector<int> arr1 = {2,3,1,1,4};
    REQUIRE(sol.canJump(arr1)==true);

    vector<int> arr2 = {3,2,1,0,4};
    REQUIRE(sol.canJump(arr2)==false);

    vector<int> arr3 = {5,2,1,0,4};
    REQUIRE(sol.canJump(arr3)==true);

    vector<int> arr4 = {0};
    REQUIRE(sol.canJump(arr4)==true);

    vector<int> arr5 = {0,1};
    REQUIRE(sol.canJump(arr5)==false);

}