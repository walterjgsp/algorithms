#include <bits/stdc++.h>

using namespace std;

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

int main(){

        DSU dsu(10);
        dsu.Union(1,2);
        dsu.Union(2,3);
        dsu.Union(4,5);
        cout<<dsu.Find(4)<<endl;
        cout<<dsu.Find(2)<<endl;
  		cout<<dsu.Find(3)<<endl;
}
