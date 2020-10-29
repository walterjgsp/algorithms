// Problem Statement
// You are given an array representing a row of seats where seats[i] = 1 
// represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

// There is at least one empty seat, and at least one person sitting.

// Alex wants to sit in the seat such that the distance between him and the 
// closest person to him is maximized. 

// Return that maximum distance to the closest person.
#include "0181_maximum_distance_closest_person.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::maxDistToClosest(vector<int>& seats){
    int tam = seats.size(),result=0;
    vector<int> left(tam,-1), right(tam,tam);
    
    for(int i=0;i<tam;i++){
        if(seats[i]==1){
            left[i]=i;
        }else if(i>0){
            left[i] = left[i-1];
        }
    }
    
    for(int i=tam-1;i>=0;i--){
        if(seats[i]==1){
            right[i]=i;
        }else if(i<tam-1){
            right[i] = right[i+1];
        }
    }
    
    for(int i=0;i<tam;i++){
        int distLeft = INT_MAX,distRight = INT_MAX;
        
        if(left[i]!=-1){
            distLeft = i-left[i];
        }
        
        if(right[i]!=tam){
            distRight = right[i]-i;
        }
        
        result = max(result,min(distLeft,distRight));
    }
    
    return result;
}