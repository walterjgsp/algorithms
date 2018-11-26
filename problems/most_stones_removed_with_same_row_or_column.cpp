class DSU {
    
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int size){
        rank.resize(size , 0);
        parent.resize(size , 0);
        for(int i=0;i<size;i++)
            parent[i]=i;
    }
    
    // (uses path compression technique) 
     int Find(int x){
        if(parent[x]!=x)
            parent[x] = Find(parent[x]);
        return parent[x];
     }
    
     void Union (int x, int y){
        //Naive implementation
        //return parent[find(x)] = find(y);
        
        //(uses union by rank)
        int xroot=Find(x);
        int yroot=Find(y);
        
        if(rank[xroot] == rank[yroot]){
            parent[yroot] = xroot;
            rank[xroot]++;
        }else if(rank[xroot] > rank[yroot]){
            parent[yroot] = xroot;
        }else{
            parent[xroot] = yroot;
        }
     }       
    
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        DSU dsu(20000);
        
        for(int i=0;i<stones.size();i++){
            dsu.Union(stones[i][0],stones[i][1]+10000);
        }
        
        unordered_set<int> s;
        for(int i=0;i<stones.size();i++){
            s.insert(dsu.Find(stones[i][0]));
        }
        
        return stones.size() - s.size();
        
    }
};
