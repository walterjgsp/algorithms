//Problem Statement
// A conveyor belt has packages that must be shipped from one port to another within D days.
//
// The i-th package on the conveyor belt has a weight of weights[i].
// Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
// We may not load more weight than the maximum weight capacity of the ship.
//
// Return the least weight capacity of the ship that will result in all the packages
// on the conveyor belt being shipped within D days.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int daysToPack(const vector<int> &weights, int maxWeight){
        int days = 1,actual_weight=0;
        for(auto val : weights){
            if(actual_weight+val>maxWeight){
                days++;
                actual_weight=0;
            }
            actual_weight+=val;
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int lower = 0,upper = 0;

        for(auto val : weights){
            lower = max(lower,val);
            upper+=val;
        }

        while(lower<upper){
            int mid = lower+(upper-lower)/2;

            if(daysToPack(weights,mid)>D){
                lower=mid+1;
            }else{
                upper = mid;
            }
        }

        return lower;
    }
};

int main(){
  vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
  int d = 5;
  Solution sol;

  cout<<sol.shipWithinDays(weights,d)<<endl;
  return 0;
}
