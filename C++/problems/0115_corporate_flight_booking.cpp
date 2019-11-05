// Problem Statement
// There are n flights, and they are labeled from 1 to n.

// We have a list of flight bookings.  The i-th booking bookings[i] = [i, j, k] means 
// that we booked k seats from flights labeled i to j inclusive.

// Return an array answer of length n, representing the number of seats 
// booked on each flight in order of their label.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> running(n,0), result(n,0);
        
        for(auto booking : bookings){
            running[booking[0]-1]+=booking[2];
            if(booking[1]<n)
                running[booking[1]]-=booking[2];
        }
        
        result[0]=running[0];
        for(int i=1;i<n;i++){
            result[i]=running[i]+result[i-1];
        }
        
        return result;
    }
};

void printVec(const vector<int> &vec){
    for(auto v : vec){
        cout<<v<<" ";
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    Solution sol;
    printVec(sol.corpFlightBookings(bookings,5));
    return 0;
}