#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(n) iterate the list once
// SP: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        // it is guaranteed the node to be deleted is not a tail node
    ListNode* prev = nullptr;
    ListNode* curr = node;
    while(curr->next)
    {
      curr->val = curr->next->val;
      prev = curr;
      curr = curr->next;
    }
    delete prev->next;
    prev->next = nullptr;
    }
};

int main()
{
  vector<int> ivec = {4, 5, 1, 9};
  ListNode *l = createList(ivec);
  ListNode *node = l;
  node = node->next;
  print(l);
  Solution s;
  s.deleteNode(node);
  print(l);
  clear(l);
  return 0;
}
