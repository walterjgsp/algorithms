//Problem Statement
// Koko loves to eat bananas.
// There are N piles of bananas, the i-th pile has piles[i] bananas.
// The guards have gone and will come back in H hours.
//
// Koko can decide her bananas-per-hour eating speed of K.
// Each hour, she chooses some pile of bananas, and eats K bananas from that pile.
// If the pile has less than K bananas, she eats all of them instead, and won't
// eat any more bananas during this hour.
//
// Koko likes to eat slowly, but still wants to finish eating all the bananas before
// the guards come back.
//
// Return the minimum integer K such that she can eat all the bananas within H hours.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int getHours(const vector<int> &piles, int bananas_hour){
        int hours_spent = 0;
        for(auto pile : piles){
            if(pile<bananas_hour)
                hours_spent++;
            else if(pile%bananas_hour==0)
                hours_spent+=pile/bananas_hour;
            else
                hours_spent+=(pile/bananas_hour)+1;
        }

        return hours_spent;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int low_bananas = 1, upper_bananas = INT_MIN;

        for(auto pile : piles){
            upper_bananas = max(upper_bananas,pile);
        }

        while(low_bananas<upper_bananas){
            int mid_bananas = low_bananas + (upper_bananas-low_bananas)/2;

            int hours_spent = getHours(piles,mid_bananas);

            if(hours_spent<=H){
                upper_bananas = mid_bananas;
            }else{
                low_bananas = mid_bananas+1;
            }
        }

        return upper_bananas;
    }
};

int main(){
  vector<int> piles = {30,11,23,4,20};
  int H = 6;
  Solution sol;
  cout<<sol.minEatingSpeed(piles,H)<<endl;
  return 0;
}
