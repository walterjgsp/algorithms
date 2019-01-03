//Problem Statement
//
// Given a non-empty array of unique positive integers A, consider the following graph:
//
// *There are A.length nodes, labelled A[0] to A[A.length - 1];
// *There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
// Return the size of the largest connected component in the graph.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<int> getPrimes(const int &limit){
        vector<bool> helper(limit+1,true);
        vector<int> primes;

        for(int i=2;i<helper.size();i++){
            if(helper[i]){
                primes.push_back(i);
                for(int j=2;j*i<helper.size();j++){
                    helper[j*i]=false;
                }
            }
        }

        return primes;
    }

    int largestComponentSize(vector<int>& A) {

        int bigger_val = A[0];

        for(int i=1;i<A.size();i++){
            bigger_val = max(bigger_val,A[i]);
        }

        vector<int> primes = getPrimes(bigger_val);
        vector<pair<int,int>> find_helper (primes.size(),make_pair(-1,0));

        for(auto val : A){
            int last_prime = -1,index=0;

            while(index<primes.size() && primes[index]<=val){
                if(val%primes[index]==0){
                    if(last_prime==-1){
                        find_helper[index].second++;
                        last_prime=index;
                    }else{
                        Union(find_helper,last_prime,index);
                        last_prime = index;
                    }
                }
                index++;
            }
        }

        for(auto child : find_helper){
            if(child.first!=-1){
                int index = child.first;
                while(find_helper[index].first!=-1)
                    index = find_helper[index].first;

                find_helper[index].second+=child.second;
            }
        }

        int result = INT_MIN;

        for(auto child : find_helper){
            result = max(result,child.second);
        }

        return result;

    }

    int find(const vector<pair<int,int>> &parent,int val){
        if(parent[val].first == -1)
            return val;
        return find(parent,parent[val].first);
    }

    void Union(vector<pair<int,int>> &parent, int x, int y){

        int xroot = find(parent,x);
        int yroot = find(parent,y);

        if(xroot!=yroot){
            parent[xroot].first = yroot;
        }
    }
};

int main(){
  Solution sol;
  vector<int> vec = {4,6,15,35};
  cout<<sol.largestComponentSize(vec)<<endl;
  return 0;
}
