+++
title = "Two Sum"
description = "Given an array of integers, return indices of the two numbers such that they add up to a specific target."
date = 2019-02-16T19:37:40-02:00
weight = 20
draft = false
languages = ["C++","Kotlin"]
toc = true
level = 0
+++
<h2 class="title is-4"> Problem Statement </h2>

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

<br/>
<h2 class="title is-4"> Questions to ask </h2>

The input array is already sorted?

The input array is mutable or read only?

<br/>
<h2 class="title is-4"> Solution </h2>

There are three main approaches to solve this problem: **Naive**, **Time Optimized**,**Memory Optimized**.

<br/>
**Naive**

<br/>
The naive approach consists in choosing the first position of the array and matching with the subsequents until we find the target value.
If we don't find, we pick the second position and repeat the process. We repet this process until the target value is find or all the pairs of positions are already tested.

Why we avoid to use the naive approach? The time complexity for this solution is O(n²).

<br/>
**Time Optimized**


<br/>
**Memory Optimized**

<br/>
Let's assume that we don't have memory to spend when trying to solve this problem, how we address it now? If we can, we sort the array.
