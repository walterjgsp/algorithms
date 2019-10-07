+++
title = "Is Graph Bipartite"
description = "Dado um gráfico não direcionado, retorne true se e somente se for bipartido."
date = 2019-10-07T08:55:56-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/is-graph-bipartite/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Dado um gráfico não direcionado, retorne true se e somente se for bipartido.

Lembre-se de que um gráfico é bipartido se pudermos dividir seu conjunto de nós em dois subconjuntos independentes A e B, de modo que cada extremidade do gráfico tenha um nó em A e outro nó em B.

O gráfico é fornecido da seguinte forma: o gráfico [i] é uma lista de índices j para os quais existe a borda entre os nós iej. Cada nó é um número inteiro entre 0 e graph.length - 1. Não há arestas próprias ou arestas paralelas: o gráfico [i] não contém i e não contém nenhum elemento duas vezes.

<h2 class="title is-5"> Solução </h2>

Esse problema pode ser resolvido colorindo o gráfico usando um bfs, se em algum ponto de nossa coloração tivermos um vértice vizinho já colorido e a cor igual à atual
vértice o gráfico não é biparatita. Caso contrário, retornamos verdadeiro.

{{< highlight cpp >}}
bool isBipartite(vector<vector<int>>& graph) {
    map<int,int> colors;

    for(int i=0;i<graph.size();i++){

        if(colors.find(i)==colors.end()){
            int color = 0;

            queue<int> bfs;
            bfs.push(i);

            while(!bfs.empty()){
                int tam = bfs.size();

                for(int i=0;i<tam;i++){
                    int vertex = bfs.front();
                    bfs.pop();

                    if(colors.find(vertex)!=colors.end())
                        continue;

                    colors[vertex] = color;

                    for(int edge : graph[vertex]){
                        if(colors.find(edge)!=colors.end()){
                            if(colors[edge]==color)
                                return false;
                        }else{
                            bfs.push(edge);
                        }
                    }
                }

                color = color ^ 1;
            }
        }
    }

    return true;
}
{{< /highlight >}}

Complexidade de tempo: **O(V+E)**
