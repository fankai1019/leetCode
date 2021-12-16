#include <algorithm>
#include <iostream>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// struct TreeNode
// {
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(long x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//     long val;
//     TreeNode *left;
//     TreeNode *right;
// };

// DFS
// TC: O(n): every node is visited 3 times, so 3n
// SC: O(h): tree height
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int target_sum)
    {
        vector<vector<int>> result;
        vector<int> state;
        int sum = 0;
        dfs(result, state, sum, root, target_sum);
        return result;
    }

private:
    void dfs(vector<vector<int>> &result, vector<int> &state, int sum,
             TreeNode *root, int target_sum)
    {
        if (!root)
            return;

        state.push_back(root->val);
        sum += root->val;

        if (sum == target_sum && !root->left && !root->right)
            result.push_back(state);
        dfs(result, state, sum, root->left, target_sum);
        if (root->left)
            state.pop_back();
        dfs(result, state, sum, root->right, target_sum);
        if (root->right)
            state.pop_back();
    }
};

int main()
{
    int target_sum = 22;
    vector<int> ivec = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    BFS<TreeNode> tree(ivec);
    tree.print();
    Solution s;
    vector<vector<int>> result = s.pathSum(tree.root(), target_sum);
    printVecVec(result);

    return 0;
}
