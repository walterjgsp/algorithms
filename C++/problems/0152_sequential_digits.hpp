#ifndef SEQUENTIAL_DIGITS_HPP_INCLUDED
#define SEQUENTIAL_DIGITS_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;
class Solution {
private:
    void helperBack(vector<int> &result, int last_digit,int curr_value, const int &low, const int &high);
public:
    vector<int> sequentialDigits(int low, int high);
};

#include "0152_sequential_digits.cpp"

#endif