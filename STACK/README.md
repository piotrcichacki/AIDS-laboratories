# STACK

### Instructions
Implement a stack, using a linked list implementation. Every element of the list should contain a key of type int (signed integer), and some pointers that are required by your stack implementation.<br/>

Your program should support the following operations:
<ul>
  <li>i - insert (push) a new element to your stack,</li>
  <li>d - delete (pop) an element from your stack and print its key on the screen (if underflow occurs, the '!' character should be printed),</li>
  <li>g - get an element of the list from given position and print its key on the screen (if the given index is greater or equal the size of your list, you should print the '?' character),</li>
  <li>q - quit the program.</li>
</ul>
The first element (at the bottom of the stack) of your list should be interpreted as an element on position 0, the second element is on position 1, etc. The top element of the stack is at index size-1.

### Input
Any number of lines, and each line contains one of the commands:
<ul>
  <li>i (key)</li>
  <li>d</li>
  <li>g (index)</li>
  <li>q</li>
</ul>  
Where:
<ul>
  <li>i, d, g, q are identifiers of the operation,</li>
  <li>(index) is the position of an element in the list,</li>
  <li>(key) is the key of an element (value of type int to be stored in the element).</li>
</ul>
You can assume that q will be always the last operation.

### Output
For every g and d operation the key of a found (or deleted) element is printed. Also, the '!' character should be printed if underflow occurs during d operation, and '?' should be printed if the given index was out of range in the g operation.. Values should be separated by the new line character (std::endl or \n).


