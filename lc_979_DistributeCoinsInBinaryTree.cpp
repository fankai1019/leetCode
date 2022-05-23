#include "utils.h"
using namespace std;

// DFS Bottom up
// Traverse children first and then return the balance of coins
// TC: O(n) iterate all nodes once
// SC: O(h) recursion stack frame size is h
class Solution
{
public:
    int distributeCoins(TreeNode *root)
    {
        dfs(root);
        return moves;
    }

private:
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        moves += abs(left) + abs(right);
        int balance = root->val + left + right - 1;
        return balance;
    }
    int moves = 0;
};

int main()
{
    vector<int> ivec = {0, 3, 0};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    int result = s.distributeCoins(root);
    cout << result << endl;
    return 0;
}