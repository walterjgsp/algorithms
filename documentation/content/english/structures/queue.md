+++
title = "Queue"
description = "Linear structure that follows the FIFO order (First In First Out)"
date = 2019-07-04T19:40:21-03:00
weight = 20
draft = false
toc = true
languages = ["C++","Kotlin"]
+++
<h2 class="title is-4"> Definition </h2>

The queue is a data structure to contain objects in the FIFO (First In First Out) order. This means
that the first element to be added will be the first element to come out. In its most classic form it implements
following operations:

<div class="margin_left">
  <ol>
    <li><b>Peek</b> : this operation returns the first element of the queue, in some cases it can also be implemented as <b>Front</b></li>
    <li><b>Push</b>: the operation adds an element in the last position of the queue</li>
    <li><b>Pop</b> : this operation removes an element from the first position in the queue. In some implementations, the operation removes and returns the element that you removed </li>
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

<h2 class="title is-4 margin_top"> Implementation </h2>

The queue can be implemented in two ways: through a static vector with fixed size where the index of the initial position is stored and this value is rotated by the vector, or through a linked list.

When deploying with a linked list, it is necessary to keep a pointer to the last position in the list so that the insert maintains the complexity **O(1)**.