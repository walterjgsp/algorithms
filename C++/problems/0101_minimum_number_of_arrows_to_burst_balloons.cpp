// Problem Statement
// There are a number of spherical balloons spread in two-dimensional space. 
// For each balloon, provided input is the start and end coordinates of the horizontal diameter.
// Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start 
// and end of the diameter suffice. Start is always smaller than end. 
// There will be at most 104 balloons.

// An arrow can be shot up exactly vertically from different points along the x-axis. 
// A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend.
// There is no limit to the number of arrows that can be shot.
// An arrow once shot keeps travelling up infinitely. 
// The problem is to find the minimum number of arrows that must be shot to burst all balloons.
#include <bits/stdc++.h>

using namespace std;

class Interval{
private:
    int start,end;
public:
    Interval(int s,int e){
        start = s,end = e;
    }

    int getStart(){
        return start;
    }

    int getEnd(){
        return end;
    }

    void setInterval(int s, int e){
        start = s, end = e;
    }

    bool operator< (const Interval &c2){
        if(start==c2.start){
            return end<c2.end;
        }
        return start<c2.start;
    }

    void printInterval(){
        cout<<"("<<start<<","<<end<<")"<<endl;
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
            return 0;

        vector<Interval> intervals;
        for(auto point : points){
            intervals.push_back(Interval(point[0],point[1]));
        }

        sort(intervals.begin(),intervals.end());
        vector<Interval> newIntervals;
        Interval currInterval = intervals[0];

        for(int i=1;i<intervals.size();i++){
            if(currInterval.getEnd()>=intervals[i].getStart()){
                int newStart = max(currInterval.getStart(),intervals[i].getStart());
                int newEnd = min(currInterval.getEnd(),intervals[i].getEnd());

                currInterval.setInterval(newStart,newEnd);
            }else{
                newIntervals.push_back(currInterval);
                currInterval = intervals[i];
            }
        }

        return newIntervals.size()+1;
    }
};

int main(){
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12},{3,5}};
    Solution sol;
    cout<<sol.findMinArrowShots(points);
    return 0;
}

