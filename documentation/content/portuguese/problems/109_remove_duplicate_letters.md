+++
title = "Remove Duplicate Letters"
description = "Dada uma string que contém apenas letras minúsculas, remova as letras duplicadas para que cada letra apareça uma vez e somente uma vez."
date = 2019-06-09T22:19:37-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 2
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/remove-duplicate-letters/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Dada uma string que contém apenas letras minúsculas, remova as letras duplicadas para que cada letra apareça uma vez e somente uma vez. Você deve certificar-se de que seu resultado é o menor em ordem lexicográfica entre todos os resultados possíveis e que a posição das letras é mantido.

<h2 class="title is-5"> Solução </h2>

Para resolver esse problema, primeiramente vamos contar a frequência de cada caractere no texto de entrada.
Isso irá nos auxiliar na tomada de decisão quando estivermos montando a nova palavra com apenas os caracteres distinto na ordem lexicográfica.

Após a contagem vamos definir de maneira gulosa se colocamos a letra na nossa string resultado ou não. Para isso vamos ter também um vetor onde iremos identificar se uma letra foi usada ou não na formação da nossa string de resultados. 

Cada vez que um novo caractere for processado primeiro vamos reduzir 1 ao vetor que guarda a frequência de caracteres, pois acabamos de processar um e não temos ele mais como disponível. Se esse caractere já tiver sido utilizado na formação da palavra final, apenas continuamos para a próxima iteração. Em caso negativo nós temos que verificar três condições:

<div class="margin_left">
  <ol>
    <li>A palavra resultado esta vazia</li>
    <li>A letra que estou tentando adicionar é menor do que a última letra da string resultado</li>
    <li>Ainda existe o último caractere da palavra resultado para ser utilizado futuramente</li>
  </ol>
</div>
</br>

Enquanto todas essas condições forem positivas nós vamos remover a última letra do resultado e marcar ela como não utilizada no nosso vetor de utilizados. Quando o loop terminar nós adicionamos a letra que estamos processando no final da palavra resultado e marcamos ela como utilizada.

{{< highlight cpp >}}
string removeDuplicateLetters(string text){
    string result;
    if(text.empty())
        return result;

    vector<int> count(26,0);
    for(auto c: text){
        count[c-'a']++;
    }

    vector<bool> used(26,false);
    for(auto c: text){
        count[c-'a']--;
        if(used[c-'a'])
            continue;
        
        while(!result.empty() && c<result.back() && count[result.back()]>0){
            used[result.back()-'a']=false;
            result.pop_back();
        }

        result+=c;
        used[c-'a'] = true;
    }

    return result;
}
{{< /highlight >}}

Complexidade de tempo: **O(n)**

Complexidade de espaço: **O(n)**