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
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };

// DFS
// TC: O(n): every node is visited 3 times, so 3n
// SC: O(h): tree hight
class Solution
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

int main()
{
    vector<int> ivec = {1, 2, 3};
    // vector<int> ivec = {4, 9, 0, 5, 1};
    BFS<TreeNode> tree(ivec);
    Solution s;
    int result = s.sumNumbers(tree.root());
    cout << result << endl;

    return 0;
}
