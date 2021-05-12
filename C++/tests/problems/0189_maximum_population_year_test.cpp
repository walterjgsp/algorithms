#include "../../problems/0189_maximum_population_year.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Maximum Population Year" ) {
    Solution sol;

    vector<vector<int>> logs1 = {{1993,1999},{2000,2010}};
    REQUIRE(sol.maximumPopulation(logs1) == 1993);

    vector<vector<int>> logs2 = {{1950,1961},{1960,1971},{1970,1981}};
    REQUIRE(sol.maximumPopulation(logs2) == 1960);
}
