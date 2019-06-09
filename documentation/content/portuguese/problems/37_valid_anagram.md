+++
title = "Valid Anagram"
description = "Dadas duas strings s e t, escreva uma função para determinar se t é um anagrama de s."
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

Dadas duas strings s e t, escreva uma função para determinar se t é um anagrama de s.

<h2 class="title is-4"> Questions to ask </h2>

Caracteres na string são apenas minúsculos? Sim

Podem existir caracteres especiais na string? Não

<h2 class="title is-5"> Solution </h2>

A solução é bem direta. Sabendo que o caractere é um número de 0 a 255, crie um vetor para contar a frequência dos caracteres da primeira string. Agora você passará pelo segundo array e removerá o caractere do array que conta a freqüência. Faça um loop pela matriz de frequência e, se algum valor for diferente de 0, retorne false. Caso contrário, retorne verdadeiro quando loop terminar.

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

Complexidade do Tempo: **O(n)**

Complexidade do espaço: **O(1)**
