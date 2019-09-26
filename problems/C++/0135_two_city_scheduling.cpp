//Problem Statement
// There are 2N people a company is planning to interview. The cost of flying the i-th person to 
// city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

// Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.
#include <bits/stdc++.h>

using namespace std;

const bool compare(const vector<int> &p1, const vector<int> &p2){
    int diff1 = abs(p1[0]-p1[1]), diff2 = abs(p2[0]-p2[1]);
    return diff1>diff2;
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),compare);
        int countA = 0,countB = 0, size = costs.size()/2;
        int result = 0;
        
        for(auto cost : costs){
            if(countA<size && countB<size){
                if(cost[0]<cost[1]){
                    result+=cost[0];
                    countA++;
                }else{
                    result+=cost[1];
                    countB++;
                }
            }else if(countA<size){
                result+=cost[0];
                countA++;
            }else{
                result+=cost[1];
                countB++;
            }
        }
        
        return result;
    }
};

int main(){
    vector<vector<int>> costs = {{10,20},{30,200},{400,50},{30,20}};
    Solution sol;
    cout<<sol.twoCitySchedCost(costs)<<endl;

    return 0;
}