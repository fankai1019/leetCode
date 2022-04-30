#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n) iterate once
// SC: O(1) no additional list is created
class Solution
{
public:
  ListNode *swapPairs(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode new_head(-1);
    new_head.next = head;
    ListNode *curr = head;
    ListNode *pre = &new_head;
    while (curr && curr->next)
    {
      ListNode *next = curr->next;
      ListNode *next_next = curr->next->next;
      pre->next = next;
      next->next = curr;
      curr->next = next_next;
      pre = curr;
      curr = curr->next;
    }

    return new_head.next;
  }
};

int main()
{
  vector<int> ivec = {1, 2, 3, 4};
  ListNode *l = createList(ivec);
  print(l);

  Solution s;
  ListNode *result = s.swapPairs(l);
  print(result);
  clear(result);

  return 0;
}
