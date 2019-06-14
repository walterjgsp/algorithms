+++
title = "Container With Most Water"
description = "Encontre duas linhas, que, juntamente com o eixo x, formam um contêiner, de modo que o contêiner contenha a maior quantidade de água."
date = 2019-03-20T06:40:40-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/container-with-most-water/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Dados n inteiros não negativos a1, a2, ..., an, onde cada um representa um ponto na coordenada (i, ai). n linhas verticais são desenhadas de tal forma que os dois pontos finais da linha i estão em (i, ai) e (i, 0). Encontre duas linhas, que, juntamente com o eixo x, formam um contêiner, de modo que o contêiner contenha a maior quantidade de água.

**Nota:** Você não pode inclinar o recipiente e n é pelo menos 2.

<h2 class="title is-5"> Solução </h2>

A área é dependente da distância entre as duas alturas e a altura mínima entre as duas. É possível
controlar de forma linear a distância entre as alturas, partindo de um ponto onde a maior distância é selecionada
e reduzi-lo ao longo do tempo.

A maior distância possível entre alturas pode ser encontrada usando dois ponteiros, um no início do array e outro no final.
Calcule a área e reduza a distância. Para encolher de forma ideal, selecione o ponteiro que tenha o menor valor e mova-o para o meio.
O loop ocorre enquanto a posição dos ponteiros é diferente.

{{< highlight cpp >}}
int maxArea(vector<int>& height) {
    int start=0,end=height.size()-1,maxArea=0,area;

    while(start<end){
        area = min(height[start],height[end])*(end-start);
        maxArea = max(maxArea,area);

        if(height[start]>height[end]){
            end--;
        }else
            start++;
    }

    return maxArea;
}
{{< /highlight >}}

Complexidade de tempo: **O(n)**

Complexidade de espaço: **O(1)**
