//Problem Statement
// N cars are going to the same destination along a one lane road.
// The destination is target miles away.
//
// Each car i has a constant speed speed[i] (in miles per hour), and initial
// position position[i] miles towards the target along the road.
//
// A car can never pass another car ahead of it, but it can catch up to it, and
// drive bumper to bumper at the same speed.
//
// The distance between these two cars is ignored - they are assumed to have the
// same position.
//
// A car fleet is some non-empty set of cars driving at the same position and same speed.
// Note that a single car is also a car fleet.
//
// If a car catches up to a car fleet right at the destination point, it will still
// be considered as one car fleet.
//
// How many car fleets will arrive at the destination?
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> fleet;
        int fleet_count = 0;

        if(position.empty())
            return fleet_count;

        fleet_count++;

        for(int index = 0;index<position.size();index++){
            fleet.push_back(make_pair(position[index],(double)(target-position[index])/speed[index]));
        }

        sort(fleet.begin(),fleet.end(),greater<pair<int,double>> ());

        for(int i=1;i<fleet.size();i++){

            if(fleet[i-1].second<fleet[i].second){
                fleet_count++;
            }else{
                fleet[i].second = fleet[i-1].second;
            }
        }

        return fleet_count;
    }
};

int main(){
  vector<int> position = {10,8,0,5,3};
  vector<int> speed = {2,4,1,1,3};
  int target = 12;
  Solution sol;

  cout<<sol.carFleet(target,position,speed)<<endl;
  return 0;
}
