//Problem Statement

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
//(you may want to display this pattern in a fixed font for better legibility)

//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"

//Write the code that will take a string and make this conversion given a number of rows:
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> helper(numRows);
        bool going_down = true;
        int row_to_print = 0;
        string result;

        for(auto c : s){
            if(going_down){
                helper[row_to_print].push_back(c);
                row_to_print++;
                if(row_to_print==numRows){
                    row_to_print = numRows-2;
                    going_down = false;
                    if(row_to_print <= 0){
                        row_to_print = 0;
                        going_down = true;
                    }
                }
            }else{
                for(int i = numRows-1;i>=0;i--){
                    if(i!=row_to_print){
                        helper[i].push_back(' ');
                    }else{
                        helper[i].push_back(c);
                    }
                }
                row_to_print--;
                if(row_to_print == 0){
                    going_down = true;
                }
            }
        }

        for(auto vec : helper){
            for (auto c : vec){
                if(c!=' ')result.push_back(c);
            }
        }

        return result;
    }
};

int main(){
    string word = "PAYPALISHIRING";
    Solution sol;
    cout<<sol.convert(word,4);

    return 0;
}