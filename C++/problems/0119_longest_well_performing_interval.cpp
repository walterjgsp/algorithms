// Problem Statement
// We are given hours, a list of the number of hours worked per day for a given employee.

// A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

// A well-performing interval is an interval of days for which the number of tiring days is strictly larger than
// the number of non-tiring days.

// Return the length of the longest well-performing interval.
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int longestWPI(vector<int> &hours){
        unordered_map<int, int> memo;
        int sum = 0, result = 0;
        for (int i = 0; i < hours.size(); i++){
            if (hours[i] > 8){
                sum++;
            }
            else{
                sum--;
            }

            if (sum > 0) 
                result = i + 1;
            else if (memo.find(sum - 1) != memo.end()) 
                result = max(result, i - memo[sum - 1]);

            if (memo.find(sum) == memo.end()) 
                memo[sum] = i;
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> hours = {9,9,6,0,6,6,9};
    cout<<sol.longestWPI(hours)<<endl;

    return 0;
}