+++
title = "Add One Row to Tree"
description = "Dada a raiz de uma árvore binária, em seguida, valor v e profundidade d, é necessário adicionar uma linha de nós com valor v na profundidade especificada d. O nó raiz está na profundidade 1."
date = 2019-02-18T19:24:15-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin","Python"]
level = 1
source = "LeetCode"
source_link = "https://leetcode.com/"
link = "https://leetcode.com/problems/add-one-row-to-tree/"
+++
<h2 class="title is-5"> Enunciado do problema </h2>

Dada a raiz de uma árvore binária, em seguida, valor v e profundidade d, é necessário adicionar uma linha de nós com o valor v
na profundidade dada d. O nó raiz está na profundidade 1.

A regra de adição é: dada uma profundidade inteira positiva d, para cada nó da árvore NÃO nulo N na profundidade d-1,
crie dois nós de árvore com o valor v como raiz da subárvore esquerda de N e raiz da subárvore direita.
E a subárvore esquerda original de N deve ser a subárvore esquerda da nova raiz da subárvore esquerda,
sua subárvore direita original deve ser a subárvore direita da nova raiz da subárvore direita.
Se a profundidade d for 1, significa que não há profundidade d-1, crie um nó de árvore com o valor v
como a nova raiz de toda a árvore original e a árvore original é a subárvore esquerda da nova raiz.

<h2 class="title is-5"> Solução </h2>

Supondo que a estrutura do nó da árvore seja:

{{< highlight cpp >}}
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x){
    val = x;
    left = NULL;
    right = NULL;
  }
}
{{< /highlight >}}

O problema pode ser resolvido recursivamente tratando os casos básicos:

<div class="margin_left">
  <ol>
    <li>d-1 = 0 : Essa condição significa que precisamos adicionar uma nova raiz à árvore. Crie um novo nó e faça com que ele faça root com a raiz real como filhos esquerdos.</li>
    <li>d-1 = 1 : Este nó é pai dos novos nós que serão adicionados. Crie dois novos nós para esquerda e direita e crie os respectivos filhos antigos do pais filhos esquerdo e direito.</li>
    <li>d-1 > 1 : Neste caso, é necessário ir mais fundo na árvore. Verifique se a criança existe e se positiva chama a mesma função com o valor de profundidade menos 1. </li>
  </ol>
</div>

Com essas informações, a seguinte implementação é feita:

{{< highlight cpp >}}
TreeNode* addOneRow(TreeNode* root, int v, int d) {

    if(d-1==0){
        TreeNode* newRoot = new TreeNode(v);
        newRoot->left = root;
        return newRoot;
    }

    if(d-1==1){
        TreeNode *newleft = new TreeNode(v), *newright = new TreeNode(v);
        newleft->left = root->left;
        newright->right = root->right;
        root->left = newleft;
        root->right = newright;
    }else{
        if(root->left) addOneRow(root->left,v,d-1);
        if(root->right)addOneRow(root->right,v,d-1);
    }
    return root;
}
{{< /highlight >}}

Complexidade de tempo: **O(n)**
