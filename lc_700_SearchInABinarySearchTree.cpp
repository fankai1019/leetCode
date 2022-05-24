#include "utils.h"
using namespace std;

// Binary search
// TC: O(logn) binary search
// SC: O(h) recursion stack frame size is h
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return nullptr;
        if (root->val == val)
            return root;
        if (root->val > val)
            return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};

int main()
{
    vector<int> ivec = {4, 2, 7, 1, 3};
    int val = 2;
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    TreeNode *result = s.searchBST(root, val);
    print(result);
    return 0;
}