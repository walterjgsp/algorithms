#ifndef SORT_INTEGERS_POWER_VALUE_HPP_INCLUDED
#define SORT_INTEGERS_POWER_VALUE_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:    
    int helperRecursive(int val, unordered_map<int,int> &memo);
public:
    int getKth(int lo, int hi, int k);
};

#include "0164_sort_integers_power_value.cpp"

#endif