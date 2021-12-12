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