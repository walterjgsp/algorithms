#include "../../problems/0022_partition_labels.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"
#include "../../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Partition Labels" ) {
    Solution sol;

    vector<int> result1 = {9,7,8};
    REQUIRE( areVectorsEqual(sol.partitionLabels("ababcbacadefegdehijhklij"),result1) );

    vector<int> result2 = {3};
    REQUIRE( areVectorsEqual(sol.partitionLabels("aba"),result2) );

    vector<int> result3 = {1,1};
    REQUIRE( areVectorsEqual(sol.partitionLabels("ab"),result3) );

    vector<int> result4 = {4,2,1,1,1};
    REQUIRE( areVectorsEqual(sol.partitionLabels("abaaccdef"),result4) );
}