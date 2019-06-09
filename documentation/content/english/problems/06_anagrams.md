+++
title = "Anagrams"
description = "Given two strings, a and b, that may or may not be of the same length, determine the minimum number of character deletions required to make a and b anagrams."
date = 2019-03-13T06:58:22-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 0
source = "HackerRank"
source_link = "https://www.hackerrank.com/"
link = "https://www.hackerrank.com/challenges/making-anagrams/problem"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given two strings, a and b, that may or may not be of the same length, determine the minimum number of character deletions required to make a and b anagrams.

Any characters can be deleted from either of the strings.

<h2 class="title is-4"> Questions to ask </h2>

Characters in the string are only lowercase? Yes

Can special characters exist in the string? No

<h2 class="title is-5"> Solution </h2>

The solution is pretty straightforward. Knowing that the a character is a number from 0 to 255, make an array to count the frequency of characters from the first string. Now you will loop trough the second array and remove the character from the array that count the frequency. Loop through the frequency array and sum the absolute value of each index to a result variable.

{{< highlight cpp >}}
int getMinimumDeletionsToAnagram(string s1, string s2){
  vector<int> count(256,0);
  int result =0;
  for(auto c:s1){
    count[c-'a']++;
  }

  for(auto c:s2){
    count[c-'a']--;
  }

  for(auto val : count){
    result+=abs(val);
  }

  return result;
}
{{< /highlight >}}

Time Complexity: **O(n)**

Space Complexity: **O(1)**
