#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// DFS
// TC: O(n) need to iterate once
// SC: O(h) stack frame size is h
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        traverse(root, nullptr);
        return sum;
    }

private:
    void traverse(TreeNode *root, TreeNode *parent)
    {
        if (!root)
            return;
        if (!root->left && !root->right && parent && root == parent->left)
            sum += root->val;
        traverse(root->left, root);
        traverse(root->right, root);
    }
    int sum = 0;
};

int main()
{
    vector<int> ivec = {3, 9, 20, null, null, 15, 7};
    // vector<int> ivec = {1};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    int result = s.sumOfLeftLeaves(root);
    cout << result << endl;
    return 0;
}