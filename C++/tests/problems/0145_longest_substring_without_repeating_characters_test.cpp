#include "../../problems/0145_longest_substring_without_repeating_characters.hpp"
#include <bits/stdc++.h>
#include "../../frameworks/catch.hpp"

using namespace std;

TEST_CASE( "Longest Substring Without Repeating Characters" ) {
    Solution sol;
    REQUIRE( sol.lengthOfLongestSubstring("abcabcbb") == 3 );
    REQUIRE( sol.lengthOfLongestSubstring("bbbbb") == 1 );
    REQUIRE( sol.lengthOfLongestSubstring("pwwkew") == 3 );
    REQUIRE( sol.lengthOfLongestSubstring("") == 0 );
    REQUIRE( sol.lengthOfLongestSubstring("abababdcesraansd") == 7 );
}