#include "utils.h"
using namespace std;

// DFS + DP
// dp[root] = max(root->left->val + root->right->val, root->val + sum root->grandchildren->vals)
// TC: O(n) iterate all nodes once
// SC: O(n) recursion stack frame size is n
class Solution
{
public:
    int rob(TreeNode *root)
    {
        mp[nullptr] = 0;
        return dfs(root);
    }

private:
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        if (mp.count(root))
            return mp[root];
        int left_max = dfs(root->left);
        int right_max = dfs(root->right);
        int left_left_max = 0;
        int left_right_max = 0;
        if (root->left)
        {
            left_left_max = dfs(root->left->left);
            left_right_max = dfs(root->left->right);
        }
        int right_left_max = 0;
        int right_right_max = 0;
        if (root->right)
        {
            right_left_max = dfs(root->right->left);
            right_right_max = dfs(root->right->right);
        }
        int sum1 = root->val + left_left_max + left_right_max + right_left_max + right_right_max;
        int sum2 = left_max + right_max;

        if (sum1 > sum2)
            return mp[root] = sum1;
        return mp[root] = sum2;
    }

    unordered_map<TreeNode *, int> mp;
};

int main()
{
    // vector<int> ivec = {3, 2, 3, null, 3, null, 1};
    vector<int> ivec = {3, 4, 5, 1, 3, null, 1};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    int result = s.rob(root);
    cout << result << endl;
    return 0;
}