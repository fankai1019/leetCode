#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(nlogk) k num of linked lists, n total number of nodes in two lists, logk levels of small merge sorts
// SC: O(1) per recusive run, O(logk) in total as the stack frame size is logk
class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    if (!lists.size())
      return nullptr;
    return mergeKLists(lists, 0, lists.size() - 1);
  }

private:
  ListNode *mergeKLists(vector<ListNode *> &lists, size_t start, size_t end)
  {
    while (start < end)
    {
      size_t mid = (start + end) / 2;
      ListNode *left = mergeKLists(lists, start, mid);
      ListNode *right = mergeKLists(lists, mid + 1, end);
      return merge(left, right);
    }
    return lists[start];
  }

  ListNode *merge(ListNode *left, ListNode *right)
  {
    ListNode new_head;
    ListNode *curr = &new_head;
    while (left && right)
    {
      if (left->val < right->val)
      {
        curr->next = left;
        left = left->next;
      }
      else
      {
        curr->next = right;
        right = right->next;
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
  vector<vector<int>> ivec_vec = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
  vector<ListNode *> lvec;
  for (size_t i = 0; i < ivec_vec.size(); ++i)
    lvec.push_back(createList(ivec_vec[i]));

  for (size_t i = 0; i < lvec.size(); ++i)
    print(lvec[i]);
  Solution s;
  ListNode *result = s.mergeKLists(lvec);
  print(result);
  clear(result);
  return 0;
}
