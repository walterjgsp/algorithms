+++
title = "Sliding Window Maximum"
description = "Dado um array nums, há uma janela deslizante de tamanho k que está se movendo da esquerda da matriz para a direita. Você só pode ver os números k na janela. Cada vez que a janela deslizante se move para a direita por uma posição. Retorne a janela deslizante máxima."
date = 2019-03-28T19:06:02-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 2
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/sliding-window-maximum/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Dado um array nums, há uma janela deslizante de tamanho k que está se movendo da esquerda da matriz para a direita. Você só pode ver os números k na janela. Cada vez que a janela deslizante se move para a direita por uma posição. Retorne a janela deslizante máxima.

<h2 class="title is-4"> Questões importantes </h2>

Posso ter números negativos no meu vetor de entrada? sim

<h2 class="title is-5"> Solução </h2>

A ideia de resolver este problema é sempre manter o maior número encontrado como primeiro em uma janela deslizante. Isso é possível usando uma deque, mantendo um os índices do array. Em cada loop, primeiro verifique se o elemento frontal da janela deslizante é válido, menor que a posição atual menos k. Segundo, verifique se o número atual é maior que o da fila, em caso positivo, remova a parte traseira até que nenhum elemento menor que o atual seja encontrado. Adicione o elemento atual à parte traseira e adicione a frente como resposta para esta posição atual da janela.

{{< highlight cpp >}}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> indexes;
    vector<int> result;

    for(int i=0;i<nums.size();i++){

        if(!indexes.empty() && indexes.front()<=i-k){
            indexes.pop_front();
        }
        while(!indexes.empty() && nums[i]>nums[indexes.back()]){
            indexes.pop_back();
        }
        indexes.push_back(i);

        if(i>=k-1){
            result.push_back(nums[indexes.front()]);
        }
    }

    return result;
}
{{< /highlight >}}

Complexidade de tempo: **O(n)**

Complexidade de espaço: **O(n)**
