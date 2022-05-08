#include <iostream>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

// DFS: simiar to the idea of lowest ancestor of a binary tree(235)
// TC: O(n) find lowest nodes and lca iterative call
// SC: O(height) + O(leaves) stack frame size is h, need a vector to store leaves
class Solution1
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        vector<TreeNode *> leaves;
        findLowestLeaves(root, leaves);
        if (leaves.size() == 1)
            return leaves[0];
        return lca(root, leaves);
    }

private:
    TreeNode *lca(TreeNode *root, vector<TreeNode *> &leaves)
    {
        if (!root)
            return root;
        for (int i = 0; i < leaves.size(); ++i)
            if (root == leaves[i])
                return root;

        TreeNode *left = lca(root->left, leaves);
        TreeNode *right = lca(root->right, leaves);
        if (left && right)
            return root;
        if (left)
            return left;
        return right;
    }

    void findLowestLeaves(TreeNode *root, vector<TreeNode *> &leaves)
    {
        if (!root)
            return;
        queue<TreeNode *> nq;
        nq.push(root);
        while (nq.size())
        {
            leaves.clear();
            int size = nq.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = nq.front();
                nq.pop();
                leaves.push_back(node);
                if (node->left)
                    nq.push(node->left);
                if (node->right)
                    nq.push(node->right);
            }
        }
    }
};

// DFS
// TC: O(n^2) find node depth in each iterative call, worst case O(n^2) when the tree is a list
// SC: O(height) stack frame size is h, need a vector to store leaves
class Solution2
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        if (!root)
            return root;

        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        if (left_depth == right_depth)
            return root;

        if (left_depth > right_depth)
            return lcaDeepestLeaves(root->left);
        return lcaDeepestLeaves(root->right);
    }

private:
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;

        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        if (left_depth == right_depth)
            return left_depth + 1;
        else
            return max(left_depth, right_depth) + 1;
    }
};

// DFS 2 iterative calls
// TC: O(n) store the node depth into an unordered map
// SC: O(height) stack frame size is h, need a vector to store leaves
class Solution3
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        dm_[nullptr] = 0;
        depth(root);
        return traverse(root);
    }

private:
    TreeNode *traverse(TreeNode *root)
    {
        if (!root)
            return root;

        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        if (left_depth == right_depth)
            return root;

        if (left_depth > right_depth)
            return traverse(root->left);
        return traverse(root->right);
    }

    int depth(TreeNode *root)
    {
        if (dm_.count(root))
            return dm_[root];

        if (!root)
            return 0;

        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        if (left_depth == right_depth)
            dm_[root] = left_depth + 1;
        else
            dm_[root] = max(left_depth, right_depth) + 1;
        return dm_[root];
    }
    unordered_map<TreeNode *, int> dm_;
};

// DFS 1 iterative calls, bottom up
// TC: O(n) store both node depth and ancestor into an unordered map
// SC: O(height) stack frame size is h, need a vector to store leaves
class Solution4
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        m[nullptr].first = nullptr;
        m[nullptr].second = 0;
        traverse(root);
        return m[root].first;
    }

private:
    void traverse(TreeNode *root)
    {
        if (!root)
            return;

        traverse(root->left);
        traverse(root->right);
        int left_depth = m[root->left].second;
        int right_depth = m[root->right].second;

        if (left_depth == right_depth)
        {
            m[root].first = root;
            m[root].second = left_depth + 1;
        }
        else if (left_depth > right_depth)
        {
            m[root].first = m[root->left].first;
            m[root].second = left_depth + 1;
        }
        else
        {
            m[root].first = m[root->right].first;
            m[root].second = right_depth + 1;
        }
    }

    unordered_map<TreeNode *, pair<TreeNode *, int>> m;
};

int main()
{
    vector<int> ivec = {3, 5, 1, 6, 2, 0, 8, null, null, 7, 4};
    BFS<TreeNode> bfs(ivec);
    print(bfs.root());
    // Solution1 s;
    // Solution2 s;
    // Solution3 s;
    Solution4 s;
    TreeNode *result = s.lcaDeepestLeaves(bfs.root());
    if (result)
        cout << result->val << endl;
    return 0;
}
