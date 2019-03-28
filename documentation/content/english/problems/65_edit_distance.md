+++
title = "Edit Distance"
description = "Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2."
date = 2019-03-02T15:26:52-03:00
weight = 20
draft = false
languages = ["C++"]
toc = true
level = 2
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/edit-distance/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given two words **word1** and **word2**, find the minimum number of operations required to convert **word1** to **word2**.

You have the following 3 operations permitted on a word:

<div class="margin_left">
  <ol>
    <li>Insert a character</li>
    <li>Delete a character</li>
    <li>Replace a character</li>
  </ol>
</div>

<br/>
<h2 class="title is-5"> Solution </h2>

If **word1** = "horse" and **word2** = "ros", how can we solve the problem? In a first look the problem seens much more complex
than it is. In an attempt to make simple, let's break it in smaller problems a go back to these words latter.

How many operations do we need to convert an empty string " " into "ab"? The answer is easy, using the insert operation in two moves
we can insert character "a" and "b" into the empty string. And the opposite? Also easy, we can delete the characters in two operations.
And what about having two strings with only one character that area equal ("a" and "a")? No movements needed there. And two different
characters ("a" and "b")? Also one operation, replace a character. Now we know how to treat the basic cases, 10% of the problem is solved.

We now know the operations we can execute on **word1**, but, how we represent then? Treating a string as an array of characters and using
one index in each word (**index1** for **word1** and **index2** for **word2**).

**Insert**

From the first index (**index1 = 0** and **index2 = 0**) in both words keep the index of the first word and add 1 in **index2**. This means that
i don't have more problem with the first position on **word2** is already solved, i inserted the right character, so let's go to the other
character but keeping the same index on **word1** since i'm still processing it.

**Replace**

Both indexes increment since we have made the replacement operation and made both values equal, so i go to the next position.

**Delete**

Deletion is the opposite of insertion. When in insertion we keep the **index1** in deletion we ignore this index, meaning remove the character,
and keep the **index2** the same because we still need to find a match.

I imagine that this complete know 30% of our problem. We already know the basic cases and how to implement each operation on a atomic
base.

I found easier to implement starting from the end, this way, when an index is smaller than 0 means that my word ended and i need to return
only the value of the other index plus 1. But the logic is the same regards the way you decide to go: from one index get the minimum of
all three operations being applied if the character value for the arrays are different.

With this in mind we can come up with the simple algorithm for treating individual characters of a string:

{{< highlight cpp >}}
minDistance(string word1, int index1, string word2, int index2){

  if(index1<0)
    return index2+1;

  if(index2<0)
    return index1+1;

  if(word1[index1]==word2[index2])
    distance = minDistance(word1,index-1,word2,index2-1);
  else
    distance = 1+min(minDistance(word1,index-1,word2,index2-1),
        minDistance(word1,index1,word2,index2-1),
        minDistance(word1,index-1,word2,index2));

  return distance;
}
{{< /highlight >}}

With this code you solve the problem, but the complexity of this implementation is exponential O(2<sup>n</sup>).
That is not a good solution. How can we make our code better?

If we observe the solution, we process some pair of indexes more than one time and we can solve the problem by solving smaller parts
of the problem (**overlapping sub-problems**). Other condition is that an optimal solution can be constructed from optimal solutions
of the subproblems (**optimal substructure**). This two are necessary conditions to apply dynamic programming. Doing with memoization, keeping a
track of all the solved subproblems using the index as a key of a map, we have the following code.


{{< highlight cpp >}}

unordered_map<pair<int,int>,int> memo;

minDistance(string word1, int index1, string word2, int index2){
  pair<int,int> key = make_pair(index1,index2);

  if(memo.find(key)!=memo.end())
    return memo[key];

  if(index1<0)
    return memo[key]=index2+1;

  if(index2<0)
    return memo[key]=index1+1;

  if(word1[index1]==word2[index2])
    distance = minDistance(word1,index-1,word2,index2-1);
  else
    distance = 1+min(minDistance(word1,index-1,word2,index2-1),
        minDistance(word1,index1,word2,index2-1),
        minDistance(word1,index-1,word2,index2));

  return memo[key]=distance;
}
{{< /highlight >}}


Time complexity : **O(mn)**
Space complexity : **O(mn)**

Where m is the size of word1 and n the size of word2
