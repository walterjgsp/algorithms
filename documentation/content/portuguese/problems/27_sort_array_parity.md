+++
title = "Sort Array By Parity"
description = "Dado um array A de inteiros não negativos, retorne um array que consiste em todos os elementos pares de A, seguidos por todos os elementos ímpares de A."
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
<h2 class="title is-4"> Enunciado do problema </h2>

Dado um array A de inteiros não negativos, retorne um array que consiste em todos os elementos pares de A, seguidos por todos os elementos ímpares de A.

Você pode retornar qualquer array de resposta que satisfaça essa condição.

<h2 class="title is-4"> Questões importantes </h2>

O array de entrada é mutável ou somente leitura? Mutável

Posso ter números negativos no meu vetor de entrada? sim

<h2 class="title is-5"> Solução </h2>

Existem duas soluções para esse problema com complexidade de tempo **O(n)** com apenas uma passada no vetor.

**Dois arrays**

Use dois arrays auxiliares, um para números ímpares e outro para números pares, ao fazer um loop coloque cada valor no seu devido array.
Depois que todos os valores forem processados, você mesclará os dois arrays em um e retornará.

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

Use um ponteiro no início do vetor e outro ponteiro no final, faça um loop até que *start* seja menor que o ponteiro *end*. Se o valor
na posição inicial é ímpar e na posição final é par, troque esses dois valores e mova os ponteiros para o meio. Caso contrário, basta verificar as condições de cada
os ponteiros para mover cada um.

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

Time complexity: **O(n)**
