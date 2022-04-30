#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n) only iterates once withiout memory leak
// SC: O(1) no additional list is created
class Solution
{
public:
  ListNode *partition(ListNode *head, int x)
  {
    if (!head || !head->next)
      return head;

    ListNode small_head;
    ListNode large_head;

    ListNode *curr = head;
    ListNode *curr_small = &small_head;
    ListNode *curr_large = &large_head;
    while (curr)
    {
      if (curr->val < x)
      {
        curr_small->next = curr;
        curr = curr->next;
        curr_small = curr_small->next;
        curr_small->next = nullptr;
      }
      else
      {
        curr_large->next = curr;
        curr = curr->next;
        curr_large = curr_large->next;
        curr_large->next = nullptr;
      }
    }

    curr_small->next = large_head.next;
    return small_head.next;
  }
};

int main()
{
  vector<int> ivec = {1, 4, 3, 2, 5, 2};
  int x = 3;
  ListNode *l = createList(ivec);
  print(l);

  Solution s;
  ListNode *result = s.partition(l, x);
  print(result);
  clear(result);

  return 0;
}
