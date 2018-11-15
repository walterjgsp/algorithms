// Problem Statement
// Given a collection of intervals, find the minimum number of intervals you need
// to remove to make the rest of the intervals non-overlapping.
//
// Note:
// You may assume the interval's end point is always bigger than its start point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
//
// Input: [ [1,2], [2,3], [3,4], [1,3] ]
// Output: 1

#include<bits/stdc++.h>

using namespace std;

struct Interval{
  int start;
  int end;
  Interval(){
    start = 0;
    end = 0;
  }

  Interval(int s,int e){
    start = s;
    end = e;
  }
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

class Solution{
public:
  static bool comparator(const Interval &i1, const Interval &i2){
    if(i1.start==i2.start)
      return i1.end<i2.end;
    return i1.start<i2.start;
  }

  int eraseOverlapIntervals(vector<Interval>& intervals){

    if(intervals.size()<2)
      return 0;

    sort(intervals.begin(),intervals.end(),comparator);

    int i=0,j=1,to_return=0;

    while (j<intervals.size()) {

      if(intervals[i].end>intervals[j].start){
        intervals[j].start=intervals[i].start;
        intervals[j].end = min(intervals[j].end,intervals[i].end);
        to_return++;
      }

      i++;
      j++;
    }

    return to_return;
  }
};

int main(){
  vector<int> vec = {1,2,1,2,1,2};
  vector<Interval> intervals = createFromVec(vec);
  Solution sol;
  cout<<sol.eraseOverlapIntervals(intervals)<<endl;
  return 0;
}
