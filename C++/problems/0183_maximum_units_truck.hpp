#ifndef MAXIMUM_UNITS_TRUCK_HPP_INCLUDED
#define MAXIMUM_UNITS_TRUCK_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool compare(const vector<int> &v1, const vector<int> &v2){
        if(v2[1]==v1[1]){
            return v1[0]>v2[0];
        }
        return v1[1]>v2[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize);
};

#include "0183_maximum_units_truck.cpp"

#endif