#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(n) iterate the list once
// SP: O(1)
class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode new_head;
    new_head.next = head;
    ListNode *curr = &new_head;
    while (curr && curr->next)
    {
      if (curr->next->val == val)
      {
        ListNode *curr_next = curr->next;
        curr->next = curr->next->next;
        delete curr_next;
        curr_next = nullptr;
      }
      else
        curr = curr->next;
    }
    return new_head.next;
  }
};

int main()
{
  vector<int> ivec = {1, 2, 6, 3, 4, 5, 6};
  int val = 6;
  ListNode *l = createList(ivec);
  print(l);
  Solution s;
  ListNode *result = s.removeElements(l, val);
  print(result);
  clear(result);
  return 0;
}
