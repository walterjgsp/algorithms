+++
title = "Longest Absolute File Path"
description = "Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0."
date = 2019-03-14T09:29:55-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/longest-absolute-file-path/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Suppose we abstract our file system by a string in the following manner:

The string **"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"** represents:

{{< highlight cpp >}}
dir
    subdir1
    subdir2
        file.ext
{{< /highlight >}}

The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string **"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"** represents:

{{< highlight cpp >}}
dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
{{< /highlight >}}

The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext
and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level
sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to
a file within our file system. For example, in the second example above, the longest
absolute path is *"dir/subdir2/subsubdir2/file2.ext"*, and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the
length of the longest absolute path to file in the abstracted file system.
If there is no file in the system, return 0.

Note:

    The name of a file contains at least a . and an extension.
    The name of a directory or sub-directory will not contain a ..

Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.

<h2 class="title is-5"> Solution </h2>

Let's break the problem in smaller subproblems that are simple to solve, in the end we going to have the full solution.

The first problem is how to split the string in a way that we can determine who is parent of who? Observing the problem statement
we can split in the '\n' character and determine who is parent of who based on the number of '\t'. Writing a function in
C++ to do this and return an array, we have:

{{< highlight cpp >}}
vector<string> splitInput(string input){
  stringstream ss(input);
  vector<string> arr;
  string temp;

  while(getline(ss,temp,'\n')){
      arr.push_back(temp);
  }
  return arr;
}
{{< /highlight >}}

When getline is used the input string is splitted and in the same time the divider ('\n') is removed from the string.

Now, we a way to get the depth of each string in the array we retrieve. One way to do this is looking for the '\t'.
We create now another function that remove the depth from an input string and at the same time return how much was removed.
To solve this problem we are going to make a DFS on the paths. So, if the depth of our stack is bigger then the depth of the folder or file
we are processing, we remove elements until the depth are the same.

{{< highlight cpp >}}
int removeDepth(string &in){
    int depth = 0,index=0;
    while(index<in.size() && in[index]=='\t'){
        index++;
        depth++;
    }

    in = in.substr(index,in.size());

    return depth;
}
{{< /highlight >}}

One of the important parts of the problem is that we can consider only file paths. This means that if we don't have a file, the
path can be longest but will not count. To make the code more modular we make a function to check if a string represents a file:

{{< highlight cpp >}}
bool isFile(const string &file){
    size_t found=file.find('.');
    return found!=string::npos;
}
{{< /highlight >}}


Now, the only information missing is the size of the path:

{{< highlight cpp >}}
int filePathSize(const vector<string> &path){
    int pathSize = path[0].size();
    for(int i=1;i<path.size();i++){
        pathSize+=path[i].size()+1;
    }
    return pathSize;
}
{{< /highlight >}}

Bringing everything together:

{{< highlight cpp >}}
int lengthLongestPath(string input) {
    vector<string> arr = splitInput(input),helper;
    int longest = 0,depth = 0;

    for(auto s:arr){
        depth = removeDepth(s);
        while(depth<helper.size())
            helper.pop_back();
        helper.push_back(s);

        if(isFile(helper.back())){
            longest = max(longest,filePathSize(helper));
        }
    }

    return longest;
}
{{< /highlight >}}
