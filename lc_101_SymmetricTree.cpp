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
// SC: O(n) stack frame size is n
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return traverse(root->left, root->right);
    }

private:
    bool traverse(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p && q)
            return false;
        if (p && !q)
            return false;
        if (p->val != q->val)
            return false;

        bool result1 = traverse(p->left, q->right);
        bool result2 = traverse(p->right, q->left);
        return result1 && result2;
    }
};

int main()
{
    vector<int> ivec = {1, 2, 2, 3, 4, 4, 3};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    bool result = s.isSymmetric(root);
    cout << result << endl;

    return 0;
}