#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n) insert one by one
// SC: O(1) no additional list is created
class Solution1
{
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    if (!list1 && !list2)
      return nullptr;
    else if (!list1)
      return list2;
    else if (!list2)
      return list1;

    if (list1->val <= list2->val)
    {
      ListNode *curr1 = list1;
      ListNode *curr2 = list2;
      while (curr1)
      {
        if (curr1->next)
        {
          if (curr2)
          {
            int curr2_val = curr2->val;
            if (curr1->val <= curr2_val && curr1->next->val > curr2_val)
            {
              ListNode *tmp1 = curr1->next;
              ListNode *tmp2 = curr2->next;

              curr1->next = curr2;
              curr2->next = tmp1;

              curr2 = tmp2;
            }
            curr1 = curr1->next;
          }
          else
            return list1;
        }
        else
        {
          curr1->next = curr2;
          return list1;
        }
      }
      return list1;
    }
    else
      return mergeTwoLists(list2, list1);
  }
};

// cleaner solution
// TC: O(n) insert one by one
// SC: O(1) no additional list is created
class Solution2
{
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode new_head(-1);
    ListNode *curr = &new_head;
    while (list1 && list2)
    {
      if (list1->val <= list2->val)
      {
        curr->next = list1;
        list1 = list1->next;
      }
      else
      {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }

    if (list1)
      curr->next = list1;
    else if (list2)
      curr->next = list2;
    return new_head.next;
  }
};

int main()
{
  vector<int> ivec1 = {1, 2, 4};
  vector<int> ivec2 = {1, 3, 4};
  ListNode *l1 = createList(ivec1);
  ListNode *l2 = createList(ivec2);
  print(l1);
  print(l2);

  // Solution1 s;
  Solution2 s;
  ListNode *result = s.mergeTwoLists(l1, l2);
  print(result);
  clear(result);

  return 0;
}
