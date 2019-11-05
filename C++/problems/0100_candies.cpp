// Problem Statement
// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left(ratings.size(),1),right(ratings.size(),1);
        int result = 0;
        
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
        }
        
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i] = right[i+1]+1;
            }
        }
        
        for(int i=0;i<ratings.size();i++){
            result+=max(left[i],right[i]);
        }
        
        return result;
    }
};

int main(){
    vector<int> candies = {2,4,2,6,1,7,8,9,2,1};
    Solution sol;
    cout<<sol.candy(candies)<<endl;
    return 0;
}