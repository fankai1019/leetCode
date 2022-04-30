#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(n) reverse right half of the list and insert it into left half accordingly
// SC: O(1) two pointer
class Solution
{
public:
  void reorderList(ListNode *head)
  {
    // The number of nodes in the list is in the range [1, 5e10]
    if (!head->next || !head->next->next)
      return;

    // determine the mid point, slow is the mid point after loop
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // curr is the node next to mid point
    ListNode *curr = slow->next;
    slow->next = nullptr;

    // reverse nodes from curr to tail
    ListNode *prev = nullptr;
    while (curr)
    {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    // frist node on the right is prev after the reverse
    // then merge left and right, num of right nodes <= num of left nodes
    ListNode *curr_right = prev;
    ListNode *curr_left = head;
    while (curr_right)
    {
      ListNode *next_left = curr_left->next;
      ListNode *next_right = curr_right->next;
      curr_left->next = curr_right;
      curr_right->next = next_left;
      curr_left = next_left;
      curr_right = next_right;
    }
  }
};

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5};
  ListNode *l = createList(ivec);
  print(l);
  Solution s;
  s.reorderList(l);
  print(l);
  clear(l);
  return 0;
}
