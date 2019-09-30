+++
title = "Letter Combinations of a Phone Number"
description = "Dada uma sequência contendo dígitos de 2 a 9, inclusive, retorne todas as combinações possíveis de letras que o número possa representar."
date = 2019-09-30T06:59:48-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com"
link = "https://leetcode.com/problems/letter-combinations-of-a-phone-number"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Dada uma sequência contendo dígitos de 2 a 9, inclusive, retorne todas as combinações possíveis de letras que o número possa representar.

O mapeamento do dígito para as letras é {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}. Observe que 1 não é mapeado para nenhuma letra.

<h2 class="title is-5"> Solução </h2>

Para resolver esse problema, usamos uma abordagem recursiva. Primeiro, definimos um caso base, que fará com que nossas chamadas recursivas parem. Neste problema será
quando chegarmos ao final da string de entrada. Para todas as outras chamadas no algoritmo, obteremos as respectivas letras do dígito atual
que esta sendo processado, adicionamos ao final de uma possível combinação e chamamos de maneira recursiva a mesma função até que a recursão pare.

O código para esta solução:

{{< highlight cpp >}}

unordered_map<int,string> letters = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
vector<string> result;

void recursiveCombination(const string &digits,int index, string curr){
    if(index>=digits.size()){
        result.push_back(curr);
    }
    
    for(auto letter : letters[digits[index]-'0']){
        curr.push_back(letter);
        recursiveCombination(digits,index+1,curr);
        curr.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    result.clear();
    if(digits.empty()){
        return result;
    }
    string curr;
    recursiveCombination(digits,0,curr);
    return result;
}
{{< /highlight >}}

Complexidade de tempo: **O(3ˆn)**