+++
title = "Sum of Even Numbers After Queries"
description = "Dado um vetor A de inteiros, e um vetor de consultas de queries, retornar a a soma dos valores pares de A após todas as consultas."
date = 2019-03-13T09:02:23-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 0
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/sum-of-even-numbers-after-queries/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Temos um vetor A de inteiros e um vetor de consultas de queries.

Para a i-ésima consulta  val = queries[i][0], index = queries[i][1], adicionamos val a A[index]. Então, a resposta para a i-ésima consulta é a soma dos valores pares de A.

(Aqui, o índice dado = queries[i][1] é um índice baseado em 0, e cada consulta modifica permanentemente o array A.)

Retorna a resposta para todas as perguntas. Seu vetor de respostas deve ter a resposta[i] como a resposta para a i-ésima consulta.

<h2 class="title is-4"> Questões importantes </h2>

Is the input array mutable or read only? Mutable

Can i have negative numbers in my input array? Yes

<h2 class="title is-5"> Solução </h2>

Para resolver este problema, vamos manter uma variável auxiliar para manter uma faixa da soma de todos os valores pares no vetor. Então, nós passamos por todo o vetor e adicionamos
o valor para essa variável se for par. Agora precisamos aplicar as alterações propostas pelas consultas e também acompanhar a nova soma. Para fazer isso, usamos matemática simples.
Se o índice de consulta tiver um valor par, subtraímos esse valor da variável com a soma total dos valores pares, aplicamos a alteração e se o novo valor for par nós adicionamos à variável e também ao vetor de resultados. 

{{< highlight cpp >}}
vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    vector<int> result;
    int actual_sum = 0;

    for(auto value:A){
        if(value%2==0)
            actual_sum+=value;
    }

    for(auto query : queries){
        int position = query[1], to_sum = query[0];

        if(A[position]%2==0)
            actual_sum-=A[position];

        A[position]+=to_sum;

        if(A[position]%2==0)
            actual_sum+=A[position];

        result.push_back(actual_sum);
    }

    return result;
}
{{< /highlight >}}


Complexidade de tempo: **O(n+m)** onde n é o tamanho da matriz inicial e m o número de consultas.
