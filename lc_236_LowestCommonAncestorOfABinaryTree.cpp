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

// DFS + backtracking
// TC: O(n): need to visit all nodes
// SC: O(h): tree height
class Solution1
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        found_p_ = false;
        found_q_ = false;
        traverse(root, p, q);
        TreeNode *result = nullptr;
        for (int i = 0; i < min(ppath_.size(), qpath_.size()); ++i)
        {
            if (ppath_[i] == qpath_[i])
                result = ppath_[i];
            else
                break;
        }
        return result;
    }

private:
    void traverse(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return;
        if (!found_p_)
            ppath_.push_back(root);
        if (!found_q_)
            qpath_.push_back(root);

        if (root == p)
            found_p_ = true;
        if (root == q)
            found_q_ = true;
        traverse(root->left, p, q);
        traverse(root->right, p, q);

        if (!found_p_)
            ppath_.pop_back();
        if (!found_q_)
            qpath_.pop_back();
    }
    bool found_p_;
    bool found_q_;
    vector<TreeNode *> ppath_;
    vector<TreeNode *> qpath_;
};

// DFS
// TC: O(n): need to visit all nodes
// SC: O(h): tree height
class Solution2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || p || q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        if (left)
            return left;
        return right;
    }
};

int main()
{
    vector<int> ivec = {3, 5, 1, 6, 2, 0, 8, null, null, 7, 4};
    BFS<TreeNode> tree(ivec);
    print(tree.root());
    TreeNode *p = tree.find(5);
    TreeNode *q = tree.find(1);
    // Solution1 s;
    Solution2 s;
    TreeNode *result = s.lowestCommonAncestor(tree.root(), p, q);
    cout << result->val << endl;

    return 0;
}
