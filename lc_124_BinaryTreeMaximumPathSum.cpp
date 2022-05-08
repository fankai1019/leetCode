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
    int maxPathSum(TreeNode *root)
    {
        sum_ = -INT_MAX;
        maxSum(root);
        return sum_;
    }

private:
    int maxSum(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_max = max(maxSum(root->left), 0);
        int right_max = max(maxSum(root->right), 0);
        int right_left_max = max(left_max, right_max) + root->val;
        int tmp = max(right_left_max, left_max + right_max + root->val);
        sum_ = max(sum_, tmp);
        return right_left_max;
    }

    int sum_;
};

int main()
{
    // vector<int> ivec = {1, 2, 3};
    vector<int> ivec = {-10, 9, 20, null, null, 15, 7};
    BFS<TreeNode> tree(ivec);
    Solution s;
    int result = s.maxPathSum(tree.root());
    cout << result << endl;

    return 0;
}
