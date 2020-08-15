//Problem Statement
// The median of a set of integers is the midpoint value of the data set for which an equal 
// number of integers are less than and greater than the value. To find the median, you must 
// first sort your set of integers in non-decreasing order, then:

// If your set contains an odd number of elements, the median is the middle element of the sorted sample. 
// In the sorted set ,  is the median.
// If your set contains an even number of elements, the median is the average of the two middle elements 
// of the sorted sample. In the sorted set ,  is the median.
// Given an input stream of  integers, you must perform the following task for each  integer:

// Add the  integer to a running list of integers.
// Find the median of the updated list (i.e., for the first element through the  element).
// Print the list's updated median on a new line. The printed value must be a double-precision number scaled to 
// decimal place (i.e.,  format).
#include "0172_finding_running_median.hpp"
#include <bits/stdc++.h>

using namespace std;


vector<double> Solution::runningMedian(vector<int> a){
    priority_queue<float,vector<float>,greater<float>> minH;
    priority_queue<float> maxH;
    vector<double> result;
    double curr_median = a[0];

    for(auto val : a){
        if(val<=curr_median){
            maxH.push(val);
        }else{
            minH.push(val);
        }

        int diff = maxH.size()-minH.size();
        if(abs(diff)>1){
            if(maxH.size()>minH.size()){
                minH.push(maxH.top());
                maxH.pop();
            }else{
                maxH.push(minH.top());
                minH.pop();
            }
        }

        if(maxH.size() == minH.size()){
            curr_median = (minH.top()+maxH.top())/2;
        }else if(maxH.size()>minH.size()){
            curr_median = maxH.top();
        }else{
            curr_median = minH.top();
        }

        result.push_back(curr_median);
    }

    return result;
}