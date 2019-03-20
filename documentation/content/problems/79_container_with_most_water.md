+++
title = "Container With Most Water"
description = "Find two lines, which together with x-axis forms a container, such that the container contains the most water. "
date = 2019-03-20T06:40:40-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/container-with-most-water/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

**Note:** You may not slant the container and n is at least 2.

<h2 class="title is-5"> Solution </h2>

The area is dependent on the distance between the two heights and the minimum height between the two. It is possible
to control in linear way the distance between the heights, starting from a point where the biggest distance is selected
and shrink it over time.

The biggest possible distance between heights can be found using two pointers, one in the start of the array and another at the end.
Calculate the area and shrink the distance. To shrink optimally select the pointer that have the smallest value and move it to the middle.
The loop will go through until the pointers position are different.

{{< highlight cpp >}}
int maxArea(vector<int>& height) {
    int start=0,end=height.size()-1,maxArea=0,area;

    while(start<end){
        area = min(height[start],height[end])*(end-start);
        maxArea = max(maxArea,area);

        if(height[start]>height[end]){
            end--;
        }else
            start++;
    }

    return maxArea;
}
{{< /highlight >}}

Time complexity: O(n)
Space complexity: O(1)
