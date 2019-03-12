+++
title = "Sort Array By Parity"
description = "Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A."
date = 2019-03-09T14:29:27-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 0
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/sort-array-by-parity/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

<h2 class="title is-4"> Questions to ask </h2>

Is the input array mutable or read only? Mutable

Can i have negative numbers in my input array? Yes

<h2 class="title is-5"> Solution </h2>

There are two solutions for this problem with time complexity **O(n)** with just one pass in the array.

**Two Arrays**

Use two auxilary arrays, one for odd numbers and the other for even numbers, when looping through place each value in the right array.
After all the values are processed you merge the two arrays into one and return.

{{< highlight cpp >}}
vector<int> sortArrayByParity(vector<int>& A) {
  vector<int> odd,even;
  for(auto num : A){
      if(num%2)
          odd.push_back(num);
      else
          even.push_back(num);
  }

  even.insert(even.end(),odd.begin(),odd.end());

  return even;
}
{{< /highlight >}}


**Two pointers**

Use one pointer in the start of the array and another pointer in the end, loop until *start* is smaller than *end* pointer. If the value
in start position is odd and in end position is even, swap these two values and move the pointers toward the middle. Otherwise, just check
the pointers condition to move each one.

{{< highlight cpp >}}
vector<int> sortArrayByParityInPlace(vector<int>& A) {
  int start = 0, end = A.size()-1;

  while(start<end){
      if(A[start]%2!=0 && A[end]%2==0){
          swap(A[start],A[end]);
          start++;
          end--;
      }

      if(A[start]%2 == 0){
          start++;
      }

      if(A[end]%2 != 0){
          end--;
      }
  }

  return A;
}
{{< /highlight >}}
