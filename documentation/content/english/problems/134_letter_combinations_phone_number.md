+++
title = "Letter Combinations of a Phone Number"
description = "Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent."
date = 2019-09-30T06:59:35-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com"
link = "https://leetcode.com/problems/letter-combinations-of-a-phone-number"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

The mapping of digit to letters is {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}. Note that 1 does not map to any letters.

<h2 class="title is-5"> Solution </h2>

To solve this problem we use a recursive approach. First we define a base case, that will make our recursion calls stop. In this problem will be 
when we arrive at the end of the input string. For all the other calls in the algorithm we gonna get the respective letters from the current digit 
that are being processed, add to the end of a possible combination and call in recursive way the same function until the recursion stops.

The code to this solution:

{{< highlight cpp >}}

unordered_map<int,string> letters = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
vector<string> result;

void recursiveCombination(const string &digits,int index, string curr){
    if(index>=digits.size()){
        result.push_back(curr);
    }
    
    for(auto letter : letters[digits[index]-'0']){
        curr.push_back(letter);
        recursiveCombination(digits,index+1,curr);
        curr.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    result.clear();
    if(digits.empty()){
        return result;
    }
    string curr;
    recursiveCombination(digits,0,curr);
    return result;
}
{{< /highlight >}}

Time complexity: **O(3ˆn)**