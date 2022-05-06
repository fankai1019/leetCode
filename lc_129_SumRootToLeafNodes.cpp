#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

#include "utils.h"
using namespace std;

// DFS
// TC: O(n): every node is visited 3 times, so 3n
// SC: O(h): tree hight
class Solution1
{
public:
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        sum_ = 0;
        sumNumbers(root, 0);
        return sum_;
    }

private:
    void sumNumbers(TreeNode *root, int num)
    {
        if (!root)
            return;

        num *= 10;
        num += root->val;
        if (!root->left && !root->right)
        {
            sum_ += num;
            return;
        }

        sumNumbers(root->left, num);
        sumNumbers(root->right, num);
    }
    int sum_;
};

// Written in a slightly differnet way
// DFS
// TC: O(n): every node is visited 3 times, so 3n
// SC: O(h): tree hight
class Solution2
{
public:
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        return traverse(root, 0);
    }

private:
    int traverse(TreeNode *root, int parentVal)
    {
        if (!root)
            return 0;
        int val = parentVal * 10 + root->val;
        if (!root->left && !root->right)
            return val;
        int left = traverse(root->left, val);
        int right = traverse(root->right, val);
        return left + right;
    }
};

int main()
{
    vector<int> ivec = {1, 2, 3};
    // vector<int> ivec = {4, 9, 0, 5, 1};
    BFS<TreeNode> tree(ivec);
    // Solution1 s;
    Solution2 s;
    int result = s.sumNumbers(tree.root());
    cout << result << endl;

    return 0;
}
