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
// TC: O(n): every node is visited m times, so mn and m is a constant
// SC: O(n): need a vector to store all nodes
class Solution1
{
public:
    Solution1() : is_binary_(true) {}
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;

        if (!is_binary_)
            return false;

        long long right_min = minValue(root->right);
        long long left_max = maxValue(root->left);

        if (!is_binary_)
            return false;
        if (right_min <= root->val)
            return false;
        if (left_max >= root->val)
            return false;
        is_binary_ = is_binary_ && isValidBST(root->left);
        if (!is_binary_)
            return false;
        is_binary_ = is_binary_ && isValidBST(root->right);
        if (!is_binary_)
            return false;
        return is_binary_;
    }

private:
    long long minValue(TreeNode *root)
    {
        if (!root)
            return LLONG_MAX;

        long left_min = minValue(root->left);
        long right_min = minValue(root->right);
        if (right_min <= root->val)
            is_binary_ = false;
        return min(min(left_min, right_min), static_cast<long>(root->val));
    }

    long long maxValue(TreeNode *root)
    {
        if (!root)
            return -LLONG_MAX;

        long left_max = maxValue(root->left);
        long right_max = maxValue(root->right);
        if (left_max >= root->val)
            is_binary_ = false;
        return max(max(left_max, right_max), static_cast<long>(root->val));
    }

    bool is_binary_;
};

// DFS
// TC: O(n): every node is visited 3 times, so 3n
// SC: O(n): need a vector to store all nodes
class Solution2
{
public:
    bool isValidBST(TreeNode *root)
    {
        vector<int> result;
        inOrder(root, result);
        for (size_t i = 0; i < result.size() - 1; ++i)
            if (result[i + 1] <= result[i])
                return false;
        return true;
    }

private:
    void inOrder(TreeNode *root, vector<int> &ivec)
    {
        if (!root)
            return;
        inOrder(root->left, ivec);
        ivec.push_back(root->val);
        inOrder(root->right, ivec);
    }
};

// For the recursive solution, we set a lower bound and a upper bound for the tree.
// When we recurse on the left subtree, the upper bound becomes the value of its root.
// When we recurse on the right subtree, the lower bound becomes the value of its root.
// DFS
// TC: O(n): every node is visited 3 times, so 3n
// SC: O(h): tree height
class Solution3
{
public:
    bool isValidBST(TreeNode *root)
    {
        return helper(root, -LONG_MAX, LONG_MAX);
    }

private:
    bool helper(TreeNode *root, long min, long max)
    {
        if (!root)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
};

int main()
{
    vector<int> ivec = {2, 1, 3};
    // vector<int> ivec = {2147483647};
    // vector<int> ivec = {5, 1, 4, -1, -1, 3, 6};
    // vector<int> ivec = {3, -1, 30, 10, -1, -1, 15, -1, 45};
    BFS<TreeNode> tree(ivec);
    // Solution1 s;
    // Solution2 s;
    Solution3 s;
    bool result = s.isValidBST(tree.root());
    cout << result << endl;

    return 0;
}
