+++
title = "Valid Anagram"
description = "Given two strings s and t , write a function to determine if t is an anagram of s."
date = 2019-03-13T06:57:57-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 0
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/valid-anagram/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given two strings s and t , write a function to determine if t is an anagram of s.

<h2 class="title is-4"> Questions to ask </h2>

Characters in the string are only lowercase? Yes

Can special characters exist in the string? No

<h2 class="title is-5"> Solution </h2>

The solution is pretty straightforward. Knowing that the a character is a number from 0 to 255, make an array to count the frequency of characters from the first string. Now you will loop trough the second array and remove the character from the array that count the frequency. Loop through the frequency array and if some value is different from 0 return false. Otherwise return true when
the loop finish.

{{< highlight cpp >}}
bool isAnagram(string s, string t){
  vector<int> counter (26,0);

  for(auto letter : s){
    counter[letter-'a']++;
  }

  for(auto letter : t){
    counter[letter-'a']--;
  }

  for(auto count : counter){
    if(count!=0)
      return false;
  }

  return true;
}
{{< /highlight >}}

Time Complexity: **O(n)**

Space Complexity: **O(1)**
