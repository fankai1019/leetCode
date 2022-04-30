#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// original thought
// TC: O(n) only iterates once
// SC: O(1) no additional list is created
class Solution1
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *pre = head;
    ListNode *curr = pre->next;
    while (curr)
    {
      ListNode *next = curr->next;
      curr->next = pre;
      if (pre == head)
        pre->next = nullptr;

      if (!next)
        return curr;
      pre = curr;
      curr = next;
    }
    return head;
  }
};

class Solution2
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr)
    {
      ListNode *next = curr->next;
      curr->next = prev;

      prev = curr;
      curr = next;
    }
    return prev;
  }
};

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5};
  ListNode *l = createList(ivec);
  print(l);

  // Solution1 s;
  Solution2 s;
  ListNode *result = s.reverseList(l);
  print(result);
  clear(result);

  return 0;
}
