+++
title = "Stack"
description = "Linear structure that follows the LIFO order (Last In First Out)"
date = 2019-07-11T04:15:43-03:00
weight = 20
draft = false
toc = true
languages = ["C++"]
+++
<h2 class="title is-4"> Definition </h2>

The stack is a data structure that hold objects in the order of LIFO (Last In First Out) entry. This means
that the first element to be added will be the last element to exit. In its most classic form it implements
following operations:

<div class="margin_left">
  <ol>
    <li><b>Top</b> : this operation returns the last element added to the stack, in some cases it can also be implemented as <b>Peek</b></li>
    <li><b>Push</b>: the operation adds an element to the last stack position</li>
    <li><b>Pop</b> : this operation removes an element from the last stack position. In some implementations, the operation removes and returns the element that you removed </li>
  </ol>
</div>

<div class="container has-text-centered">
<h3 class="title is-5 margin_top"> Complexity </h3>

<table class="table is-striped is-bordered center" >
    <thead>
        <tr>
            <th>Operation</th>
            <th>Average</th> 
            <th>Worst Case</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Space</td>
            <td>O(n)</td> 
            <td>O(n)</td>
        </tr>
        <tr>
            <td>Search</td>
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

<h2 class="title is-4 margin_top"> Implementation </h2>

The stack can be implemented in two ways: through a fixed-size static vector where the index of the position of the last added element is stored (in this case the stack has a fixed capacity), or through a linked list (in this type of implementation the stack capacity is variable).

When deploying with a linked list it is necessary to make some modifications and keep a pointer to the first position in the list so that insertion and removal maintain the complexity **O(1)**. In the structure of the list we will add an element at the beginning and at the time of removing we also remove the element from the beginning. The difference from the queue to the stack in the implementation using a list is that the queue inserts the element in the last position and you need to keep a pointer to it.