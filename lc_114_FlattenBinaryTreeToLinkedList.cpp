#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(nlogn) tree depth is logn. It takes O(n) time to find the right most leaf
//     T(n) = 2T(n/2) + n
// SC: O(1) no additional list is created
class Solution
{
public:
  void flatten(TreeNode *root)
  {
    if (!root)
      return;

    flatten(root->left);
    flatten(root->right);
    if (!root->left && !root->right)
      return;
    else if (!root->left)
      return;
    else if (!root->right)
    {
      root->right = root->left;
      root->left = nullptr;
      return;
    }
    else
    {
      TreeNode *right_tmp = root->right;
      root->right = root->left;
      TreeNode *left_leaf = findRightMost(root->left);
      left_leaf->right = right_tmp;
      root->left = nullptr;
      return;
    }
  }

private:
  TreeNode *findRightMost(TreeNode *root)
  {
    if (!root)
      return root;
    while (root->right)
      root = root->right;
    return root;
  }
};

int main()
{
  vector<int> ivec = {1, 2, 5, 3, 4, -1, 6};
  BFS<TreeNode> bfs(ivec);
  BFS<TreeNode>::print(bfs.root());

  Solution s;
  s.flatten(bfs.root());
  BFS<TreeNode>::print(bfs.root());

  return 0;
}
