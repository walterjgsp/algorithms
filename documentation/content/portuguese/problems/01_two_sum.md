+++
title = "Two Sum"
description = "Dado um vetor de números inteiros, retorne os índices dos dois números de forma que eles se somem a um alvo específico."
date = 2019-02-16T19:37:40-02:00
weight = 20
draft = false
languages = ["C++","Kotlin"]
toc = true
level = 0
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/two-sum/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Dado um vetor de números inteiros, retorne os índices dos dois números de forma que eles se somem a um alvo específico.

Você pode assumir que cada entrada teria exatamente uma solução, e você não pode usar o mesmo elemento duas vezes.

<h2 class="title is-4"> Questões para fazer </h2>

O vetor já esta ordenado? Não

O array de entrada é mutável ou somente leitura? Mutável

<h2 class="title is-4"> Solução </h2>

Existem três abordagens principais para resolver este problema: **Naive**, **Time Optimized**, **Memory Optimized**.

**Naive**

A abordagem ingênua consiste em escolher a primeira posição da matriz e combinar com os subsequentes até encontrarmos o valor alvo.
Se não encontrarmos, escolhemos a segunda posição e repetimos o processo. Repetimos esse processo até encontrarmos o valor alvo ou todos os pares de posições já estão testados.

Por que devemos evitar essa abordagem ingênua? A complexidade de tempo para esta solução é **O(n²)**.

**Time Optimized**

E se pudéssemos manter na memória todos os valores que já encontramos, de modo que seja possível consultar um determinado valor de destino, isso nos ajudaria a resolver o problema?

A solução otimizada de tempo é baseada em uma estrutura de dados básica, Map (HashMap).
Com essa estrutura, podemos manter um controle de todos os valores anteriores e também consultar se um valor já foi visto em O(1). Como isso ajuda?

Vamos dizer que temos esse tipo de entrada:

**Array =  [2, 11, 7, 15]**

**Target = 9**

Se olharmos para o número 2 no primeiro índice, conhecendo o valor alvo, qual é o valor que precisamos encontrar no array para que a soma dos dois seja adicionada ao alvo 9?
Com matemática básica, achamos que é 7. O número 7 existe na matriz, então eu encontrei a minha resposta? Ainda não. É impossível prever o futuro, mas podemos acompanhar o passado,
É por isso que usamos um **map**.

Nesta abordagem, percorremos o array, procurando por | target - number |, se acharmos voilà! Caso contrário, adicionamos o valor ao valor atual em nosso mapa e prosseguimos

{{< highlight cpp >}}
vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int,int> index_val;
  index_val[nums[0]]=0;
  vector<int> result;
  for(int i=1;i<nums.size();i++){
    if(index_val.find(target-nums[i])!=index_val.end()){
      result.push_back(index_val[target-nums[i]]);
      result.push_back(i);
      break;
    }
    index_val[nums[i]]=i;
  }

  return result;
}
{{< /highlight >}}

Com essa abordagem, temos a seguinte complexidade:

Complexidade do Tempo: **O(n)**

Complexidade do espaço: **O(n)**

onde n é o número de elementos no vetor.

**Memory Optimized**

Vamos supor que não temos memória para gastar ao tentar resolver este problema, e apenas queremos saber se existem dois valores na matriz, como o endereçamos agora?
Se pudermos, ordenamos o array.

Com o array ordenado, mantemos dois ponteiros, um apontando para a primeira posição do array e o outro apontando para o último. Nós obtemos os dois valores de cada ponteiro
e compare o resultado da soma ao alvo. Se o resultado for maior que o nosso alvo, precisamos mover o maior ponteiro para baixo, então nossa soma é menor. De outra forma,
se precisarmos aumentar o resultado, incrementamos o ponteiro com o valor menor (aquele que aponta para a primeira posição).

Com essa abordagem, temos a seguinte complexidade:

Complexidade do Tempo: **O(nlogn)**

Complexidade do espaço: **O(1)**

onde n é o número de elementos no vetor.
