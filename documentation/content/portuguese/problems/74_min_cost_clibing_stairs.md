+++
title = "Min Cost Climbing Stairs"
description = "Você precisa encontrar um custo mínimo para chegar ao topo de uma escada e começar do degrau com o índice 0 ou com o índice 1."
date = 2019-03-13T21:30:24-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 0
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/min-cost-climbing-stairs/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Em uma escada, o i-ésimo degrau tem algum custo de valor não negativo [i] atribuído (0 indexado).

Depois de pagar o custo, você pode subir um ou dois degraus. Você precisa encontrar o mínimo
custo para chegar ao topo do andar, e você pode começar a partir do degrau com o índice 0 ou com o índice 1.

<h2 class="title is-5"> Solução </h2>

Para resolver este problema, vamos usar a programação dinâmica. Para cada índice no array os valores mais importantes são i-2 e i-1
porque eles representam o custo imediato que eu preciso pagar para que eu possa chegar ao meu índice real. Desde que eu quero minimizar o custo,
eu escolherei o valor mínimo entre o meu custo real e um dos custos anteriores que tornam possível chegar à minha posição atual.
Manter um controle desses valores com um vetor possibilita encontrar uma resposta.

{{< highlight cpp >}}
int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    vector<int> dp(cost.size(),0);
    dp[0]=cost[0],dp[1]=cost[1];

    for(int i=2;i<dp.size();i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }

    return dp.back();
}
{{< /highlight >}}

Complexidade de tempo: **O(n)**

Complexidade de espaço: **O(n)**
