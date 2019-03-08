//Problem Statement
// Implement pow(x, n), which calculates x raised to the power n(x^n).
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, long n) {
        if(n==0)
            return 1;
        if(n<0)
            return myPow(1/x,-n);
        if(n%2==0)
            return myPow(x*x,n/2);
        else
            return x*myPow(x*x,n/2);
    }
};

int main(){
  Solution sol;
  cout<<sol.myPow(2.1000,3)<<endl;
  return 0;
}
