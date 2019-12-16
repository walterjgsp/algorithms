#ifndef SMALLEST_DIVISOR_GIVEN_THRESHOLD_HPP_INCLUDED
#define SMALLEST_DIVISOR_GIVEN_THRESHOLD_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;
class Solution {
private:
    int getDiv(const int &quotient,const int &divisor);
    int getSum(const vector<int> &nums, const int &divisor);

public:
    int smallestDivisor(vector<int>& nums, int threshold);
};

#include "0151_smallest_divisor_given_threshold.cpp"

#endif