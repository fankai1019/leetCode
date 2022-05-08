#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// DFS
// TC: O(m*n) need to iterate once
// SC: O(m*n) stack frame size is n
class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        result_ = false;
        traverse(root, subRoot);
        return result_;
    }

private:
    void traverse(TreeNode *root, TreeNode *subRoot)
    {
        if (!root || result_)
            return;
        if (isSame(root, subRoot))
        {
            result_ = true;
            return;
        }
        traverse(root->left, subRoot);
        traverse(root->right, subRoot);
    }
    bool isSame(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (p && !q)
            return false;
        if (!p && q)
            return false;
        if (p->val != q->val)
            return false;

        bool left = isSame(p->left, q->left);
        bool right = isSame(p->right, q->right);
        return left && right;
    }
    bool result_;
};

int main()
{
    vector<int> ivec1 = {3, 4, 5, 1, 2};
    vector<int> ivec2 = {4, 1, 2};
    BFS<TreeNode> bfs1(ivec1);
    BFS<TreeNode> bfs2(ivec2);
    TreeNode *root1 = bfs1.root();
    TreeNode *root2 = bfs2.root();
    print(root1);
    print(root2);
    Solution s;
    bool result = s.isSubtree(root1, root2);
    cout << result << endl;

    return 0;
}