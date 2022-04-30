#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(n^2), insertion sort
// SP: O(1) only a few additional pointers are used
class Solution1
{
public:
  ListNode *insertionSortList(ListNode *head)
  {
    // The number of nodes in the list is in the range [1, 5000]
    if(!head->next)
      return head;
    ListNode new_head(-5001);
    new_head.next = head;
    ListNode* anchor = head;
    ListNode* curr = head->next;
    while(curr)
    {
      ListNode* left = &new_head;
      while(left != anchor)
      {
        if(left->val <= curr->val && left->next->val > curr->val)
        {
          ListNode* curr_next = curr->next;
          ListNode* left_next = left->next;
          left->next= curr;
          curr->next = left_next;
          anchor->next = curr_next;
          break;
        }
        left = left->next;
      }
      if(left == anchor)
        anchor = curr;
      curr = anchor->next;
    }
    return new_head.next;
  }
};

// get rid of the idea of anchor by nullptr
// TC: O(n^2), insertion sort
// SP: O(1) only a few additional pointers are used
class Solution2
{
public:
  ListNode *insertionSortList(ListNode *head)
  {
    // The number of nodes in the list is in the range [1, 5000]
    if(!head->next)
      return head;
    ListNode new_head(-5001);
    new_head.next = head;
    ListNode* curr = head->next;
    head->next = nullptr;

    while(curr)
    {
      ListNode* curr_next = curr->next;

      ListNode* curr2 = &new_head;
      while(curr2 && curr2->next && curr2->next->val <= curr->val)
          curr2 = curr2->next;

      ListNode* curr2_next = curr2->next;
      curr2->next = curr;
      curr->next = curr2_next;
      curr = curr_next;
    }
    return new_head.next;
  }
};

int main()
{
  vector<int> ivec = {4, 2, 1, 3};
  ListNode *l = createList(ivec);
  print(l);
  // Solution1 s;
  Solution2 s;
  ListNode *result = s.insertionSortList(l);
  print(result);
  clear(result);
  return 0;
}
