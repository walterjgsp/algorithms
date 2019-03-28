+++
title = "Squares of a Sorted Array"
description = "Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order."
date = 2019-03-09T01:26:01-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 0
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/squares-of-a-sorted-array/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

<h2 class="title is-4"> Questions to ask </h2>

Can i have negative numbers in my input array?

Is the input array mutable or read only?

<h2 class="title is-5"> Solution </h2>

The naive solution is to traverse the array calculating the square of each value and adding the result in a array to return. After this loop
we sort the result array and return.

The time complexity of this code is **O(N logn)** that is the cost to sort the array.

A more optimized solution can be achived if we use two pointers and the information that the array is already sorted.

Keep one pointer in the initial position and other in the final position of the input array. Using absolute difference we discover the bigger
value and we add the square of this value in the result array. The last step is to move the pointer were we found the bigger value,
if was the initial we increment this pointer, otherwise we decrement the final position pointer. We are going to have a result array sorted in reverse order,
reverse the array and we found a solution.

{{< highlight cpp >}}
vector<int> sortedSquares(vector<int>& A) {
    vector<int> result;
    int start = 0, end = A.size()-1;
    while(start<=end){
        if(abs(A[start])<abs(A[end])){
            result.push_back(A[end]*A[end]);
            end--;
        }else{
            result.push_back(A[start]*A[start]);
            start++;
        }
    }

    reverse(result.begin(),result.end());
    return result;
}
{{< /highlight >}}

The time complexity of this code is **O(n)**
