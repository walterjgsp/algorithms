+++
title = "Word Break"
description = "Dada uma string não vazia e um dicionário wordDict contendo uma lista de palavras não vazias, determine se s pode ser segmentado em uma seqüência separada por espaço de uma ou mais palavras do dicionário."
date = 2019-03-18T21:21:57-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/word-break/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Dada uma string não vazia e um dicionário wordDict contendo uma lista de palavras não vazias, determine se **s** pode ser segmentado em uma seqüência separada por espaço de uma ou mais palavras do dicionário.

Nota:

A mesma palavra no dicionário pode ser reutilizada várias vezes na segmentação.

Você pode assumir que o dicionário não contém palavras duplicadas.

<h2 class="title is-5"> Solução </h2>

Começando do final ao começo, nós quebramos a palavra em duas partes. Primeiro verifique se a parte mais à direita está no dicionário, se esta então verifique se a parte esquerda é uma sequência
de uma ou mais palavras do dicionário. Se as duas verificações forem verdadeiras, retorne true.

O truque desse problema é como resolver isso de maneira otimizada. É possível usar a recursão com memorização, pois o problema apresenta **subproblemas sobrepostos** e **subestrutura ótima**.
Usando um hash, podemos reduzir a complexidade evitando que os mesmos dados sejam processados ​​mais de uma vez.

{{< highlight cpp >}}
bool helperWordBreak(unordered_map<string,bool> &memo,const unordered_set<string> &dict, string word){
  if(memo.find(word)!=memo.end())
          return memo[word];

  if(dict.find(word)!=dict.end())
          return memo[word]=true;

  for(int i=word.size()-1; i>0; i--) {

          string right = word.substr(i);
          if(dict.find(right)==dict.end())
                  continue;

          string left = word.substr(0,i);
          if(helperWordBreak(memo,dict,left)) {
                  return memo[word]=true;
          }
  }

  return memo[word]=false;
}

bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<string> dict (wordDict.begin(),wordDict.end());
  unordered_map<string,bool> memo;

  return helperWordBreak(memo,dict,s);
}
{{< /highlight >}}
