#include "utils.h"
using namespace std;

// DFS
// TC: O(n) need to iterate once
// SC: O(h) stack frame size is h
class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        traverse(root);
        return diff;
    }

private:
    void traverse(TreeNode *root)
    {
        if (!root)
            return;
        traverse(root->left);
        diff = min(diff, abs(root->val - prev));
        prev = root->val;
        traverse(root->right);
    }
    int diff = INT_MAX;
    int prev = INT_MAX;
};

int main()
{
    vector<int> ivec = {4, 2, 6, 1, 3};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    int result = s.getMinimumDifference(root);
    cout << result << endl;
    return 0;
}