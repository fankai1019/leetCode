#include <iostream>
#include <unordered_map>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(m+n) m num of nodes in A, n num of nodes in B, iterate through A and B
// SP: O(1) only use several tmp pointers
class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode* headB)
  {
    size_t countA = 1;
    size_t countB = 1;
    ListNode* currA = headA;
    ListNode* currB = headB;

    while(currA)
    {
      currA = currA->next;
      ++countA;
    }

    while(currB)
    {
      currB = currB->next;
      ++countB;
    }

    size_t diff = countA > countB ? countA - countB : countB - countA;

    currA = headA;
    currB = headB;
    if(countA > countB)
    {
      while(diff--)
        currA = currA->next;
    }
    else
    {
      while(diff--)
        currB = currB->next;
    }

    while(currA)
    {
      if(currA == currB)
        return currA;
      currA = currA->next;
      currB = currB->next;
    }

    return nullptr;
  }
};

int main()
{
  vector<int> ivec1 = {2, 4};
  vector<int> ivec2 = {1, 9, 1};
  vector<int> ivec3 = {3};
  ListNode *l1 = createList(ivec1);
  ListNode *l2 = createList(ivec2);
  ListNode *l3 = createList(ivec3);

  ListNode* tail2 = l2;
  while(tail2 && tail2->next)
    tail2 = tail2->next;
  tail2->next = l1;

  ListNode* tail3 = l3;
  while(tail3 && tail3->next)
    tail3 = tail3->next;
  tail3->next = l1;

  print(l1);
  print(l2);
  print(l3);
  Solution s;
  ListNode *result = s.getIntersectionNode(l2, l3);
  if(result)
    cout << result->val << endl;
  else
    cout << "nullptr" << endl;

  tail2->next = nullptr;
  tail3->next = nullptr;

  clear(l1);
  clear(l2);
  clear(l3);
  return 0;
}
