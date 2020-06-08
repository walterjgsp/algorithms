#ifndef BACSPACE_STRING_COMPARE_HPP_INCLUDED
#define BACSPACE_STRING_COMPARE_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    string buildString(const string &word);

public:
    bool backspaceCompare(const string &S, const string &T);
};

#include "0168_backspace_string_compare.cpp"

#endif