// Problem Statement
//
// There are N gas stations along a circular route, where the amount of gas at
// station i is gas[i].
//
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel
// from station i to its next station (i+1). You begin the journey with an empty
// tank at one of the gas stations.
//
// Return the starting gas station's index if you can travel around the circuit
// once in the clockwise direction, otherwise return -1.
//
// Note:
//
// *If there exists a solution, it is guaranteed to be unique.
// *Both input arrays are non-empty and have the same length.
// *Each element in the input arrays is a non-negative integer.
//
// Input:
// gas  = [1,2,3,4,5]
// cost = [3,4,5,1,2]
// Output: 3

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_cost=0;
        for(int i=0;i<gas.size();i++){
            gas[i]=gas[i]-cost[i];
            total_cost+=gas[i];
        }

        if(total_cost<0)
            return -1;

        int to_return = 0,actual_cost=gas[0];
        for(int i=1;i<gas.size();i++){

            if(actual_cost<0){
                actual_cost = gas[i];
                to_return = i;
            }else{
                actual_cost+=gas[i];
            }
        }

        return to_return;
    }
};

int main(){
  vector<int> cost = {3,4,5,1,2};
  vector<int> gas = {1,2,3,4,5};
  Solution sol;
  cout<<sol.canCompleteCircuit(gas,cost)<<endl;
  return 0;
}
