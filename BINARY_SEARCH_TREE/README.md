# Binary Search Tree

### Instructions
Implement a binary search tree (BST). Each element of a tree should have a key (unsigned integer).<br/>
Your program should support the following operations:
<ul>
  <li>+ - add a new element with a given key to the tree,</li>
  <li>- - remove an element with a given key from the tree (ignore this operation if there is no such an element in the tree),</li>
  <li>? - search the tree for an element with a given key, write '1' if the element was found, or '0' if not,</li>
  <li>m - write the key of the minimum element in the tree,</li>
  <li>M - write the key of the maximum element in the tree,</li>
  <li>q - quit the program.</li>
</ul>

### Input
Any number of lines, one of the following commands in each:
<ul>
  <li>+ (key)</li>
  <li>- (key)</li>
  <li>? (key)</li>
  <li>m</li>
  <li>M</li>
  <li>q</li>
</ul>
Where:
<ul>
  <li>+, -, ?, m, M and q are the command identifiers,</li>
  <li>(key) is the key of an element,</li>
</ul>
You should assume that q will be always the last operation.

### Output
The key of a given element (for m and M operations), or single 0/1 value for ? operation (depending on whether the element was found).
  
  
  
  
