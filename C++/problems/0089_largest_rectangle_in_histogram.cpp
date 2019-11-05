// Problem Statement
// Given n non-negative integers representing the histogram's bar height where the
// width of each bar is 1, find the area of largest rectangle in the histogram.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indexes;
        int result = 0,i=0;

        while(i<heights.size()){
            if(indexes.empty() || heights[indexes.top()]<heights[i])
                indexes.push(i++);
            else{
                int top = indexes.top();
                indexes.pop();

                int area;
                if(indexes.empty()){
                    area = heights[top] * i;
                }else{
                    area = heights[top] * (i-indexes.top()-1);
                }

                result = max(result,area);
            }

        }

        while(!indexes.empty()){
            int top = indexes.top();
            indexes.pop();

            int area;
            if(indexes.empty()){
                area = heights[top] * i;
            }else{
                area = heights[top] * (i-indexes.top()-1);
            }

            result = max(result,area);
        }

        return result;
    }
};

int main(){
  vector<int> histogram = {2,1,5,6,2,3};
  Solution sol;
  cout<<sol.largestRectangleArea(histogram)<<endl;
  return 0;
}
