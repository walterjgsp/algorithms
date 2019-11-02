//Problem Statement
//Given n non-negative integers representing an elevation map where the width
//of each bar is 1, compute how much water it is able to trap after raining.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;

        vector<int> right_max(height.size(),0),left_max(height.size(),0);

        left_max[0]=height[0];
        for(int i=1;i<height.size();i++){
            left_max[i]=max(height[i],left_max[i-1]);
        }

        right_max[height.size()-1] = height.back();
        for(int j=height.size()-2;j>=0;j--){
            right_max[j]=max(height[j],right_max[j+1]);
        }

        int result = 0;
        for(int i=1;i<height.size()-1;i++){
            int water = min(left_max[i],right_max[i])-height[i];
            result+=max(water,0);
        }

        return result;
    }
};

int main(){
  vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution sol;
  cout<<sol.trap(heights)<<endl;
  return 0;
}
