#include <algorithm>
#include <iostream>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// DFS
// TC: O(n): every node is visited 3 times, so 3n
// SC: O(h): tree height
class Solution1
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> nodes;
        traverse(root, 0, targetSum, nodes);
        return paths;
    }

private:
    void traverse(TreeNode *root, int val, int targetSum, vector<int> &path)
    {
        if (!root)
            return;
        path.push_back(root->val);
        int sum = val + root->val;
        if (!root->left && !root->right && sum == targetSum)
            paths.push_back(path);
        traverse(root->left, sum, targetSum, path);
        traverse(root->right, sum, targetSum, path);
        path.pop_back();
    }
    vector<vector<int>> paths;
};

// minor diff from solution1 with fewer arguments
// DFS
// TC: O(n): every node is visited 3 times, so 3n
// SC: O(h): tree height
class Solution2
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        backtracking(root, path, targetSum);
        return results;
    }

    void backtracking(TreeNode *root, vector<int> &path, int targetSum)
    {
        if (!root)
            return;

        path.push_back(root->val);

        if (!root->left && !root->right && root->val == targetSum)
            results.push_back(path);

        backtracking(root->left, path, targetSum - root->val);
        backtracking(root->right, path, targetSum - root->val);
        path.pop_back();
    }
    vector<vector<int>> results;
};

int main()
{
    int target_sum = 22;
    vector<int> ivec = {5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1};
    BFS<TreeNode> tree(ivec);
    print(tree.root());
    // Solution1 s;
    Solution2 s;
    vector<vector<int>> result = s.pathSum(tree.root(), target_sum);
    printVecVec(result);

    return 0;
}
