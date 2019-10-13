+++
title = "Add Two Numbers"
description = "Adicione dois números e retorne-os como uma lista encadeada."
date = 2019-02-18T21:24:09-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin", "Python"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/add-two-numbers/"
+++
<h2 class="title is-5"> Enunciado do problema </h2>

Você recebe duas listas encadeadas não vazias que representam dois inteiros não negativos.
Os dígitos são armazenados na ordem inversa e cada um de seus nós contém um único dígito.
Adicione os dois números e retorne-os como uma lista encadeada.

Você pode assumir que os dois números não contêm nenhum zero inicial, exceto o próprio número 0.

<h2 class="title is-5"> Solução </h2>

Assumindo um nó da lista sendo este:

{{< highlight cpp >}}
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
{{< /highlight >}}

Como os dígitos já estão armazenados em ordem inversa com o valor menos significativo primeiro
e o retorno deve ser da mesma forma, só é necessário executar a operação de adição em cada
valor tomando cuidado para não perder nenhum ponteiro e evitar o acesso a nós de ponteiros nulos.

A solução se torna simples e a implementação é direta.

{{< highlight cpp >}}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode *dummy = new ListNode(-1), *it = dummy;
  int carry=0;

  while (l1 || l2) {
    int val1=0,val2=0;

    if(l1){
      val1 = l1->val;
      l1 = l1->next;
    }
    if(l2){
      val2 = l2->val;
      l2 = l2->next;
    }

    int sum = val1+val2+carry;
    carry=sum/10;
    sum%=10;

    it->next = new ListNode(sum);
    it = it->next;
  }

  if(carry>0){
    it->next = new ListNode(1);
  }

  return dummy->next;
}
{{< /highlight >}}

Complexidade de tempo **O(max (n, m))** onde n é o tamanho da lista 1 e m o tamanho da lista 2
