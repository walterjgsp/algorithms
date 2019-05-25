// Problem Statement
// N couples sit in 2N seats arranged in a row and want to hold hands. 
// We want to know the minimum number of swaps so that every couple is 
// sitting side by side. A swap consists of choosing any two people, 
// then they stand up and switch seats.

// The people and seats are represented by an integer from 0 to 2N-1,
// the couples are numbered in order, the first couple being (0, 1),
// the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

// The couples' initial seating is given by row[i] being the value of 
// the person who is initially sitting in the i-th seat.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> couples;
    
    int find(int x){
        if(couples[x]==x)
            return x;
        return find(couples[x]);
    }
    
    bool Union(int x, int y){
        int xcouple = find(x);
        int ycouple = find(y);
        
        if(xcouple == ycouple)
            return false;
        
        couples[xcouple]=ycouple;
        return true;
    }
public:
    int minSwapsCouples(vector<int>& row) {
        couples = vector<int> (row.size());
        for(int i=0;i<row.size();i+=2){
            couples[row[i]]=row[i];
            couples[row[i+1]]=row[i];
        }
        
        int result = 0;
        
        for(int i=0;i<row.size();i+=2){
            if(Union(i,i+1)){
                result++;
            }
        }
        
        return result;
    }
};

int main(){
    vector<int> couples = {0,2,1,3};
    Solution sol;
    cout<<sol.minSwapsCouples(couples)<<endl;
}