# ShortestPath

Algorithms and Data Structures laboratory6

### Instructions
For a given set of connections between nodes, find the length of the shortest path from the starting point to the destination. Each connection is defined by the 2 nodes it connects and by length (a non-negative integer). Connections are bi-directional (if a is connected with b by a connection of length d, then also b is connected with a with the same length). The recommended way to solve this task is to use the Dijkstra algorithm.<br/><br/>

Note that it may be impossible to reach the destination from the starting point (i.e. a graph may not be connected). In this case, you should print an exclamation mark '!' on the screen.

### Input
<ul>
  <li>n: the number of nodes (non-negative integer),</li>
  <li>m: the number of connections (non-negative integer),</li>
  <li>Next m lines in the form: v u d, where: v and u are the indices of nodes that are connected (non-negative integers from range [0, n-1]), d is the length of the connection between these two nodes (non-negative integer).</li>
  <li>t: the number of tests (non-negative integer),</li>
  <li>Next t lines in the form: a b, where: a is the starting point of the path to be found (non-negative integer from range [0, n-1]), b is the destination of the path to be found (non-negative integer from range [0, n-1]).</li>
</ul>

### Output
For each test: one line with the length of the shortest path for nodes given in this test, or '!' if these vertices are not connected.
