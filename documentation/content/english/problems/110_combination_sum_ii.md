+++
title = "Combination Sum II"
description = "Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target."
date = 2019-06-12T21:59:24-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/combination-sum-ii/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

***Note:***

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

<h2 class="title is-4"> Questions to ask </h2>

Is the input vector already ordered? No

Can the input vector be modified? Yes

<h2 class="title is-5"> Solution </h2>

This problem is solved by a recursive and intelligent (brute force) method. It is enough to make an algorithm that has as the objective to test all the possibilities and taking advantage of the constraints of the problem to perform prunings to not process situations that do not make sense.

Before starting recursive processing, you need to sort the input vector, so it becomes easy to ensure that duplicate solutions will not occur.

The recursion algorithm will receive as parameters: the candidate vector, the target, the current vector that is a subset of the candidate vector, the sum of all values of the current vector, the position currently being processed in the candidate vector . In recursion there are three situations:


<div class = "margin_left">
   <ol>
     <li> The current sum value is less than target </li>
     <li> The value of the current sum is equal to the target </li>
     <li> Current sum value is higher than target </li>
   </ol>
</div>
</br>

In the third case just return, the constraints that all numbers are positive ensures that any further processing will only increase the current value. In the second case the result was found for that combination of the current vector, save it in the result array and return because of the same constraint of only positive values. In the first case you must perform the processing.

The processing consists of, for each position of the candidate vector starting from the received position as parameter + 1, put this element in the vector representing the subset of the candidates, add the value to the variable that represents all the values of the current subset, execute the recursive call and at the end remove that element from the subset. Do this until all the elements have been processed.

The implementation of this code is:

{{< highlight cpp >}}
class Solution{
private:
    vector<vector<int>> result;

    void helper(const vector<int> &nums, const int &target, vector<int> &curr, int &currSum, int pos){
        if(currSum>target){
            return;
        }

        if(currSum == target){
            result.push_back(curr);
            return;
        }

        for(int i=pos+1;i<nums.size();i++){
            curr.push_back(nums[i]);
            currSum+=nums[i];
            helper(nums,target,curr,currSum,i);
            curr.pop_back();
            currSum-=nums[i];

            while(i+1<nums.size() && nums[i]==nums[i+1])
                i++;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        result.clear();
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        int currSum = 0;
        helper(candidates,target,curr,currSum,-1);
        return result;
    }
};
{{< /highlight >}}

Time complexity: **O(N!)**