#ifndef MINIMUM_CHANGES_ALTERNATE_STRING_HPP_INCLUDED
#define MINIMUM_CHANGES_ALTERNATE_STRING_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    string createAlternate(int size, bool startZero);
    int checkDiff(const string &w1, const string &w2);
public:
    int minOperations(string s);
};

#include "0185_minimum_changes_alternate_string.cpp"

#endif