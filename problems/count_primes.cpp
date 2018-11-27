// Problem Statement

// Count the number of prime numbers less than a non-negative number, n.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1,true);
        int to_return = 0;

        for(int i=2;i<n;i++){

            if(!primes[i])
                continue;
            else{
                to_return++;
                for(int j=2;j*i<n;j++){
                    primes[j*i]=false;
                }
            }
        }

        return to_return;
    }
};

int main(){
  Solution sol;
  cout<<sol.countPrimes(16)<<endl;
  return 0;
}
