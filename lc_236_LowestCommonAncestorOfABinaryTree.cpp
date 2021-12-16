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
        TreeNode *result;
        if (!root)
            return nullptr;
        found_p_ = false;
        found_q_ = false;
        vector<TreeNode *> p_an;
        vector<TreeNode *> q_an;
        helper(root, p, q, p_an, q_an);
        size_t size = p_an.size() <= q_an.size() ? p_an.size() : q_an.size();
        size_t count = 0;
        for (size_t i = 0; i < size; ++i)
        {
            if (p_an[i] != q_an[i])
            {
                count = i;
                break;
            }
        }
        if (count)
            return p_an[count - 1];
        else
            return p_an[size - 1];
    }

private:
    void helper(TreeNode *root, TreeNode *p, TreeNode *q,
                vector<TreeNode *> &p_an, vector<TreeNode *> &q_an)
    {
        if (!root || (found_p_ && found_q_))
            return;
        if (!found_p_)
            p_an.push_back(root);
        if (!found_q_)
            q_an.push_back(root);
        if (root == p)
            found_p_ = true;
        if (root == q)
            found_q_ = true;
        helper(root->left, p, q, p_an, q_an);
        if (root->left)
        {
            if (!found_p_)
                p_an.pop_back();
            if (!found_q_)
                q_an.pop_back();
        }
        helper(root->right, p, q, p_an, q_an);
        if (root->right)
        {
            if (!found_p_)
                p_an.pop_back();
            if (!found_q_)
                q_an.pop_back();
        }
    }
    bool found_p_;
    bool found_q_;
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
    int target_sum = 22;
    vector<int> ivec = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    BFS<TreeNode> tree(ivec);
    tree.print();
    TreeNode *p = tree.find(5);
    TreeNode *q = tree.find(1);
    // Solution1 s;
    Solution2 s;
    TreeNode *result = s.lowestCommonAncestor(tree.root(), p, q);
    cout << result->val << endl;

    return 0;
}
