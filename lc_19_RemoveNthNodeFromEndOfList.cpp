#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n) linear time to reach the nth element
// SC: O(1) no additional list is created
class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode new_head(-1);
    new_head.next = head;

    ListNode *slow = &new_head; // pre node of to be deleted
    ListNode *fast = &new_head;
    for (int i = 0; i < n; ++i)
      fast = fast->next; // fast is never empty as 1<= n <=sz

    while (fast->next)
    {
      fast = fast->next;
      slow = slow->next;
    }

    ListNode *to_be_deleted = slow->next;
    slow->next = slow->next->next;
    delete to_be_deleted;
    return new_head.next;
  }
};

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5};
  int n = 2;
  ListNode *l = createList(ivec);
  print(l);

  Solution s;
  ListNode *result = s.removeNthFromEnd(l, 2);
  print(result);
  clear(l);

  return 0;
}
