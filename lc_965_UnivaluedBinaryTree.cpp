#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// DFS Bottome up
// TC: O(n) need to iterate once
// SC: O(n) stack frame size is n
class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        int val = root->val;
        return traverse(root, val);
    }

private:
    bool traverse(TreeNode *root, int val)
    {
        if (!root)
            return true;
        if (root->val != val)
            return false;

        bool left = traverse(root->left, val);
        bool right = traverse(root->right, val);

        return left && right;
    }
};

int main()
{
    vector<int> ivec = {1, 1, 0};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    bool result = s.isUnivalTree(root);
    cout << result << endl;

    return 0;
}