// Problem Statement
// Given two lists of closed intervals, each list of intervals is pairwise disjoint
// and in sorted order.
//
// Return the intersection of these two interval lists.
//
// (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers
// x with a <= x <= b.  The intersection of two closed intervals is a set of real
// numbers that is either empty, or can be represented as a closed interval.
// For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
#include <bits/stdc++.h>

using namespace std;

struct Interval{
  int start;
  int end;
  Interval() : start(0), end(0){}
  Interval(int s, int e): start(s), end(e){}
  void toString(){
    cout<<"["<<start<<","<<end<<"]";
  }
};

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> result;

        int index_a=0,index_b=0;

        while(index_a<A.size() && index_b<B.size()){

            int newStart = max(A[index_a].start,B[index_b].start);
            int newEnd = min(A[index_a].end,B[index_b].end);

            if(newStart<=newEnd){
                Interval newInterval = Interval(newStart,newEnd);
                result.push_back(newInterval);
            }

            if(A[index_a].end<B[index_b].end)
                index_a++;
            else if(A[index_a].end>B[index_b].end)
                index_b++;
            else{
                index_a++;
                index_b++;
            }
        }

        return result;
    }
};

vector<Interval> vectOfIntervals(vector<vector<int>> arr){
  vector<Interval> newVec;
  for(auto value : arr){
    Interval interval = Interval(value[0],value[1]);
    newVec.push_back(interval);
  }
  return newVec;
};

void printIntervalVec(vector<Interval> vec){
  for(auto interval:vec){
    interval.toString();
    cout<<" ";
  }
  cout<<endl;
}

int main(){
  vector<vector<int>> A = {{0,2},{5,10},{13,23},{24,25}};
  vector<vector<int>> B = {{1,5},{8,12},{15,24},{25,26}};
  vector<Interval> vA = vectOfIntervals(A),vB = vectOfIntervals(B);
  Solution sol;
  printIntervalVec(sol.intervalIntersection(vA,vB));
  return 0;
}
