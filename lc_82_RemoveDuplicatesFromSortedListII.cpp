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
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    ListNode new_head(-1);
    new_head.next = head;

    ListNode *curr = &new_head;

    int duplicate = 0;
    while (curr->next && curr->next->next)
    {
      if (curr->next->val == curr->next->next->val)
      {
        duplicate = curr->next->val;
        while (curr->next && curr->next->val == duplicate)
        {
          ListNode *to_be_delete = curr->next;
          ;
          curr->next = curr->next->next;
          delete to_be_delete;
        }
      }
      else
        curr = curr->next;
    }

    return new_head.next;
  }
};

int main()
{
  vector<int> ivec = {1, 1, 1, 2, 3};
  ListNode *l = createList(ivec);
  print(l);

  Solution s;
  ListNode *result = s.deleteDuplicates(l);
  print(result);
  clear(result);

  return 0;
}
