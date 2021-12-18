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
// TC: O(n): all nodes are visited
// SC: O(h): depth of the tree
class Solution1
{
public:
    void recoverTree(TreeNode *root)
    {
        if (!root)
            return;
        head_.reset(new TreeNode(INT_MIN));
        prev_ = head_.get();
        first_ = nullptr;
        second_ = nullptr;
        inOrder(root);
        swap(first_, second_);
    }

private:
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        if (!first_ && root->val < prev_->val)
            first_ = prev_;
        if (first_ && root->val < prev_->val)
            second_ = root;
        prev_ = root;
        inOrder(root->right);
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

    TreeNode *first_;
    TreeNode *prev_;
    TreeNode *second_;
    unique_ptr<TreeNode> head_;
};

// DFS
// follow up morris traversal
// TC: O(n): all nodes are visited
// SC: O(1): stack and recursion are not used
class Solution2
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
    vector<int> ivec = {1, 3, -1, -1, 2};
    // vector<int> ivec = {3, 1, 4, -1, -1, 2};
    BFS<TreeNode> bfs(ivec);
    BFS<TreeNode>::print(bfs.root());
    // Solution1 s;
    Solution2 s;
    s.recoverTree(bfs.root());
    BFS<TreeNode>::print(bfs.root());

    return 0;
}