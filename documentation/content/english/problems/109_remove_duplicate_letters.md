+++
title = "Remove Duplicate Letters"
description = "Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once."
date = 2019-06-09T22:19:02-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 2
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/remove-duplicate-letters/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

<h2 class="title is-5"> Solution </h2>

To solve this problem, let's first count the frequency of each character in the input text. This will aid us in decision making 
when we are assembling the new word with only the distinct characters in the lexicographic order.

After the count we will define in a greedy way if we put the letter in our string result or not. For this we will also have a vector where we will identify whether a letter was used or not in the formation of our results string.

Each time a new character is processed first let's reduce 1 to the vector that stores the character frequency, since we just processed  and do not have it as available anymore. If this character has already been used in the final word formation, we only continue to the next iteration. If not, we have to check three conditions:

<div class="margin_left">
  <ol>
    <li>Result string is not empty</li>
    <li>The letter I'm trying to add is smaller than the last letter of the string result</li>
    <li>There is still the last character of the word result to be used in the future</li>
  </ol>
</div>
</br>

While all these conditions are positive we will remove the last letter of the result and mark it as unused in our used vector. When the loop finishes we add the letter that we are processing at the end of the word result and mark it as used.

{{< highlight cpp >}}
string removeDuplicateLetters(string text){
    string result;
    if(text.empty())
        return result;

    vector<int> count(26,0);
    for(auto c: text){
        count[c-'a']++;
    }

    vector<bool> used(26,false);
    for(auto c: text){
        count[c-'a']--;
        if(used[c-'a'])
            continue;
        
        while(!result.empty() && c<result.back() && count[result.back()]>0){
            used[result.back()-'a']=false;
            result.pop_back();
        }

        result+=c;
        used[c-'a'] = true;
    }

    return result;
}
{{< /highlight >}}

Time complexity: **O(n)**

Space complexity: **O(n)**