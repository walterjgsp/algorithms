//Problem Statement
// Markov takes out his Snakes and Ladders game, stares at the board and 
// wonders: "If I can always roll the die to whatever number I want, what 
// would be the least number of rolls to reach the destination?"

// Rules The game is played with a cubic die of 6 faces numbered 1 to 6.

// Starting from square 1, land on square 100 with the exact roll of the die. 
// If moving the number rolled would place the player beyond square 100, no move is made.

// If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.

// If a player lands at the mouth of a snake, the player must go down the snake and 
// come out through the tail. Snakes go down only.

//Return an integer that represents the minimum number of moves required.
#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
    unordered_map<int,int> mapVec(const vector<vector<int>> &vec){
        unordered_map<int,int> result;
        for(auto val : vec){
            result[val[0]] = val[1];
        }

        return result;
    }

public:
    int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
        unordered_map<int,int> map_ladders, map_snakes;
        map_ladders = mapVec(ladders);
        map_snakes = mapVec(snakes);

        vector<int> visited(101,-1);

        queue<int> bfs;

        bfs.push(1);
        int rows = 0;
        while(!bfs.empty()){
            int tam = bfs.size();

            for(int i=0;i<tam;i++){
                int current_pos = bfs.front();
                bfs.pop();

                if(current_pos==100){
                    return rows;
                }

                if(visited[current_pos]==-1){
                    visited[current_pos] = rows;

                    for(int j=current_pos+1;j<=current_pos+6 && j<=100;j++){
                        if (map_ladders.find(j) != map_ladders.end()) {
                        bfs.push(map_ladders[j]);
                        } else if (map_snakes.find(j) != map_snakes.end()) {
                        bfs.push(map_snakes[j]);
                        } else if (visited[j] == -1)
                        bfs.push(j);
                    }
                    
                }
            }

            rows++;
        }
        
        return -1;
    }
};

int main(){
    vector<vector<int>> ladders = {{32,62},{42,68},{12,98}};
    vector<vector<int>> snakes = {{95,13},{97,25},{93,37},{79,27},{75,19},{49,47},{67,17}};
    Solution sol;
    cout<<sol.quickestWayUp(ladders,snakes)<<endl;
    return 0;
}