#include <iostream>
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

// DFS construction
// TC: O(n) loop over every node.
// SC: O(logn) stack frame size is tree height, which is logn for a balanced tree
class Solution1
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(0, nums.size() - 1, nums);
    }

private:
    TreeNode *helper(int start, int end, const vector<int> &nums)
    {
        if (start > end)
            return nullptr;
        if (start == end)
            return new TreeNode(nums[start]);
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(start, mid - 1, nums);
        root->right = helper(mid + 1, end, nums);
        return root;
    }
};

// Redid solution
// TC: O(n) loop over every node.
// SC: O(logn) stack frame size is tree height, which is logn for a balanced tree
class Solution2
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return dfs(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *dfs(const vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(nums, start, mid - 1);
        root->right = dfs(nums, mid + 1, end);
        return root;
    }
};

int main()
{
    vector<int> ivec{-10, -3, 0, 5, 9};
    printVec(ivec);
    // Solution1 s;
    Solution2 s;
    TreeNode *result = s.sortedArrayToBST(ivec);
    print(result);
    clear(result);
    return 0;
}
