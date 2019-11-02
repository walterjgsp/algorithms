// Problem Statement
// You are driving a vehicle that has capacity empty seats initially available for passengers.  
// The vehicle only drives east (ie. it cannot turn around and drive west.)

// Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains 
// information about the i-th trip: the number of passengers that must be picked up, and the 
// locations to pick them up and drop them off.  The locations are given as the number of kilometers 
// due east from your vehicle's initial location.

// Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    enum Action {OUT,IN};
    typedef tuple<int,Action,int> triple_t;

public:
    bool carPooling(vector<vector<int>>& trips, int capacity) { 
        priority_queue<triple_t, vector<triple_t>, greater<triple_t> > pq;
        
        for(auto trip : trips){
            pq.push(make_tuple(trip[1],IN,trip[0]));
            pq.push(make_tuple(trip[2],OUT,trip[0]));
        }
        
        int curr_passengers=0,location,passengers;
        Action action;
        
        while(!pq.empty()){
            tie(location,action,passengers) = pq.top();
            
            pq.pop();
            if(action == IN){
                curr_passengers+=passengers;
            }else{
                curr_passengers-=passengers;
            }
            if(curr_passengers>capacity)
                return false;
        }
        
        return true;
    }
};

int main(){
    vector<vector<int>> trips = {{3,2,7},{3,7,9},{8,3,9}};
    Solution sol;
    cout<<sol.carPooling(trips,11)<<endl;
    return 0;
}