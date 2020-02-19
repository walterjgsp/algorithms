+++
title = "Trie"
description = "A trie is a tree-like data structure whose nodes store the letters of an alphabet."
date = 2019-07-11T19:04:54-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
+++
<h2 class="title is-4"> Definition </h2>

A trie is a tree-like data structure whose nodes store the letters of an alphabet. 

By structuring the nodes in a particular way, words and strings can be retrieved from the structure by traversing down a branch path of the tree. 

With this structure, it's really easy and fast to get all the dictionary words with a correlated prefix.

<div class="container has-text-centered">
<h3 class="title is-5 margin_top"> Complexity </h3>

<table class="table is-striped is-bordered center" >
    <thead>
        <tr>
            <th>Operation</th>
            <th>Average</th> 
            <th>Worst Case</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Space</td>
            <td>O(n)</td> 
            <td>O(n)</td>
        </tr>
        <tr>
            <td>Search</td>
            <td>O(logn)</td> 
            <td>O(logn)</td>
        </tr>
        <tr>
            <td>Add</td>
            <td>O(logn)</td> 
            <td>O(logn)</td>
        </tr>
        <tr>
            <td>Sort</td>
            <td>O(nlogn)</td> 
            <td>O(nlogn)</td>
        </tr>
    </tbody>
</table>
</div>

<h2 class="title is-4 margin_top"> Implementation </h2>

The trie it's implemented with the following basic structure for each node 

{{< highlight cpp >}}
class TNode{
public:
    vector<TNode*> children;
    bool endWord;
    TNode(){
        children = vector<TNode*> (26,nullptr);
        endWord = false;
    }
};
{{< /highlight >}}

using a 26 letters alphabet.

When adding and searching any value in the trie what we do is to recursively traverse the structure and check if the current node child exists or not. 
In case we want to add value if the node does not exist we create and go until the end. After the end is reached we change the endWord variable to true.

Searching in a trie it's very similar to adding. The only difference is that if for some reason the child node being searched does not exist, return false. When all the nodes exist, return the value of the endWord variable.

To print all the words of a dictionary sorted, traversing the trie in order will solve the problem.