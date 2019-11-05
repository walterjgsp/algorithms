// Problem Statement
// A frog is crossing a river. The river is divided into x units and at each unit
// there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
//
// Given a list of stones' positions (in units) in sorted ascending order,
// determine if the frog is able to cross the river by landing on the last stone.
// Initially, the frog is on the first stone and assume the first jump must be 1 unit.
//
// If the frog's last jump was k units, then its next jump must be either k - 1, k,
// or k + 1 units. Note that the frog can only jump in the forward direction.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> dp;

        dp[1].insert(1);
        for(int i=1;i<stones.size()-1;i++){
            if(dp.find(stones[i])==dp.end())
                continue;
            else{
                for(auto jump : dp[stones[i]]){
                    dp[stones[i]+jump].insert(jump);
                    dp[stones[i]+jump+1].insert(jump+1);
                    if(jump-1>0)
                        dp[stones[i]+jump-1].insert(jump-1);
                }
            }
        }

        return dp.find(stones.back())!=dp.end();
    }
};

int main(){
  vector<int> stones = {0,1,3,5,6,8,12,17};
  Solution sol;
  cout<<sol.canCross(stones)<<endl;
}
