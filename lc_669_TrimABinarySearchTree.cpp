#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

// DFS Bottom up
// TC: O(n) iterate onces
// SC: O(n) stack frame size might be n
class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        TreeNode new_head;
        new_head.left = root;
        traverse(root, low, high, &new_head, 0);
        return new_head.left;
    }

private:
    void traverse(TreeNode *root, int low, int high, TreeNode *parent, int left0right1)
    {
        if (!root)
            return;

        traverse(root->left, low, high, root, 0);
        traverse(root->right, low, high, root, 1);

        if (root->val < low)
        {
            if (!left0right1)
                parent->left = root->right;
            else
                parent->right = root->right;
        }
        else if (root->val > high)
        {
            if (!left0right1)
                parent->left = root->left;
            else
                parent->right = root->left;
        }
    }
};

int main()
{
    vector<int> ivec = {1, 0, 2};
    int low = 1;
    int high = 2;
    BFS<TreeNode> bfs(ivec);
    BFS<TreeNode>::print(bfs.root());
    Solution s;
    TreeNode *result = s.trimBST(bfs.root(), low, high);
    BFS<TreeNode>::print(result);
    return 0;
}
