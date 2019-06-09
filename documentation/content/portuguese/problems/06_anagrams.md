+++
title = "Anagrams"
description = "Dadas duas strings, a e b, que podem ou não ter o mesmo comprimento, determine o número mínimo de exclusões de caracteres necessárias para tornar a e b anagramas."
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
<h2 class="title is-4"> Enunciado do problema </h2>

Dadas duas strings, a e b, que podem ou não ter o mesmo comprimento, determine o número mínimo de exclusões de caracteres necessárias para tornar a e b anagramas.

Qualquer caractere pode ser excluído de qualquer uma das strings.

<h2 class="title is-4"> Questões para fazer </h2>

Caracteres na string são apenas minúsculos? Sim

Podem existir caracteres especiais na string? Não

<h2 class="title is-5"> Solução </h2>

A solução é bem direta. Sabendo que o caractere é um número de 0 a 255, crie um vetor para contar a frequência dos caracteres da primeira string. Agora você passará pelo segundo array e removerá o caractere do vetor que conta a freqüência. Faça um loop pelo vetor de frequência e some o valor absoluto de cada índice a uma variável de resultado.

Como os caracteres são apenas minúsculos, um vetor de 26 posições poderia ser utilizado ao invés de um de 255 fazendo a subtração do valor ASCII 'a' de cada caractere.

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

Complexidade do Tempo: **O(n)**

Complexidade do espaço: **O(1)**
