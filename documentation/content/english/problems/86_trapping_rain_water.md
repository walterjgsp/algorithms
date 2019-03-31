+++
title = "Trapping Rain Water"
description = "Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining."
date = 2019-03-31T17:30:00-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 2
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/trapping-rain-water/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

<h2 class="title is-4"> Questions to ask </h2>

Can the boundaries hold water? No

<h2 class="title is-5"> Solution </h2>

To solve this problem compute two auxiliary arrays containing the maximum values at the right and at the left of a i-th position. The height minus the minimum value between
the two arrays is going to show how much water can be trapped in every position of the array. If the value is negative means that no water can be trapped and does not add to the final
result.

{{< highlight cpp >}}
int trap(vector<int>& height) {
    if(height.empty())
        return 0;

    vector<int> right_max(height.size(),0),left_max(height.size(),0);

    left_max[0]=height[0];
    for(int i=1;i<height.size();i++){
        left_max[i]=max(height[i],left_max[i-1]);
    }

    right_max[height.size()-1] = height.back();
    for(int j=height.size()-2;j>=0;j--){
        right_max[j]=max(height[j],right_max[j+1]);
    }

    int result = 0;
    for(int i=1;i<height.size()-1;i++){
        int water = min(left_max[i],right_max[i])-height[i];
        result+=max(water,0);
    }

    return result;
}
{{< /highlight >}}

Time complexity: **O(n)**

Space complexity: **O(n)**
