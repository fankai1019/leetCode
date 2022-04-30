#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n) fast slow 2 pointers
// SC: O(1) no additional list is created
class Solution
{
public:
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (!head || !head->next)
      return head;

    int sz = 0;
    ListNode *curr = head;
    while (curr)
    {
      ++sz;
      curr = curr->next;
    }
    k %= sz;

    if (k == 0)
      return head;

    ListNode new_head(-1);
    new_head.next = head;

    ListNode *slow = &new_head;
    ListNode *fast = slow;
    for (int i = 0; i < k; ++i)
      fast = fast->next;

    while (fast->next)
    {
      slow = slow->next;
      fast = fast->next;
    }

    fast->next = new_head.next;
    new_head.next = slow->next;
    slow->next = nullptr;

    return new_head.next;
  }
};

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5};
  int k = 2;
  ListNode *l = createList(ivec);
  print(l);

  Solution s;
  ListNode *result = s.rotateRight(l, k);
  print(result);
  clear(result);

  return 0;
}
