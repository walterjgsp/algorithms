+++
title = "Trapping Rain Water"
description = "Dados n inteiros não negativos representando um mapa de elevação onde a largura de cada barra é 1, calcule quanta água será retida após a chuva."
date = 2019-03-31T17:30:00-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 2
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/trapping-rain-water/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Dados n inteiros não negativos representando um mapa de elevação onde a largura de cada barra é 1, calcule quanta água será retida após a chuva.

<h2 class="title is-4"> Questões importantes </h2>

Os limites do vetor também podem reter água? Não

<h2 class="title is-5"> Solução </h2>

Para resolver este problema, calcule dois arrays auxiliares contendo os valores máximos à direita e à esquerda de uma i-ésima posição. A altura menos o valor mínimo centered
os dois vetores vai mostrar quanta água pode ficar presa em todas as posições do vetor. Se o valor for negativo significa que nenhuma água pode ser retida e não acrescenta à
resultado.

{{< highlight cpp >}}
int trap(vector<int>& height) {
    if(height.empty())
        return 0;

    vector<int> right_max(height.size(),0),left_max(height.size(),0);

    left_max[0]=height[0];
    for(int i=1;i<height.size();i++){
        left_max[i]=max(height[i],left_max[i-1]);
    }

    right_max[height.size()-1] = height.back();
    for(int j=height.size()-2;j>=0;j--){
        right_max[j]=max(height[j],right_max[j+1]);
    }

    int result = 0;
    for(int i=1;i<height.size()-1;i++){
        int water = min(left_max[i],right_max[i])-height[i];
        result+=max(water,0);
    }

    return result;
}
{{< /highlight >}}

Complexidade de tempo: **O(n)**

Complexidade de espaço: **O(n)**
