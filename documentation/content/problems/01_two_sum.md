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

What if we could keep a memory of all the values that we already pass in the array and it is possible to make a query about a certain value really fast, this help us to solve the problem?

<br/>
The time optimized solution is based on a basic structure of coding, the **Map** (HashMap). With this structure i can keep a track of all the past values and also query if a value was already
seen in O(1). How this helps?

<br/>
Let's say we have this kind of input:

**Array =  [2, 11, 7, 15]**

**Target = 9**

<br/>
If we lookup at the number 2 at the first index, knowing the target value, which is the value that we need to find in the array so that the sum of the two add to the target 9?
With basic math we find that is 7. The number 7 exists in the array, so i found my answer? Not yet.It is impossible to devise the future, but we can keep a track about the past,
this is why we use a **map**.

<br/>
In this approach, we traverse the array, looking if the complement of the target minus the value we are processing is in the map, and if not, we add the value we are processing on the map
and go to the next one until we find the solution.

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
and compare the result of the sum to the target. If the result is bigger than the target we need to move the pointers in a way that the result of the sum get smaller.
To do this we decrement the pointer with the bigger value (the one pointing to the last position). Otherwise, if we need to make the result bigger, we increment the
pointer with the smaller value (the one pointing to the first positon).

<br/>
With this approach we have the following complexity:

*Time Complexity : O(nlogn)*

*Space Complexity : O(1)*

where n is the number of elements in the array.
