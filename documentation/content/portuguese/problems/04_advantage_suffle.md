+++
title = "Advantage Shuffle"
description = "Dados dois vetores A e B de tamanho igual, a vantagem de A em relação a B é o número de índices i para os quais A[i]>B[i]."
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
<h2 class="title is-4"> Enunciado do problema </h2>

Dados dois vetores A e B de tamanho igual, a vantagem de A em relação a B é o número de índices i para os quais A[i]>B[i].

Retorne qualquer permutação de A que maximize sua vantagem em relação a B.

<h2 class="title is-4"> Questões para fazer </h2>

O vetor de entrada está ordenado? Não ordenado

O array de entrada é mutável ou somente leitura? Mutável

Posso ter números negativos no meu vetor de entrada? Apenas números positivos

<h2 class="title is-5"> Solução </h2>

Este problema é resolvido de forma gulosa e pode ser provado com a técnica "Greedy fica à frente".

Crie um array **result** com tamanho igual a A e B. Faça um array de pares usando o array B onde cada par é (B[i],i) sendo i o índice de B.
Ordene os dois arrays (**A** e **PairB**). Agora é possível encontrar o número de elementos em A que são maiores que os elementos em B e
onde eles precisam estar. Para finalizar a solução, coloque os elementos ausentes de A em qualquer lugar do vetor de resultados.

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

Em uma passada, você escolhe os valores maiores de A e coloca na posição correta no vetor resultante.
A complexidade do tempo será o custo para ordenar ambos os arrays que é **O(nlogn)**
