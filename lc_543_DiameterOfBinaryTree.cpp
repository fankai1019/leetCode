#include "utils.h"

using namespace std;

// DFS Bottom up
// TC: O(n) traverse the tree once
// SC: O(logn) stack frame size is n
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return result;
    }

private:
    int dfs(TreeNode *root)
    {
        if (!root)
            return -1;
        int left = dfs(root->left);
        int right = dfs(root->right);
        result = max(result, left + right + 2);
        return max(left, right) + 1;
    }

    int result = INT_MIN;
};

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    int result = s.diameterOfBinaryTree(root);
    cout << result << endl;
    return 0;
}
