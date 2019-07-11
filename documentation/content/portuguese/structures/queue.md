+++
title = "Fila"
description = "Estrutura de dados linear que obedece a ordem FIFO (First In First Out) em suas funções"
date = 2019-07-04T19:40:35-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
+++

<h2 class="title is-4"> Definição </h2>

A fila é uma estrutura de dados para conter objetos obedecendo a ordem de entrada FIFO( First In First Out ). Isso significa
que o primeiro elemento a ser adicionado sera o primeiro elemento a sair. Em sua forma mais clássica ela implementa
as seguintes operações:

<div class="margin_left">
  <ol>
    <li><b>Peek</b> : essa operação retorna o primeiro elemento da fila, em alguns casos pode ser também implementada como <b>Front</b></li>
    <li><b>Push</b>: a operação adiciona um elemento na última posição da fila</li>
    <li><b>Pop</b> : essa operação remove um elemento da primeira posição da fila. Em algumas implementações, a operação remove e retorna o elemento que removeu </li>
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
            <td>Peek</td>
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

A fila pode ser implementada de duas maneiras: através de um vetor estático com tamanho fixo onde é armazenado o índice da posição inicial e esse valor vai rotacionando pelo vetor, ou através de uma lista encadeada.

Ao se implementar com uma lista encadeada é necessário manter um ponteiro para a última posição da lista de forma que a inserção mantenha a complexidade **O(1)**.