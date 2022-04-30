#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(nlogn) tree depth is logn. It takes O(n) time to find the mid point
//     T(n) = 2T(n/2) + n
// SC: O(1) in each recursion. There are O(logn) recursion calls, in total O(logn)
class Solution
{
public:
  TreeNode *sortedListToBST(ListNode *head)
  {
    if (!head)
      return nullptr;
    if (!head->next)
      return new TreeNode(head->val);

    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast->next && fast->next->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *mid = slow->next;
    slow->next = nullptr;
    TreeNode *root = new TreeNode(mid->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;
  }
};

int main()
{
  vector<int> ivec = {-10, -3, 0, 5, 9};
  ListNode *l = createList(ivec);
  print(l);

  Solution s;
  TreeNode *result = s.sortedListToBST(l);
  BFS<TreeNode>::print(result);

  clear(l);
  clear(result);

  return 0;
}
