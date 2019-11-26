#include "../../problems/0150_search_suggestions_system.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"
#include "../../frameworks/asserts.hpp"

using namespace std;

TEST_CASE( "Search Suggestions System" ) {
    Solution sol;
    vector<string> products1 = {"mobile","mouse","moneypot","monitor","mousepad"};
    vector<vector<string>> result1 = {{"mobile","moneypot","monitor"},{"mobile","moneypot","monitor"},{"mouse","mousepad"},{"mouse","mousepad"},{"mouse","mousepad"}};
    REQUIRE( areVectorsEqual(sol.suggestedProducts(products1,"mouse"),result1) );


    vector<string> products2 = {"havana"};
    vector<vector<string>> result2 = {{"havana"},{"havana"},{"havana"},{"havana"},{"havana"},{"havana"}};
    REQUIRE( areVectorsEqual(sol.suggestedProducts(products2,"havana"),result2) );
    
}