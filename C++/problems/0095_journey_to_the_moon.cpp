//Problem Statement
// The member states of the UN are planning to send  people to the moon. They want them to be from different countries. 
// You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. 
// Determine how many pairs of astronauts from different countries they can choose from.

#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
    vector<pair<int, int>> parents;

    int find(const int &x){
        if (parents[x].first == x)
            return x;
        return find(parents[x].first);
    }

    void Union(const int &x, const int &y){
        int xparent = find(x), yparent = find(y);

        if (xparent != yparent){
            if(parents[xparent].second > parents[yparent].second){
                parents[yparent].first = xparent;
                parents[xparent].second += parents[yparent].second;
            }else{
                parents[xparent].first = yparent;
                parents[yparent].second += parents[xparent].second;
            }
        }
    }

public:
    long journeyToMoon(int n, vector<vector<int>> astronauts){
        parents = vector<pair<int,int>> (n);
        for(int i=0;i<n;i++){
            parents[i]={i,1};
        }

        for(auto ids : astronauts){
            Union(ids[0],ids[1]);
        }

        unordered_map<int,int> sets;
        for(int i=0;i<n;i++){
            int xparent = find(i);
            sets[xparent] = parents[xparent].second;
        }

        vector<int> setsSize;
        for(auto it : sets){
            setsSize.push_back(it.second);
        }

        vector<int> sumRight(setsSize.size(),0);

        sumRight.back() = setsSize.back();
        

        for(int i=setsSize.size()-2;i>=0;i--){
            sumRight[i] = sumRight[i+1]+setsSize[i];
        }

        long result = 0;
        for(int i=0;i<setsSize.size()-1;i++){
            result+=setsSize[i]*sumRight[i+1];
        }

        return result;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> astronauts = {{1, 2},{3,4}};
    cout << sol.journeyToMoon(100000, astronauts) << endl;
    return 0;
}