#include "../../problems/0190_minimize_maximum_pair_sum.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Minimize Maximum Pair Sum in Array" ) {
    Solution sol;

    vector<int> nums1 = {3,5,2,3};
    REQUIRE(sol.minPairSum(nums1) == 7);

    vector<int> nums2 = {3,5,4,2,4,6};
    REQUIRE(sol.minPairSum(nums2) == 8);
}