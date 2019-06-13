+++
title = "Squares of a Sorted Array"
description = "Dada um vetor de inteiros A ordenada em ordem não decrescente, retorne um vetor dos quadrados de cada número, também em ordem não decrescente ordenado."
date = 2019-03-09T01:26:01-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 0
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/squares-of-a-sorted-array/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Dada um vetor de inteiros A ordenada em ordem não decrescente, retorne um vetor dos quadrados de cada número, também em ordem não decrescente ordenado.

<h2 class="title is-4"> Questões importantes </h2>

Posso ter números negativos no meu vetor de entrada? Sim

O array de entrada é mutável ou somente leitura? Não

<h2 class="title is-5"> Solução </h2>

A solução ingênua é percorrer o array calculando o quadrado de cada valor e adicionando o resultado em um array para retornar. Depois desse loop ordenamos o array resultante e retornamos.

A complexidade temporal deste código é **O(N logn)**, que é o custo para ordenar o array.

Uma solução mais otimizada pode ser obtida se usarmos dois ponteiros e as informações que o vetor já está ordenado.

Mantenha um ponteiro na posição inicial e outro na posição final do array de entrada. Usando a diferença absoluta, descobrimos a maior
valor e nós adicionamos o quadrado deste valor no vetor de resultados. O último passo é mover o ponteiro se o maior valor encontrado foi o inicial, incrementamos esse ponteiro, senão decrementamos o ponteiro da posição final. Nós vamos ter um array de resultado ordenado na ordem inversa, ao inverter o vetor encontramos uma solução.

{{< highlight cpp >}}
vector<int> sortedSquares(vector<int>& A) {
    vector<int> result;
    int start = 0, end = A.size()-1;
    while(start<=end){
        if(abs(A[start])<abs(A[end])){
            result.push_back(A[end]*A[end]);
            end--;
        }else{
            result.push_back(A[start]*A[start]);
            start++;
        }
    }

    reverse(result.begin(),result.end());
    return result;
}
{{< /highlight >}}

A complexidade de tempo desse código é **O(n)**
