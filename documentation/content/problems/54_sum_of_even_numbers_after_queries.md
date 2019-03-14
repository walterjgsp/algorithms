+++
title = "Sum of Even Numbers After Queries"
description = "Given an array A of integers, and an array queries of queries return the answer to all queries."
date = 2019-03-13T09:02:23-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 0
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/sum-of-even-numbers-after-queries/"
+++
<h2 class="title is-4"> Problem Statement </h2>

We have an array A of integers, and an array queries of queries.

For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index]. Then, the answer to the i-th query is the sum of the even values of A.

(Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)

Return the answer to all queries. Your answer array should have answer[i] as the answer to the i-th query.

<h2 class="title is-4"> Questions to ask </h2>

Is the input array mutable or read only? Mutable

Can i have negative numbers in my input array? Yes

<h2 class="title is-5"> Solution </h2>

To solve this problem we gonna keep an auxiliary variable to keep a track of the sum of all even values in the array. So, we loop through adding
the value to this variable if it is even. Now we need to apply the changes proposed by the queries and also track the new sum. To do this we use simple math.
If the query index has a even value we subtract this value from the variable with the total sum of even values, we appply the change and if the new value
is even we add to the variable and also in the result array. 

{{< highlight cpp >}}
vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    vector<int> result;
    int actual_sum = 0;

    for(auto value:A){
        if(value%2==0)
            actual_sum+=value;
    }

    for(auto query : queries){
        int position = query[1], to_sum = query[0];

        if(A[position]%2==0)
            actual_sum-=A[position];

        A[position]+=to_sum;

        if(A[position]%2==0)
            actual_sum+=A[position];

        result.push_back(actual_sum);
    }

    return result;
}
{{< /highlight >}}


Time Complexity: **O(n+m)** where n is the size of the initial array and m the number of queries.
