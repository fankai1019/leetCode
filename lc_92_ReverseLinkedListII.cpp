#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n) only iterates twice
// SC: O(1) no additional list is created
class Solution
{
public:
  ListNode *reverseList(ListNode *head, int left, int right)
  {
    // 1 <= n <= 500
    // 1 <= left <= right <=n
    if (!head->next || left == right)
      return head;

    ListNode new_head;
    new_head.next = head;

    ListNode *n1 = nullptr;
    ListNode *n2 = nullptr;
    ListNode *n3 = nullptr;
    ListNode *n4 = nullptr;

    ListNode *curr = &new_head;
    int n = 0;
    while (curr)
    {
      if (n == left - 1)
        n1 = curr;
      else if (n == left)
        n2 = curr;
      else if (n == right)
        n3 = curr;
      else if (n == right + 1)
        n4 = curr;
      curr = curr->next;
      ++n;
    }

    ListNode *pre = n4;
    curr = n2;
    while (curr != n4)
    {
      ListNode *next = curr->next;
      curr->next = pre;
      pre = curr;
      curr = next;
    }
    n1->next = pre;

    return new_head.next;
  }
};

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5};
  int left = 2;
  int right = 4;
  ListNode *l = createList(ivec);
  print(l);

  Solution s;
  ListNode *result = s.reverseList(l, left, right);
  print(result);
  clear(result);

  return 0;
}
