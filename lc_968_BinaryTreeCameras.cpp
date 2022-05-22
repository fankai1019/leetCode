#include "utils.h"

using namespace std;

// DFS Bottom up
// TC: O(n) traverse the tree once
// SC: O(logn) stack frame size is n
class Solution
{
public:
    enum Status
    {
        Leaf = 0,
        ParentWithCamera,
        Covered
    };
    int minCameraCover(TreeNode *root)
    {
        Status status = dfs(root);
        if (status == Leaf)
            return result + 1;
        return result;
    }

private:
    Status dfs(TreeNode *root)
    {
        if (!root)
            return Covered;
        Status left = dfs(root->left);
        Status right = dfs(root->right);

        if (left == Leaf || right == Leaf)
        {
            result++;
            return ParentWithCamera;
        }

        if (left == ParentWithCamera || right == ParentWithCamera)
            return Covered;

        return Leaf;
    }

    int result = 0;
};

int main()
{
    vector<int> ivec = {0, 0, null, 0, 0};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    int result = s.minCameraCover(root);
    cout << result << endl;
    return 0;
}
