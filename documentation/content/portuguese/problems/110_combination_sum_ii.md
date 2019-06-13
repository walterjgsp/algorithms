+++
title = "Combination Sum II"
description = ""
date = 2019-06-12T21:59:28-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/combination-sum-ii/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Dada uma coleção de números de candidatos (candidatos) e um número de destino (meta), localize todas as combinações exclusivas em candidatos em que os números dos candidatos somam a meta.

Cada número em candidatos só pode ser usado uma vez na combinação.

***Nota:***

Todos os números (incluindo o alvo) serão inteiros positivos.
O conjunto de soluções não deve conter combinações duplicadas.

<h2 class="title is-4"> Questões importantes </h2>

O vetor de entrada já esta ordenado? Não

O vetor de entrada pode ser modificado? Sim

<h2 class="title is-5"> Solução </h2>

Esse problema é resolvido através de um método força bruta de maneira recursiva e inteligente (backtracking). Basta fazer um algoritmo que tem como o objetivo testar todas as possibilidades e aproveitando das restrições do problema realizar podas para não processar situações que não fazem sentido.

Antes de começar o processamento recursivo, é necessário ordenar o vetor de entrada, dessa forma se torna fácil garantir que soluções duplicadas não irão ocorrer.

O algoritmo de recursão irá receber como parâmetros: o vetor de candidatos, a meta, o vetor atual que é um subconjunto do vetor de candidatos, a soma de todos os valores do vetor atual, a posição que esta sendo processada atualmente no vetor de candidatos. Na recursão existem ter três situações:

<div class="margin_left">
  <ol>
    <li>O valor da soma atual é menor do que a menta</li>
    <li>O valor da soma atual é igual a meta</li>
    <li>O valor da soma atual é aior do que a menta</li>
  </ol>
</div>
</br>

No terceiro caso basta retornar, a restrição de todos os números serem positivos garante que qualquer processamento a mais irá apenas aumentar o valor atual. No segundo caso o resultado foi encontrado para aquela combinação do vetor atual, salvar ele na matriz de resultados e retornar devido a mesma restrição de valores apenas positivos. No primeiro caso deve-se executar o processamento.

O processamento consiste em para cada posição do vetor de candidatos iniciando da posição recebida como parâmetro + 1, colocar esse elemento no vetor representando o subconjunto dos candidatos, adicionar o valor a variável que representa todos os valores do subconjunto atual, executar a chamada recursiva e ao final remover esse elemento do subconjunto. Fazer isso até que todos os elementos tenham sido processados. 

A implementação desse código fica sendo:

{{< highlight cpp >}}
class Solution{
private:
    vector<vector<int>> result;

    void helper(const vector<int> &nums, const int &target, vector<int> &curr, int &currSum, int pos){
        if(currSum>target){
            return;
        }

        if(currSum == target){
            result.push_back(curr);
            return;
        }

        for(int i=pos+1;i<nums.size();i++){
            curr.push_back(nums[i]);
            currSum+=nums[i];
            helper(nums,target,curr,currSum,i);
            curr.pop_back();
            currSum-=nums[i];

            while(i+1<nums.size() && nums[i]==nums[i+1])
                i++;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        result.clear();
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        int currSum = 0;
        helper(candidates,target,curr,currSum,-1);
        return result;
    }
};
{{< /highlight >}}

Complexidade de tempo: **O(N!)**
