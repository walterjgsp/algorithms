+++
title = "LRU Cache"
description = "Projetar e implementar uma estrutura de dados para o cache LRU (Least Recently Used). Deve suportar as seguintes operações: obter e colocar."
date = 2019-03-20T21:46:11-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
level = 2
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/lru-cache/"
+++
<h2 class="title is-4"> Enunciado do problema </h2>

Projetar e implementar uma estrutura de dados para o cache LRU (Least Recently Used). Deve suportar as seguintes operações: obter e colocar.

get (key) - Obtém o valor (sempre será positivo) da chave se a chave existir no cache, caso contrário, retornará -1.
put (chave, valor) - Defina ou insira o valor se a chave ainda não estiver presente. Quando o cache atingiu sua capacidade,
ele deve invalidar o item usado menos recentemente antes de inserir um novo item.

<h2 class="title is-5"> Solução </h2>

No Cache LRU, a chave recente menos utilizada é despejada da memória. Uma maneira de manter um controle do uso da chave é manter a chave em um
das extremidades na estrutura selecionada para simular a memória. Toda vez que uma chave é usada (sendo as ações de get ou put)
o valor será colocado no início e, antes da operação put, removerá a chave menos usada se o tamanho máximo do array já foi
alcançado.

Uma solução é manter um vetor de chaves e, cada vez que as funções são chamadas, o vetor é reorganizada para corresponder à condição declarada.
Isso torna a solução **O(n*m)** onde n é o número de operações e m o tamanho máximo do cache.

Se uma lista encadeada for usada com um mapa não ordenado, é possível fazer a solução **O(1)** para ambas as operações (obter e colocar). O mapa será
usado para manter uma faixa de todas as chaves na minha lista e os ponteiros para os nós da lista dessas chaves. Toda vez que uma ação é chamada, nós rearranjamos
apenas o nó que foi usado colocando-o na frente da lista, e essas operações são **O(1)** para uma lista.


{{< highlight cpp >}}
class LRUCache {
private:
  struct Node{
    int key, val;
    Node(int k, int v){
      key = k, val = v;
    }
  };
  unordered_map<int, std::list<Node>::iterator> mapping;
  list<Node> lru;
  int maxSize;

public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }

    int get(int key) {
        if(mapping.find(key)!=mapping.end()){
          int val = mapping[key]->val;
          lru.erase(mapping[key]);
          addFront(key,val);
          return val;
        }
        return -1;
    }

    int removeBack(){
      auto it = lru.back();
      int key = it.key;
      lru.pop_back();
      return key;
    }

    void addFront(int key, int val){
      lru.push_front(Node(key,val));
      mapping[key]=lru.begin();
    }

    void put(int key, int value) {
        if(mapping.find(key)!=mapping.end()){
          lru.erase(mapping[key]);
        }else if(lru.size()>=maxSize){
          mapping.erase(removeBack());
        }

        addFront(key,value);
    }
};
{{< /highlight >}}
