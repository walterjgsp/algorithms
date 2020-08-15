#include "../../problems/0172_finding_running_median.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"
#include "../../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Find the Running Median" ) {
    Solution sol;
    
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10};
    vector<double> result1 = {1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0,5.5};
    REQUIRE(areVectorsEqual(sol.runningMedian(arr1),result1));   

    vector<int> arr2 = {12,4,5,3,8,7};
    vector<double> result2 = {12.0,8.0,5.0,4.5,5.0,6.0};
    REQUIRE(areVectorsEqual(sol.runningMedian(arr2),result2));   
}
