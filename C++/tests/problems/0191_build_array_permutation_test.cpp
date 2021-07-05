#include "../../problems/0191_build_array_permutation.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"
#include "../../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Build Array from Permutation" ) {
    Solution sol;

    vector<int> nums1 = {0,2,1,5,3,4};
    vector<int> result1 = {0,1,2,4,5,3};
    REQUIRE(areVectorsEqual(sol.buildArray(nums1),result1));

    vector<int> nums2 = {5,0,1,2,3,4};
    vector<int> result2 = {4,5,0,1,2,3};
    REQUIRE(areVectorsEqual(sol.buildArray(nums2),result2));    
}
