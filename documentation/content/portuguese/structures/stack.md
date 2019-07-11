+++
title = "Pilha"
description = "Estrutura de dados linear que obedece a ordem LIFO (Last In First Out) em suas funções"
date = 2019-07-11T04:15:17-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
+++
<h2 class="title is-4"> Definição </h2>

A pilha é uma estrutura de dados para conter objetos obedecendo a ordem de entrada  LIFO (Last In First Out). Isso significa
que o primeiro elemento a ser adicionado sera o último elemento a sair. Em sua forma mais clássica ela implementa
as seguintes operações:

<div class="margin_left">
  <ol>
    <li><b>Top</b> : essa operação retorna o último elemento adicionado a pilha, em alguns casos pode ser também implementada como <b>Peek</b></li>
    <li><b>Push</b>: a operação adiciona um elemento na última posição da pilha</li>
    <li><b>Pop</b> : essa operação remove um elemento da última posição da pilha. Em algumas implementações, a operação remove e retorna o elemento que removeu </li>
  </ol>
</div>

<div class="container has-text-centered">
<h3 class="title is-5 margin_top"> Complexidades </h3>

<table class="table is-striped is-bordered center" >
    <thead>
        <tr>
            <th>Operação</th>
            <th>Caso médio</th> 
            <th>Pior caso</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Espaço</td>
            <td>O(n)</td> 
            <td>O(n)</td>
        </tr>
        <tr>
            <td>Busca</td>
            <td>O(n)</td> 
            <td>O(n)</td>
        </tr>
        <tr>
            <td>Top</td>
            <td>O(1)</td> 
            <td>O(1)</td>
        </tr>
        <tr>
            <td>Push</td>
            <td>O(1)</td> 
            <td>O(1)</td>
        </tr>
        <tr>
            <td>Pop</td>
            <td>O(1)</td> 
            <td>O(1)</td>
        </tr>
    </tbody>
</table>
</div>

<h2 class="title is-4 margin_top"> Implementação </h2>

A pilha pode ser implementada de duas maneiras: através de um vetor estático com tamanho fixo onde é armazenado o índice da posição do último elemento adicionado (nesse caso a pilha tem uma capacidade fixa), ou através de uma lista encadeada (nesse tipo de implementação a capacidade da pilha é variável).

Ao se implementar com uma lista encadeada é necessário realizar algumas modifiações e manter um ponteiro para a primeira posição da lista de forma que a inserção e a remoção mantenham a complexidade **O(1)**. Na estrutura da lista vamos adicionar um elemento no ínicio e na hora de remover também removemos o elemento do início. A diferença da fila para a pilha na implementação usando uma lista é que na fila se insere o elemento na última posição e é preciso manter um ponteiro para a mesma.