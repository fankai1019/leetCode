#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(n) compare first halve and reverse of second halve
// SC: O(1) two pointers
class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    // The number of nodes in the list is [1, 10^5]
    if (!head->next)
      return true;

    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *right = slow->next;
    slow->next = nullptr;

    right = reverse(right);

    ListNode *left_curr = head;
    ListNode *right_curr = right;
    while (left_curr && right_curr)
    {
      if (left_curr->val != right_curr->val)
        return false;
      left_curr = left_curr->next;
      right_curr = right_curr->next;
    }
    return true;
  }

private:
  ListNode *reverse(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr)
    {
      ListNode *curr_next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = curr_next;
    }
    return prev;
  }
};

int main()
{
  vector<int> ivec = {1, 2, 2, 1};
  ListNode *l = createList(ivec);
  print(l);
  Solution s;
  cout << s.isPalindrome(l) << endl;
  clear(l);
  return 0;
}
