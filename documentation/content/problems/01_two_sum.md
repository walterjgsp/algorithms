+++
title = "Two Sum"
description = "Given an array of integers, return indices of the two numbers such that they add up to a specific target."
date = 2019-02-16T19:37:40-02:00
weight = 20
draft = false
languages = ["C++","Kotlin"]
toc = true
level = 0
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/two-sum/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

<br/>
<h2 class="title is-4"> Questions to ask </h2>

Is the input array already sorted?

Is The input array mutable or read only?

<br/>
<h2 class="title is-4"> Solution </h2>

There are three main approaches to solve this problem: **Naive**, **Time Optimized**,**Memory Optimized**.

<br/>
**Naive**

<br/>
The naive approach consists in choosing the first position of the array and matching with the subsequents until we find the target value.
If we don't find it, we pick the second position and repeat the process. We repeat this process until we find the target value or all the pairs of positions are already tested.

Why should we avoid this naive approach? The time complexity for this solution is O(n²).

<br/>
**Time Optimized**

What if we could keep in memory all values that we've already encountered such that it is possible to query a certain target value, would it help us solve the problem ?

<br/>
The time optimized solution is based on a basic data structure, Map (HashMap).
With this structure we can keep a track of all the past values and also query if a value was already seen in O(1). How this helps?

<br/>
Let's say we have this kind of input:

**Array =  [2, 11, 7, 15]**

**Target = 9**

<br/>
If we lookup at the number 2 at the first index, knowing the target value, which is the value that we need to find in the array so that the sum of the two add to the target 9?
With basic math we find that is 7. The number 7 exists in the array, so i found my answer? Not yet.It is impossible to predict the future, but we can keep a track about the past,
this is why we use a **map**.

<br/>
IIn this approach, we traverse the array, looking for | target - number|, if we find it voilà! Otherwise, we add the value the current value on our map and proceed

<br/>
With this approach we have the following complexity:

*Time Complexity : O(n)*

*Space Complexity : O(n)*

where n is the number of elements in the array.

<br/>
**Memory Optimized**

<br/>
Let's assume that we don't have memory to spend when trying to solve this problem, and we just want to know if two values exists in the array, how we address it now?
If we can, we sort the array.

<br/>
With the array sorted we keep two pointers, one pointing to the first position of the array and the other pointing to the last. We get the two values of each pointer
and compare the result of the sum to the target. If the result is bigger than our target, we need to move the biggest pointer down, so our sum is smaller. Otherwise,
if we need to make result bigger, we increment the pointer with the smaller value (the one pointing to the first positon).

<br/>
With this approach we have the following complexity:

*Time Complexity : O(nlogn)*

*Space Complexity : O(1)*

where n is the number of elements in the array.
