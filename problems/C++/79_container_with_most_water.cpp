// Problem Statement
// Given n non-negative integers a1, a2, ..., an , where each represents a point at
// coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
// line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
// forms a container, such that the container contains the most water.
//
// Note: You may not slant the container and n is at least 2.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0,end=height.size()-1,maxArea=0,area;

        while(start<end){
            area = min(height[start],height[end])*(end-start);
            maxArea = max(maxArea,area);

            if(height[start]>height[end]){
                end--;
            }else
                start++;
        }

        return maxArea;
    }
};

int main(){
  vector<int> height = {1,8,6,2,5,4,8,3,7};
  Solution sol;
  cout<<sol.maxArea(height)<<endl;
  return 0
}
