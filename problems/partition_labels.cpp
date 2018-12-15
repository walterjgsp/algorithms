// Problem Statement
//
// A string S of lowercase letters is given. We want to partition this string into
// as many parts as possible so that each letter appears in at most one part,
// and return a list of integers representing the size of these parts.
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    struct Interval{
        int start, end;
        Interval(int s, int e){
            start = s;
            end = e;
        }

        Interval(){};
    };

    static bool comparator(const Interval &i1, const Interval &i2){
        if(i1.start == i2.start)
            return i1.end<i2.end;
        return i1.start<i2.start;
    }
public:
    vector<int> partitionLabels(string S) {

        vector<int> to_return;

        if(S.empty())
            return to_return;

        unordered_map<char,Interval> helper;

        for(int i=0;i<S.size();i++){
            if(helper.find(S[i])!=helper.end()){
                helper[S[i]].end = i;
            }else{
                helper[S[i]] = Interval(i,i);
            }
        }

        vector<Interval> intervals, newIntervals;

        for(auto it : helper){
            intervals.push_back(it.second);
        }

        sort(intervals.begin(),intervals.end(),comparator);

        newIntervals.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(newIntervals.back().end>intervals[i].start){
                newIntervals.back().end = max(newIntervals.back().end,intervals[i].end);
            }else{
                newIntervals.push_back(intervals[i]);
            }
        }

        for(auto inter : newIntervals){
            to_return.push_back(inter.end-inter.start+1);
        }

        return to_return;
    }
};

void printVec(const vector<int> &vec){
  for(int val : vec)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  string word = "ababcbacadefegdehijhklij";
  Solution sol;

  printVec(sol.partitionLabels(word));

  return 0;
}
