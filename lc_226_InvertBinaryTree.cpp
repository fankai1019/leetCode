#include "utils.h"

using namespace std;

// DFS Bottom up
// TC: O(n) iterated over all nodes
// SC: O(h) stack frame size is height
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;

        invertTree(root->left);
        invertTree(root->right);

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};

int main()
{
    vector<int> ivec = {4, 2, 7, 1, 3, 6, 9};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    TreeNode *result = s.invertTree(root);
    print(result);
    return 0;
}
