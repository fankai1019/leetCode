# This is the study notes for learning algorithms

1. Why array amortized insert time is O(1)\
   Assume we are at the point where the capacity is just doubled and assume the capacity now is 2^n.\
   Then the number of insertions we have done is 2^(n-1), then the average time is O(2)

2. Bit operations:
   In c++, the size of an integer is not guarantted to be 4 bytes (32 bits). It depends on the machine. \
   However, we can use int32_t to specify the exact number of bits for an integer. \
   The bit shift operator << yields a copy of the left-hand operand with bits shifted by right-hand operand.\
   The right-hand operand can't be negative and must be strictly less than the number of bits in the result. Otherwise, the operation is undefined.

3. Binary numbers:
   A simple guide about how binary numbers work can be found [https://www.fayewilliams.com/2014/02/18/binary-numbers-explained/].

4. The time complexity of both DFS and BFS traversal is O(V+E), where V and E are the total number of vertices and edges in the graph, respectively
   The memory is taken by DFS/BFS heavily depends on the structure of the tree/graph. The maximum memory taken by DFS is equal to the depth of the tree
   and the maximum memory taken by BFS is equal to the width of the tree.

5. Master Theorem (https://www.programiz.com/dsa/master-theorem#:~:text=The%20master%20method%20is%20a,to%20have%20the%20same%20size)
   T(n) = aT(n/b) + f(n)
   where, T(n) has the following asymptotic bounds:
      1. If f(n) = O(n^log_b(a-e)), then T(n) = O(n^log_b(a))
      2. If f(n) = O(n^log_b(a)), then T(n) = O(n^log_b(a) * log n)
      3. If f(n) = O(n^log_b(a+e)), then T(n) = O(f(n))
   e > 0 is a constant

6. Catalan numbers
   https://stackoverflow.com/questions/27371612/catalan-numbers-recursive-function-time-complexity

   https://www.youtube.com/watch?v=0pTN0qzpt-Y
   c[0] = 1
   c[1] = 1
   c[n] = c[0]c[n-1] + c[1]c[n-2] +...+c[n-1][0]
        = Sum_0^{n-1}c[i]c[n-1-i]

7. Full binary tree:
      A full binary tree has its nodes with 0 or 2 children
   Complete binary tree:
      A binary tree is complete if all levels are completely filled except possibly the last level
      and the last level has all keys as left as possible
   Perfect binary tree:
      A bineary tree is perfect if all nodes have two children and all leaves are at the same level
      A perect binary tree is both full and complete
   Balanced binary tree:
      A binary tree in which the left and right subtrees of every node differ in height by no more than 1.


Useful links:
https://leetcode.wang/