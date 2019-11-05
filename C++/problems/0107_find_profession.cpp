// Problem Statement
// Consider a special family of Engineers and Doctors. This family has the following rules:

// Everybody has two children.
// The first child of an Engineer is an Engineer and the second child is a Doctor.
// The first child of a Doctor is a Doctor and the second child is an Engineer.
// All generations of Doctors and Engineers start with an Engineer.

// Given the level and position of a person in the ancestor tree above, find the profession of the person.
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    string findProfession(int level, int pos) {
        int start = 1, end = pow(2,level-1);
        bool isEngineer = true;
        
        while(start<end){
            int mid = start+(end-start)/2;
            
            if(pos<=mid){
                end = mid;            
            }else{
                isEngineer= !isEngineer;
                start = mid+1;
            }
        }
        
        if(isEngineer){
            return "Engineer";
        }else
            return "Doctor";
    }
};

int main(){
    Solution sol;
    cout<<sol.findProfession(3,3)<<endl;
    return 0;
}