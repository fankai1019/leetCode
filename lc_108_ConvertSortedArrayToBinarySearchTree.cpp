#include <iostream>
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

// DFS construction
// TC: O(n) loop over every node.
// SC: O(nlogn) stack frame size is tree height, which is nlogn for a balanced tree
class Solution
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

int main()
{
    vector<int> ivec{-10, -3, 0, 5, 9};
    printVec(ivec);
    Solution s;
    TreeNode *result = s.sortedArrayToBST(ivec);
    print(result);
    clear(result);
    return 0;
}
