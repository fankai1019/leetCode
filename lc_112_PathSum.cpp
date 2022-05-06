#include <algorithm>
#include <iostream>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// DFS + backtracking
// TC: O(n): all nodes are visited
// SC: O(h): depth of the tree
class Solution1
{
public:
    bool hasPathSum(TreeNode *root, int target_sum)
    {
        if (!root)
            return false;
        result_ = false;
        int val = 0;
        helper(root, target_sum, val);
        return result_;
    }

private:
    void helper(TreeNode *root, int target_sum, int &val)
    {
        if (result_ || !root)
            return;

        val += root->val;
        if (!root->left && !root->right)
        {
            if (target_sum == val)
            {
                result_ = true;
                return;
            }
        }
        helper(root->left, target_sum, val);
        if (root->left)
            val -= root->left->val;
        helper(root->right, target_sum, val);
        if (root->right)
            val -= root->right->val;
    }
    bool result_;
};

// DFS
// TC: O(n): all nodes are visited
// SC: O(h): depth of the tree
class Solution2
{
public:
    bool hasPathSum(TreeNode *root, int target_sum)
    {
        if (!root)
            return false;
        if (!root->left && !root->right && root->val == target_sum)
            return true;
        return hasPathSum(root->left, target_sum - root->val) || hasPathSum(root->right, target_sum - root->val);
    }
};

// DFS
// TC: O(n) need to iterate once
// SC: O(height) stack frame size is height
class Solution3
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        return traverse(root, 0, targetSum);
    }

private:
    bool traverse(TreeNode *root, int val, int targetSum)
    {
        if (!root)
            return false;
        int sum = val + root->val;
        if (!root->left && !root->right && sum == targetSum)
            return true;
        bool left = traverse(root->left, sum, targetSum);
        bool right = traverse(root->right, sum, targetSum);

        return left || right;
    }
};

int main()
{
    int target_sum = 22;
    vector<int> ivec = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    BFS<TreeNode> bfs(ivec);
    BFS<TreeNode>::print(bfs.root());
    // Solution1 s;
    // Solution2 s;
    Solution3 s;
    bool result = s.hasPathSum(bfs.root(), target_sum);
    cout << result << endl;

    return 0;
}