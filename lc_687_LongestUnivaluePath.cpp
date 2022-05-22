#include "utils.h"

using namespace std;

// DFS Bottom up
// TC: O(n) traverse the tree once
// SC: O(logn) stack frame size is n
class Solution
{
public:
    int longestUnivaluePath(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root);
        return result;
    }
    int dfs(TreeNode *root)
    {
        if (!root)
            return -1;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int left_edges = 0;
        int right_edges = 0;
        if (root->left && root->val == root->left->val)
            left_edges = left + 1;
        if (root->right && root->val == root->right->val)
            right_edges = right + 1;
        result = max(result, left_edges + right_edges);
        return max(left_edges, right_edges);
    }
    int result = INT_MIN;
};

int main()
{
    vector<int> ivec = {5, 4, 5, 1, 1, 5};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    int result = s.longestUnivaluePath(root);
    cout << result << endl;
    return 0;
}
