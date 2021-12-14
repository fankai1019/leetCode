#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
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
// TC: O(n): every node is visited 3 times, so 3n
// SC: O(h): tree height
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        is_balanced_ = true;
        height(root);
        return is_balanced_;
    }

private:
    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        if (!is_balanced_) // if it is already unbalanced, just return
            return 0;

        int left = height(root->left);
        int right = height(root->right);
        int height = max(left, right) + 1;

        if (abs(left - right) >= 2)
            is_balanced_ = false;

        return height;
    }

    bool is_balanced_;
};

int main()
{
    // vector<int> ivec = {3, 9, 20, -1, -1, 15, 7};
    vector<int> ivec = {1, 2, 2, 3, 3, -1, -1, 4, 4};
    BFS<TreeNode> tree(ivec);
    tree.print();
    Solution s;
    bool result = s.isBalanced(tree.root());
    cout << result << endl;

    return 0;
}