#include <algorithm>
#include <iostream>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// DFS cleaner code but slower
// TC: O(nh) binary search
// SC: O(h) recursion stack frame size is h
class Solution1
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode dummy;
        while (!isBST(root))
            dfs(root, &dummy);
    }

private:
    void dfs(TreeNode *root, TreeNode *parent, long mn = LONG_MIN, long mx = LONG_MAX)
    {
        if (!root)
            return;

        if (mn >= root->val || mx <= root->val)
            swap(root->val, parent->val);

        dfs(root->left, root, mn, root->val);
        dfs(root->right, root, root->val, mx);
    }

    bool isBST(TreeNode *root, long mn = LONG_MIN, long mx = LONG_MAX)
    {
        if (!root)
            return true;
        if (mn >= root->val || mx <= root->val)
            return false;
        if (!isBST(root->left, mn, root->val))
            return false;
        if (!isBST(root->right, root->val, mx))
            return false;
        return true;
    }
};

// DFS
// TC: O(n): all nodes are visited
// SC: O(h): depth of the tree
class Solution2
{
public:
    void recoverTree(TreeNode *root)
    {
        dfs(root);
        swap(first->val, second->val);
    }

private:
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        // 1 2 3 4 5
        // 1 3 2 4 5
        if (prev && prev->val >= root->val)
        {
            if (!first)
            {
                first = prev;
                second = root;
            }
            else
                second = root;
        }
        prev = root;
        dfs(root->right);
    }

    TreeNode *prev = nullptr;
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
};

// DFS
// follow up morris traversal
// TC: O(n): all nodes are visited
// SC: O(1): stack and recursion are not used
class Solution3
{
public:
    void recoverTree(TreeNode *root)
    {
        if (!root)
            return;
        head_.reset(new TreeNode(INT_MIN));
        head_->left = root;
        first_ = nullptr;
        second_ = nullptr;
        prev_ = head_.get();
        morrisInorder(root);
        swap(first_, second_);
    }

private:
    // Morris inorder traversal
    void morrisInorder(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                visit(curr);
                curr = curr->right;
            }
            else
            {
                TreeNode *predecessor = curr->left;
                while (predecessor->right && predecessor->right != curr)
                    predecessor = predecessor->right;
                if (!predecessor->right)
                {
                    predecessor->right = curr;
                    curr = curr->left;
                }
                else
                {
                    predecessor->right = nullptr;
                    visit(curr);
                    curr = curr->right;
                }
            }
        }
    }

    void swap(TreeNode *node1, TreeNode *node2)
    {
        if (node1 && node2)
        {
            int tmp = node1->val;
            node1->val = node2->val;
            node2->val = tmp;
        }
    }

    void visit(TreeNode *root)
    {
        if (!first_ && prev_->val > root->val)
            first_ = prev_;
        if (first_ && prev_->val > root->val)
            second_ = root;
        prev_ = root;
    }

    TreeNode *first_;
    TreeNode *second_;
    TreeNode *prev_;
    unique_ptr<TreeNode> head_;
};

int main()
{
    vector<int> ivec = {1, 3, null, null, 2};
    // vector<int> ivec = {3, 1, 4, null, null, 2};
    BFS<TreeNode> bfs(ivec);
    print(bfs.root());
    // Solution1 s;
    // Solution2 s;
    Solution3 s;
    s.recoverTree(bfs.root());
    print(bfs.root());

    return 0;
}