#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n) iterate once
// SC: O(1) only a few pointers
class Solution
{
public:
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (k == 1 || !head->next)
      return head;

    ListNode new_head;
    new_head.next = head;

    ListNode *kstart = &new_head;

    bool flag = true;
    while (flag)
    {
      int step = k;
      ListNode *kend = kstart;
      while (kend && step--)
        kend = kend->next;
      if (!kend)
        flag = false;

      if (flag)
      {
        ListNode *next = kend->next;
        kend->next = nullptr;

        ListNode *prev = kstart;
        ListNode *curr = prev->next;

        while (curr)
        {
          ListNode *curr_next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = curr_next;
        }
        ListNode *tmp = kstart->next;
        tmp->next = next;
        kstart->next = kend;
        kstart = tmp;
      }
    }
    return new_head.next;
  }
};

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5};
  ListNode *l = createList(ivec);
  print(l);
  int k = 3;
  Solution s;
  ListNode *result = s.reverseKGroup(l, k);
  print(result);
  clear(result);
  return 0;
}
