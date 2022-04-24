#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// Assume:
// The distance from head to the start of the loop is x1
// The distane from the start of the loop to the point fast and slow meet is x2
// The distance from the point fast and slow meet to the start of the loop if x3
// fast ptr is twice as fast as slow ptr
// Then:
// x1+x2+x3+x2 = 2(x1+x2)
// which indicates:
// x1 = x3

// Floyd’s Cycle-Finding Algorithm
// TC: O(n) worst case: tail points to head, which means there are n nodes in the cycle.
//          fast pointer will meet slow pointer in the second round which takes at most 2n steps
// SC: O(1) two pointer
class Solution
{
public:
  ListNode* detectCycle(ListNode *head)
  {
    if(!head || !head->next)
      return nullptr;
    
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* meet = nullptr;
    while(fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast)
      {
        meet = slow;
        break;
      }
    }

    if(!meet)
      return nullptr;
    
    slow = head;
    fast = meet;
    while(true)
    {
      if(slow == fast)
        return slow;
      slow = slow->next;
      fast = fast->next;
    }
    return nullptr;
  }
};

int main()
{
  vector<int> ivec = {3, 2, 0, -4};
  ListNode *l = createList(ivec);
  print(l);
  Solution s;
  ListNode* result = s.detectCycle(l);
  cout << (result ? result->val : -1) << endl;
  clear(l);
  return 0;
}
