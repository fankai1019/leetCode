#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// DFS Bottom up
// TC: O(n) need to iterate once
// SC: O(n) stack frame size is n
class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        TreeNode new_head;
        new_head.left = root;
        hasOne(&new_head);
        return new_head.left;
    }

private:
    bool hasOne(TreeNode *root)
    {
        if (!root)
            return false;
        bool left_has_one = hasOne(root->left);
        bool right_has_one = hasOne(root->right);
        if (!left_has_one)
            root->left = nullptr;
        if (!right_has_one)
            root->right = nullptr;
        if (right_has_one || left_has_one)
            return true;
        return root->val == 1;
    }
};

int main()
{
    vector<int> ivec = {1, -1, 0, 0, 1};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    BFS<TreeNode>::print(root);
    Solution s;
    TreeNode *result = s.pruneTree(root);
    BFS<TreeNode>::print(result);

    return 0;
}