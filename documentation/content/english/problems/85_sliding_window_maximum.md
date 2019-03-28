+++
title = "Sliding Window Maximum"
description = "Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window."
date = 2019-03-28T19:06:02-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 2
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/sliding-window-maximum/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

<h2 class="title is-4"> Questions to ask </h2>

Can i have negative numbers in my input array? Yes

<h2 class="title is-5"> Solution </h2>

{{< highlight cpp >}}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> indexes;
    vector<int> result;

    for(int i=0;i<nums.size();i++){

        if(!indexes.empty() && indexes.front()<=i-k){
            indexes.pop_front();
        }
        while(!indexes.empty() && nums[i]>nums[indexes.back()]){
            indexes.pop_back();
        }
        indexes.push_back(i);

        if(i>=k-1){
            result.push_back(nums[indexes.front()]);
        }
    }

    return result;
}
{{< /highlight >}}

Time complexity: **O(n)**

Space complexity: **O(n)**
