+++
title = "Min Cost Climbing Stairs"
description = "You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1."
date = 2019-03-13T21:30:24-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 0
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/min-cost-climbing-stairs/"
+++
<h2 class="title is-4"> Problem Statement </h2>

On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum
cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

<h2 class="title is-5"> Solution </h2>

To solve this problem we going to use dynamic programming. For each index on the array, the most important values are i-2 and i-1
because they represent the immediate cost that i need to pay so i can arrive at my actual index. Since i want to minimize the cost,
i will choose the minimum value between my actual cost and one of the previous costs that make it possible i arrive at my actual position.
Keeping a track of this values with an array make it possible to find an answer.

{{< highlight cpp >}}
int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    vector<int> dp(cost.size(),0);
    dp[0]=cost[0],dp[1]=cost[1];

    for(int i=2;i<dp.size();i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }

    return dp.back();
}
{{< /highlight >}}

Time Complexity: **O(n)**

Space Complexity: **O(n)**
