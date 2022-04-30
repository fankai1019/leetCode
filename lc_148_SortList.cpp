#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(nlogn) T(n) = 2T(n/2) + n
// SP: O(logn) recursive stack has size O(logn)
class Solution
{
public:
  ListNode *sortList(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    ListNode *fast = head->next;
    ListNode *slow = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *mid = slow;
    ListNode *mid_next = slow->next;
    mid->next = nullptr;

    ListNode *tmp1 = sortList(head);
    ListNode *tmp2 = sortList(mid_next);
    ListNode *result = merge(tmp1, tmp2);
    return result;
  }

private:
  ListNode *merge(ListNode *left, ListNode *right)
  {
    ListNode new_head;
    ListNode *curr = &new_head;
    while (left && right)
    {
      if (left->val <= right->val)
      {
        ListNode *left_next = left->next;
        curr->next = left;
        left = left_next;
      }
      else
      {
        ListNode *right_next = right->next;
        curr->next = right;
        right = right_next;
      }
      curr = curr->next;
    }

    if (!left)
      curr->next = right;
    else
      curr->next = left;
    return new_head.next;
  }
};

int main()
{
  vector<int> ivec = {4, 2, 1, 3, 5};
  ListNode *l = createList(ivec);
  print(l);
  Solution s;
  ListNode *result = s.sortList(l);
  print(result);
  clear(result);
  return 0;
}
