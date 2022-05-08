#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

// DFS Bottom up
// TC: O(n) iterate onces
// SC: O(height)
class Solution
{
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        TreeNode new_root;
        new_root.left = root;
        traverse(root, target, &new_root, 0);
        return new_root.left;
    }

private:
    void traverse(TreeNode *root, int target, TreeNode *parent, int left0right1)
    {
        if (!root)
            return;
        traverse(root->left, target, root, 0);
        traverse(root->right, target, root, 1);
        if (root->val == target && !root->left && !root->right)
        {
            if (!left0right1)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
    }
};

int main()
{
    vector<int> ivec = {1, 2, 3, 2, null, 2, 4};
    int target = 2;
    BFS<TreeNode> bfs(ivec);
    print(bfs.root());
    Solution s;
    TreeNode *result = s.removeLeafNodes(bfs.root(), target);
    print(result);
    return 0;
}
