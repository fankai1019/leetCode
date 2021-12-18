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
// TC: O(h): where h is the height of BST
// SC: O(h): for recursive stack
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;

        head.reset(new TreeNode);
        head->left = root;

        TreeNode *curr = root;
        TreeNode *parent = head.get();
        while (curr && curr->val != key)
        {
            if (curr->val < key)
            {
                parent = curr;
                curr = curr->right;
            }
            else if (curr->val > key)
            {
                parent = curr;
                curr = curr->left;
            }
        }
        if (!curr)
            return root;

        if (!curr->left || !curr->right)
        {
            TreeNode **child = parent->left == curr ? &parent->left : &parent->right;
            if (curr->left)
                *child = curr->left;
            else
                *child = curr->right;
        }
        else
        {
            // two children
            // replace it with the smallest node in its right subtree
            TreeNode *smallest = curr->right;
            TreeNode *smallest_parent = curr;
            while (smallest && smallest->left)
            {
                smallest_parent = smallest;
                smallest = smallest->left;
            }
            curr->val = smallest->val;
            TreeNode **child = smallest_parent->left == smallest
                                   ? &smallest_parent->left
                                   : &smallest_parent->right;
            *child = smallest->right;
        }
        return head->left;
    }

private:
    unique_ptr<TreeNode> head;
};

int main()
{
    int key = 3;
    // vector<int> ivec = {5, 3, 6, 2, 4, -1, 7};
    // vector<int> ivec = {3, 2, 5, -1, -1, 4, 10, -1, -1, 8, 15, 7};
    vector<int> ivec = {5, 3, 6, 2, 4, -1, 7};
    BFS<TreeNode> tree(ivec);
    BFS<TreeNode>::print(tree.root());
    Solution s;
    TreeNode *result = s.deleteNode(tree.root(), key);
    BFS<TreeNode>::print(result);
    cout << result->val << endl;

    return 0;
}
