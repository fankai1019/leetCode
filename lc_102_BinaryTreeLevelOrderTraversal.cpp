#include <iostream>
#include <queue>
#include <vector>
#include <memory>

#include "utils.h"
using namespace std;

// struct TreeNode
// {
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   int val;
//   TreeNode *left;
//   TreeNode *right;
// };

// TC: O(n): every node is pushed and poped once, so 2n
// SC: O(n): at worst case you need to hold all vertices in the queue
class Solution
{
public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    if (!root)
      return {};

    vector<vector<int>> result;
    queue<TreeNode *> tq;
    tq.push(root);
    while (!tq.empty())
    {
      size_t size = tq.size();
      vector<int> level;
      for (size_t i = 0; i < size; ++i)
      {
        TreeNode *curr = tq.front();
        tq.pop();
        level.push_back(curr->val);
        if (curr->left)
          tq.push(curr->left);
        if (curr->right)
          tq.push(curr->right);
      }
      result.push_back(level);
    }
    return result;
  }
};

int main()
{
  vector<int> ivec = {3, 9, 30, -1, -1, 15, 7};
  BFS<TreeNode> bfs(ivec);
  Solution s;
  vector<vector<int>> result = s.levelOrder(bfs.root());
  for (const auto &ivec : result)
  {
    for (size_t i = 0; i < ivec.size(); ++i)
      if (i != ivec.size() - 1)
        cout << ivec[i] << " ";
      else
        cout << ivec[i];
    cout << endl;
  }

  return 0;
}
