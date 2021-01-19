//Problem Statement
// You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, 
// where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

// numberOfBoxesi is the number of boxes of type i.
// numberOfUnitsPerBoxi is the number of units in each box of the type i.
// You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. 
// You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

// Return the maximum total number of units that can be put on the truck.
#include "0183_maximum_units_truck.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
    sort(boxTypes.begin(),boxTypes.end(),compare);
    int result = 0,index=0;
    while(truckSize>0 && index<boxTypes.size()){
        result+=boxTypes[index][1];
        boxTypes[index][0]--;
        truckSize--;
        
        if(boxTypes[index][0]==0){
            index++;
        }
    }
    
    return result;
}