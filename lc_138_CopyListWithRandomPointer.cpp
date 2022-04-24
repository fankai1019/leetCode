#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *random;
  Node(int _val)
  {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

void clear(Node *&head)
{
  if (!head)
  {
    cout << "Cleared!" << endl;
    return;
  }
  if (!head->next)
  {
    delete head;
    head = nullptr;
    cout << "Cleared!" << endl;
    return;
  }
  Node *curr = head;
  while (curr->next->next)
    curr = curr->next;
  delete curr->next;
  curr->next = nullptr;
  clear(head);
}

Node *createList(const vector<vector<int>> &ivec_vec)
{
  Node head(-1);
  Node *curr = &head;
  for (size_t i = 0; i < ivec_vec.size(); ++i)
  {
    curr->next = new Node(ivec_vec[i][0]);
    curr = curr->next;
  }

  curr = head.next;
  size_t n = 0;
  while (curr)
  {
    int step = ivec_vec[n][1];
    if (step != -1)
    {
      Node *random = head.next;
      while (step--)
        random = random->next;
      curr->random = random;
    }
    ++n;
    curr = curr->next;
  }
  return head.next;
}

void print(Node *head)
{
  Node *curr = head;
  while (curr)
  {
    cout << "[" << curr->val << ", " << (!curr->random ? -1 : curr->random->val) << "] ";
    curr = curr->next;
  }
  cout << endl;
}

// TC: O(nlogn) iterate each element twice and map search (insertion) time is logn + rebalace(for insertion)
// SC: O(n) a map is needed
class Solution1
{
public:
  Node *copyRandomList(Node *head)
  {
    if (!head)
      return head;

    map<Node *, Node *> node_map;
    Node new_head(-1);
    Node *curr_new = &new_head;
    Node *curr_old = head;
    while (curr_old)
    {
      curr_new->next = new Node(curr_old->val);
      node_map[curr_old] = curr_new->next;
      curr_old = curr_old->next;
      curr_new = curr_new->next;
    }

    curr_new = new_head.next;
    curr_old = head;
    while (curr_new)
    {
      curr_new->random = node_map[curr_old->random];
      curr_new = curr_new->next;
      curr_old = curr_old->next;
    }
    return new_head.next;
  }
};

// TC: O(n) combine list and separate list
// SC: O(1) no map is needed
class Solution2
{
public:
  Node *copyRandomList(Node *head)
  {
    if (!head)
      return head;
    Node new_head(-1);
    Node *curr_new = &new_head;
    Node *curr_old = head;
    while (curr_old)
    {
      curr_new->next = new Node(curr_old->val);
      curr_old = curr_old->next;
      curr_new = curr_new->next;
    }

    curr_new = &new_head;
    curr_old = head;

    while (curr_old)
    {
      Node *next_new = curr_new->next;
      Node *next_old = curr_old->next;
      curr_new->next = curr_old;
      curr_old->next = next_new;
      curr_old = next_old;
      curr_new = next_new;
    }

    curr_old = new_head.next;
    curr_new = curr_old->next;

    while (curr_new)
    {
      if (curr_old->random)
        curr_new->random = curr_old->random->next;
      curr_old = curr_old->next->next;
      curr_new = curr_new->next ? curr_new->next->next : nullptr;
    }

    curr_old = new_head.next;
    curr_new = &new_head;
    while (curr_new->next)
    {
      curr_new->next = curr_new->next->next;
      curr_old->next = curr_old->next->next; // to avoid memory leak
      curr_new = curr_new->next;
      curr_old = curr_old->next;
    }
    return new_head.next;
  }
};

int main()
{
  vector<vector<int>> ivec_vec = {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
  Node *l = createList(ivec_vec);
  print(l);
  // Solution1 s;
  Solution2 s;
  Node *l_cpy = s.copyRandomList(l);
  print(l_cpy);
  clear(l);
  clear(l_cpy);
  return 0;
}
