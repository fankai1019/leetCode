#include "utils.h"
using namespace std;

// Binary search
// TC: O(h) binary search
// SC: O(h) recursion stack frame size is h
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        dfs(root, val);
        return root;
    }

private:
    void dfs(TreeNode *&root, int val)
    {
        if (!root)
        {
            root = new TreeNode(val);
            return;
        }

        if (val < root->val)
            dfs(root->left, val);
        else
            dfs(root->right, val);
    }
};

int main()
{
    vector<int> ivec = {4, 2, 7, 1, 3};
    int val = 5;
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    TreeNode *result = s.insertIntoBST(root, val);
    print(result);
    return 0;
}