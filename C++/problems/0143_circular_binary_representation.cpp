// Problem Statement
// Given 2 integers n and start. Your task is return any permutation p of (0,1,2.....,2^n -1) such that :
//  * p[0] = start
//  * p[i] and p[i+1] differ by only one bit in their binary representation.
//  * p[0] and p[2^n -1] must also differ by only one bit in their binary representation.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> generateGrey(const int&n){
        vector<int> curr_codes;
        for(int i=0;i<n;i++){
            vector<int> new_codes;
            if(curr_codes.size()==0){
                new_codes.push_back(0);
                new_codes.push_back(1);
            }else{
               for(int j=0;j<curr_codes.size();j++){
                   int code = curr_codes[j]<<1;
                   new_codes.push_back(code);
               }
               
               for(int j=curr_codes.size()-1;j>=0;j--){
                   int code = curr_codes[j]<<1;
                   code+=1;
                   new_codes.push_back(code);
               } 
            }
            
            curr_codes = new_codes;
        }
        
        return curr_codes;
    }
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> grey = generateGrey(n);
        vector<int> result;
        int start_index = 0;
        
        for(int i=0;i<grey.size();i++){
            if(grey[i]==start){
                start_index = i;
                break;
            }
        }
        
        int i = start_index;
        result.push_back(grey[start_index]);
        i= (i+1)%grey.size();
        while(i!=start_index){
            result.push_back(grey[i]);
            i= (i+1) %grey.size();
        }
        
        return result;
    }
};

void printVec(const vector<int> &vec){
    for(auto val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    Solution sol;
    printVec(sol.circularPermutation(2,3));
    return 0;
}