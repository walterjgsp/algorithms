// Problem Statement
// On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].

// Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]
// We may make the following moves:

// 'U' moves our position up one row, if the position exists on the board;
// 'D' moves our position down one row, if the position exists on the board;
// 'L' moves our position left one column, if the position exists on the board;
// 'R' moves our position right one column, if the position exists on the board;
// '!' adds the character board[r][c] at our current position (r, c) to the answer.
// (Here, the only positions that exist on the board are positions with letters on them.)

// Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  
// You may return any path that does so.
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    unordered_map<char, pair<int, int>> board;
    pair<int,int> pos_z = make_pair(5,0);

    string move(const int &quant, const char &dir){
        return string(quant,dir);
    }

    string get_path(pair<int, int> from, pair<int, int> to)
    {
        string path;
        bool add_end = false;
        if(from == pos_z && to!=pos_z){
            from.first--;
            path+='U';
        }else if(from != pos_z && to == pos_z){
            add_end = true;
            to.first--;
        }

        int row = to.first - from.first, col = to.second - from.second;

        if(row<0) path+=move(abs(row),'U');
        if(row>0) path+=move(row,'D');
        if(col<0) path+=move(abs(col),'L');
        if(col>0) path+=move(col,'R');

        if(add_end) path+='D';

        path+='!';
        return path;
    }

public:
    Solution()
    {
        vector<string> grid = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                board[grid[i][j]] = make_pair(i, j);
            }
        }
    }

    string alphabetBoardPath(string target)
    {
        pair<int, int> curr_position = make_pair(0, 0);
        string result;
        for (auto t : target)
        {
            auto new_position = board[t];
            result += get_path(curr_position, new_position);
            curr_position = new_position;
        }

        return result;
    }
};

int main()
{
    string test = "zvz";
    Solution sol;
    cout<<sol.alphabetBoardPath(test)<<endl;
    return 0;
}