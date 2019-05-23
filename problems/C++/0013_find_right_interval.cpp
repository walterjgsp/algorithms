// Problem Statement
// Given a set of intervals, for each of the interval i, check if there exists
// an interval j whose start point is bigger than or equal to the end point of the
// interval i, which can be called that j is on the "right" of i.
//
// For any interval i, you need to store the minimum interval j's index, which
// means that the interval j has the minimum start point to build the "right"
// relationship for interval i. If the interval j doesn't exist, store -1 for the
// interval i. Finally, you need output the stored value of each interval as an array.
//
// Note:
// You may assume the interval's end point is always bigger than its start point.
// You may assume none of these intervals have the same start point.

// Input: [ [3,4], [2,3], [1,2] ]
// Output: [-1, 0, 1]

#include<bits/stdc++.h>

using namespace std;

struct Interval {
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> createFromVec(vector<int> vec){
  vector<Interval> to_return;

  if(vec.size()%2!=0)
    return to_return;

  for(int i=0;i<vec.size();i+=2){
    Interval inter(vec[i],vec[i+1]);
    to_return.push_back(inter);
  }

  return to_return;
}

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int,set<int>> helper;

        if(intervals.size()<2){
            return {-1};
        }

        vector<int> starts,to_return;

        for(int i=0;i<intervals.size();i++){
            auto inter = intervals[i];
            helper[inter.start].insert(i);
        }

        for(auto it : helper){
            starts.push_back(it.first);
        }

        for(int i=0;i<intervals.size();i++){
            int target = intervals[i].end;
            int mid,low = 0, upper = starts.size()-1;

            while(low<=upper){
                mid = low+(upper-low)/2;

                if(starts[mid]==target){
                    low=mid;
                    break;
                }else if(starts[mid]<target){
                    low=mid+1;
                }else{
                    upper=mid-1;
                }
            }

            if(starts[low]<target){
                to_return.push_back(-1);
            }else{
                int index =  -1;

                auto possible = helper[starts[low]];

                for(auto it : possible){
                    if(it!=i){
                        index = it;
                        break;
                    }
                }

                to_return.push_back(index);
            }
        }

        return to_return;
    }
};

void printVec(const vector<int> vec){
  for(int val:vec){
    cout<<val<<",";
  }
  cout<<endl;
}

int main(){
  vector<int> vec = {1,4,2,3,3,4};
  vector<Interval> intervals = createFromVec(vec);
  Solution sol;
  printVec(sol.findRightInterval(intervals));
  return 0;
}
