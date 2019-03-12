+++
title = "Advantage Shuffle"
description = "Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i]."
date = 2019-03-11T21:14:47-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/advantage-shuffle/"
+++
<h2 class="title is-4"> Problem Statement </h2>

Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

<h2 class="title is-4"> Questions to ask </h2>

Is the input array already sorted? Not sorted

Is the input array mutable or read only? Mutable

Can i have negative numbers in my input array? Only positive numbers

<h2 class="title is-5"> Solution </h2>

This problem is solved in a greedy way and can be proved with the technique "Greedy stays ahead".

Create an array **result** with size the same of A and B. Make an array of pairs using array B where each pair is (B[i],i) being i the index of B.
Sort both arrays (**A** and **PairB**). Now is possible to find the number of elements in A that are bigger then the elements in B and
where they need to be. To finish the solution place the missing elements of A in any place of the result array.

{{< highlight cpp >}}
vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    vector<pair<int,int>> helperB;
    vector<int> result (A.size(),-1);
    int tam = A.size();

    for(int i=0;i<tam;i++){
        helperB.push_back(make_pair(B[i],i));
    }

    sort(A.begin(),A.end());
    sort(helperB.begin(),helperB.end());

    int indexA = 0,indexB = 0;

    while(indexA<tam){
        auto pairB = helperB[indexB];
        if(A[indexA]>pairB.first){
            result[pairB.second]=A[indexA];
            A[indexA]=-1;
            indexB++;
        }
        indexA++;
    }

    indexA = 0;
    int i = 0;

    while(indexA<tam && i<tam){
        if(A[indexA]==-1){
            indexA++;
        }else if(result[i]!=-1){
            i++;
        }else{
            result[i]=A[indexA];
            i++;
            indexA++;
        }
    }

    return result;
}
{{< /highlight >}}

In one pass you pick the bigger values of A and place in the right position in the result array.
The time complexity will be the cost to sort both arrays is **O(Nlogn)**
