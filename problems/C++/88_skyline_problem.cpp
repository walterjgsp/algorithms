// Problem Statement
// A city's skyline is the outer contour of the silhouette formed by all the buildings
// in that city when viewed from a distance. Now suppose you are given the locations and height of all
// the buildings, write a program to output the skyline formed by these buildings collectively.
//
// The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi],
// where Li and Ri are the x coordinates of the left and right edge of the ith building,
// respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX,
// and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely
// flat surface at height 0.
//
// For instance, the dimensions of all buildings are recorded as:
// [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
//
// The output is a list of "key points" in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ]
// that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment.
// Note that the last key point, where the rightmost building ends, is merely used to
// mark the termination of the skyline, and always has zero height.
// Also, the ground in between any two adjacent buildings should be
// considered part of the skyline contour.
//
// For instance, the skyline from the given dimensions should be represented as:
// [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int,int>> buildingToPoints(vector<int> &building){
        vector<pair<int,int>> points;

        points.push_back({building[0],building[2]});
        points.push_back({building[1],0});

        return points;
    }

    vector<pair<int,int>> mergeSkylines(vector<pair<int,int>> &s1,vector<pair<int,int>> &s2){
        vector<pair<int,int>> result;
        vector<int> last_height (2,0);
        int i=0,j=0;

        while(i<s1.size() || j<s2.size()){
            pair<int,int> t1 = {INT_MAX,0}, t2 = {INT_MAX,0}, tA;

            if(i<s1.size())
                t1 = s1[i];

            if(j<s2.size())
                t2 = s2[j];

            if(t1.first == t2.first){
                tA.first = t1.first;
                tA.second = max(t1.second,t2.second);
                i++;
                j++;
                last_height[0]=t1.second;
                last_height[1]=t2.second;
            }else if(t1.first<t2.first){
                tA=t1;
                i++;
                last_height[0]=t1.second;
                tA.second=max(last_height[0],last_height[1]);
            }else{
                tA=t2;
                j++;
                last_height[1]=t2.second;
                tA.second = max(last_height[1],last_height[0]);
            }

            if(result.empty() || result.back().second != tA.second)
                result.push_back(tA);
        }

        return result;
    }

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        deque<vector<pair<int,int>>> merge;
        for(auto build : buildings){
            merge.push_back(buildingToPoints(build));
        }

        while(merge.size()>1){
            auto sky1 = merge.front();
            merge.pop_front();
            auto sky2 = merge.front();
            merge.pop_front();
            merge.push_back(mergeSkylines(sky1,sky2));
        }

        return merge.front();
    }
};

void printVec(const vector<pair<int,int>> &points){
  for(auto point : points){
    cout<<"["<<point.first<<","<<point.second<<"]";
  }
  cout<<endl;
}

int main(){
  vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
  Solution sol;
  printVec(sol.getSkyline(buildings));
  return 0;
}
