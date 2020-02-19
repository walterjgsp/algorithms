+++
title = "Trie"
description = ""
date = 2019-07-11T19:05:07-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
+++
<h2 class="title is-4"> Definição </h2>

Um trie é uma estrutura de dados semelhante a uma árvore cujos nós armazenam as letras de um alfabeto.

Ao estruturar os nós de uma maneira específica, palavras e seqüências de caracteres podem ser recuperadas da estrutura percorrendo um caminho de ramificação da árvore.

Com essa estrutura, é realmente fácil e rápido obter todas as palavras do dicionário com um prefixo correlacionado.

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
            <td>O(logn)</td> 
            <td>O(logn)</td>
        </tr>
        <tr>
            <td>Adicionar</td>
            <td>O(logn)</td> 
            <td>O(logn)</td>
        </tr>
        <tr>
            <td>Ordenar</td>
            <td>O(nlogn)</td> 
            <td>O(nlogn)</td>
    </tbody>
</table>
</div>

<h2 class="title is-4 margin_top"> Implementação </h2>

A trie é implementada com a seguinte estrutura básica para cada nó

{{< highlight cpp >}}
class TNode{
public:
    vector<TNode*> children;
    bool endWord;
    TNode(){
        children = vector<TNode*> (26,nullptr);
        endWord = false;
    }
};
{{< /highlight >}}

usando um alfabeto de 26 letras.

Ao adicionar e pesquisar qualquer valor na árvore, o que fazemos é atravessar recursivamente a estrutura e verificar se o filho do nó atual existe ou não.
Caso desejemos agregar valor, se o nó não existir, criamos e vamos até o final. Após o término, alteramos a variável endWord para true.

Pesquisando em um trie é muito semelhante à adição. A única diferença é que, se por algum motivo o nó filho que está sendo pesquisado não existir, retorne false. Quando todos os nós existirem, retorne o valor da variável endWord.

Para imprimir todas as palavras de um dicionário de maneira ordenada, basta percorrer a trie em ordem para resolver o problema.