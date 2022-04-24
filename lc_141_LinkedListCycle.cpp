#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// Floyd’s Cycle-Finding Algorithm
// TC: O(n) worst case: tail points to head, which means there are n nodes in the cycle.
//          fast pointer will meet slow pointer in the second round which takes at most 2n steps
// SC: O(1) two pointer
class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (!head)
      return false;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        return true;
    }
    return false;
  }
};

int main()
{
  vector<int> ivec = {3, 2, 0, -4};
  ListNode *l = createList(ivec);
  print(l);
  Solution s;
  bool has_cycle = s.hasCycle(l);
  cout << has_cycle << endl;
  clear(l);
  return 0;
}
