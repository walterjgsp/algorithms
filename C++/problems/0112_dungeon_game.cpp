#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
    pair<int,int> addCost(const pair<int,int> &cell, int value){
        pair<int,int> newCost = {cell.first,cell.second};
        if(value<0){
            newCost.first+=value;
        }else{
            int healing = newCost.first+value;
            if(healing>0){
                newCost.first=0;
                newCost.second=healing;
            }else{
                newCost.first = healing;
                newCost.second = 0;
            }
        }

        return newCost;
    }

    pair<int,int> betterCost(pair<int,int> p1, pair<int,int> p2){
        if(p1.first==p2.first){
            if(p1.second>p2.second) return p1;
            else return p2;
        }else if(p1.first<p2.first)
            return p2;
        else return p1;
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon){
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<pair<int,int>>> cost (n,vector<pair<int,int>>(m,{0,0}));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    cost[i][j] = addCost(cost[i][j],dungeon[i][j]);
                }else if(i==n-1){
                    cost[i][j] = addCost(cost[i][j+1],dungeon[i][j]);
                }else if(j==m-1){
                    cost[i][j] = addCost(cost[i+1][j],dungeon[i][j]);
                }else{
                    auto better = betterCost(cost[i][j+1],cost[i+1][j]);
                    cost[i][j] = addCost(better,dungeon[i][j]);
                }
            }
        }

        int result = cost[0][0].first;
        if(result>0)
            return 0;
        return (-1*result)+1;
    }
};

int main(){
    // vector<vector<int>> dungeon = {{-1,3,-1},{1,-3,-2},{10,-10,-5},{-30,-20,-7}};
    vector<vector<int>> dungeon = {{1,-3,3},{0,-2,0},{-3,-3,-3}};
    Solution sol;
    cout<<sol.calculateMinimumHP(dungeon)<<endl;
    return 0;
}