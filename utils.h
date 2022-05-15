#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// debug print
#define dprint(x) std::cout << #x " = " << x << std::endl

#define null INT_MIN

struct ListNode
{
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr)
  {
  }
  ListNode(int x)
      : val(x), next(nullptr)
  {
  }
  ListNode(int x, ListNode *next)
      : val(x), next(next)
  {
  }
};

struct TreeNode
{
  TreeNode()
      : val(0), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x)
      : val(x), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right)
  {
  }
  int val;
  TreeNode *left;
  TreeNode *right;
};

struct Node
{
  Node()
      : val(0), left(nullptr), right(nullptr), next(nullptr)
  {
  }
  Node(int x)
      : val(x), left(nullptr), right(nullptr), next(nullptr)
  {
  }
  Node(int x, Node *left, Node *right, Node *next = nullptr)
      : val(x), left(left), right(right), next(next)
  {
  }
  int val;
  Node *left;
  Node *right;
  Node *next;
};

template <typename T>
class BFS
{
public:
  BFS(const vector<int> &ivec)
  {
    if (!ivec.size())
      return;
    nodes_.push_back(unique_ptr<T>(new T(ivec[0]))); // root
    queue<T *> tq;
    tq.push(nodes_[0].get());
    size_t count = 0;
    while (tq.size())
    {
      size_t size = tq.size();
      for (size_t i = 0; i < size; ++i)
      {
        T *curr = tq.front();
        tq.pop();
        if (count + 1 < ivec.size() && ivec[count + 1] != null)
        {
          nodes_.push_back(unique_ptr<T>(new T(ivec[count + 1])));
          tq.push(nodes_.back().get());
          curr->left = tq.back();
          count++;
        }
        else
          count++;
        if (count + 1 < ivec.size() && ivec[count + 1] != null)
        {
          nodes_.push_back(unique_ptr<T>(new T(ivec[count + 1])));
          tq.push(nodes_.back().get());
          curr->right = tq.back();
          count++;
        }
        else
          count++;
      }
    }
  }

  // find the first node that has value == a
  // order: 0 pre order, 1 in order, 2 post order
  // if not found, return null ptr
  T *find(int a, int order = 0) const
  {
    if (!nodes_.size() || !nodes_[0])
      return nullptr;

    // a stack of pair of nodes and whether they are visited
    stack<pair<T *, bool>> ns;
    ns.push(make_pair(nodes_[0].get(), false));
    while (ns.size())
    {
      pair<T *, bool> curr = ns.top();
      ns.pop();
      if (!curr.first)
        continue;
      if (!curr.second) // not visited
      {
        if (order == 0)
        {
          ns.push(make_pair(curr.first->right, false));
          ns.push(make_pair(curr.first->left, false));
          ns.push(make_pair(curr.first, true));
        }
        else if (order == 1)
        {
          ns.push(make_pair(curr.first->right, false));
          ns.push(make_pair(curr.first, true));
          ns.push(make_pair(curr.first->left, false));
        }
        else
        {
          ns.push(make_pair(curr.first, true));
          ns.push(make_pair(curr.first->right, false));
          ns.push(make_pair(curr.first->left, false));
        }
      }
      else
      {
        if (curr.first->val == a)
          return curr.first;
      }
    }
    return nullptr;
  }

  T *root()
  {
    if (nodes_.size())
      return nodes_[0].get();
    return nullptr;
  }

private:
  vector<unique_ptr<T>> nodes_;
};

class Sort
{
public:
  void mergeSort(vector<int> &ivec)
  {
    if (ivec.size() <= 1)
      return;
    mergeSort(ivec, 0, ivec.size() - 1);
  }

private:
  void mergeSort(vector<int> &ivec, size_t start, size_t end)
  {
    if (start < end)
    {
      size_t mid = (start + end) / 2;
      mergeSort(ivec, start, mid);
      mergeSort(ivec, mid + 1, end);
      merge(ivec, start, mid, end);
    }
  }

  void merge(vector<int> &ivec, size_t start, size_t mid, size_t end)
  {
    size_t i = start;
    size_t j = mid + 1;
    size_t k = 0;
    vector<int> tmp(end - start + 1);

    while (i <= mid && j <= end)
    {
      if (ivec[i] <= ivec[j])
        tmp[k++] = ivec[i++];
      else
        tmp[k++] = ivec[j++];
    }

    while (i <= mid)
      tmp[k++] = ivec[i++];

    while (j <= end)
      tmp[k++] = ivec[j++];

    for (i = start; i <= end; ++i)
      ivec[i] = tmp[i - start];
  }
};

template <typename T>
inline void print(T *root)
{
  if (!root)
    return;
  queue<T *> tq;
  tq.push(root);

  vector<int> row;
  row.push_back(root->val);
  while (tq.size())
  {
    bool quit = true;
    for (size_t i = 0; i < row.size(); ++i)
    {
      if (row[i] != -1)
      {
        quit = false;
        break;
      }
    }
    if (quit)
      break;

    row.clear();
    size_t size = tq.size();
    for (size_t i = 0; i < size; ++i)
    {
      T *curr = tq.front();
      tq.pop();
      if (curr)
        cout << curr->val << " ";
      else
        cout << "n ";

      if (curr)
      {
        tq.push(curr->left);
        if (curr->left)
          row.push_back(curr->left->val);
        else
          row.push_back(null);
      }
      else
        tq.push(nullptr);

      if (curr)
      {
        tq.push(curr->right);
        if (curr->right)
          row.push_back(curr->right->val);
        else
          row.push_back(null);
      }
      else
        tq.push(nullptr);
    }
    cout << endl;
  }
  cout << endl;
}

inline void
print(const ListNode *const head)
{
  const ListNode *curr = head;
  while (curr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
  return;
}

inline ListNode *
createList(const vector<int> &ivec)
{
  ListNode new_head(-1);
  ListNode *curr = &new_head;
  for (size_t i = 0; i < ivec.size(); ++i)
  {
    curr->next = new ListNode(ivec[i]);
    curr = curr->next;
  }
  return new_head.next;
}

inline void
clear(ListNode *&head)
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
  ListNode *curr = head;
  while (curr->next->next)
    curr = curr->next;
  delete curr->next;
  curr->next = nullptr;
  clear(head);
}

inline void
clearTree(TreeNode *&node)
{
  if (!node)
    return;

  clearTree(node->left);
  clearTree(node->right);
  delete node;
  node = nullptr;
}

inline void
clear(TreeNode *&root)
{
  clearTree(root);
  cout << "Cleared!" << endl;
}

template <typename T>
inline void
printVec(const vector<T> &t_vec)
{
  for (size_t i = 0; i < t_vec.size(); ++i)
  {
    cout << t_vec[i];
    if (i != t_vec.size() - 1)
      cout << " ";
  }
  cout << endl;
}

template <typename T>
inline void
printVecVec(const vector<vector<T>> &t_vec_vec)
{
  for (size_t i = 0; i < t_vec_vec.size(); ++i)
  {
    for (size_t j = 0; j < t_vec_vec[i].size(); ++j)
    {
      cout << t_vec_vec[i][j];
      if (j != t_vec_vec[i].size() - 1)
        cout << " ";
    }
    cout << endl;
  }
}
