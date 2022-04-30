#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(n) iterate the list once
// SP: O(1) odd even pointers
class Solution
{
public:
  ListNode *oddEvenList(ListNode *head)
  {
    if (!head)
      return head;
    ListNode *odd = head;
    ListNode *even_head = head->next;
    ListNode *even = even_head;

    while (even && even->next)
    {
      odd->next = odd->next->next;
      even->next = even->next->next;
      odd = odd->next;
      even = even->next;
    }

    odd->next = even_head;
    return head;
  }
};

int main()
{
  vector<int> ivec = {2, 1, 3, 5, 6, 4, 7};
  ListNode *l = createList(ivec);
  print(l);
  Solution s;
  ListNode *result = s.oddEvenList(l);
  print(result);
  clear(result);
  return 0;
}
