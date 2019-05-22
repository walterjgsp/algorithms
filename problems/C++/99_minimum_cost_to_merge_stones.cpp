//Problem Statement
// There are N piles of stones arranged in a row.  The i-th pile has stones[i] stones.

// A move consists of merging exactly K consecutive piles into one pile, and the 
// cost of this move is equal to the total number of stones in these K piles.

// Find the minimum cost to merge all piles of stones into one pile.  If it is impossible, return -1.
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> sums;
    int mK;
    vector<vector<vector<int>>> memo;

    void initSums(const vector<int> &stones){
        sums.push_back(0);
        for(int i=0;i<stones.size();i++){
            sums.push_back(stones[i]+sums.back());
        }
    }

    int mergeCost(const vector<int> &stones, int i, int j, int piles){
        // if i already calculated this value, return
        if (memo[i][j][piles] != 0) 
            return memo[i][j][piles];

        //it the quantity of stones to merge is smaller than the number of piles
        if (j - i + 1 < piles) 
            return INT_MAX;
        
        if (i == j) 
            return (piles == 1) ? 0 : INT_MAX;

        if (piles == 1) {
            int subMinCost = mergeCost(stones,i, j, mK);
            if (subMinCost != INT_MAX) 
                memo[i][j][piles] = sums[j] - sums[i - 1] + subMinCost;
            else 
                memo[i][j][piles] = subMinCost;
            
            return memo[i][j][piles];
        }

        int minCost = INT_MAX;
        for (int k = i; k <= j - 1; k++) {
            int leftCost = mergeCost(stones,i, k, piles - 1);
            
            if (leftCost == INT_MAX) 
                continue;
            int rightCost = mergeCost(stones,k + 1, j, 1);
            
            if (rightCost == INT_MAX) 
                continue;
            
            minCost = min(leftCost + rightCost, minCost);
        }
        
        memo[i][j][piles] = minCost;
        return minCost;
    }

public:
    int mergeStones(vector<int>& stones, int K) {
        int ssize = stones.size();

        mK = K;

        if ((ssize - 1) % (K - 1) > 0) 
            return -1;
        else if(ssize==1)
            return 0;
        
        memo = vector<vector<vector<int>>>(ssize+1,
            vector<vector<int>> (ssize+1,
            vector<int>(K+1)));

        initSums(stones);

        return mergeCost(stones,1, ssize, 1);
    }
};

int main(){
    vector<int> stones = {3,2,4,1};
    Solution sol;
    cout<<sol.mergeStones(stones,2)<<endl;
}
