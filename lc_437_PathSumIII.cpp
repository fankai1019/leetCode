#include <iostream>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

// Brute force
// TC: O(n^2) iterate onces
// SC: O(height) stack frame size is h
// Note: targetSum needs to be changed to long long, otherwise, integer overflow
class Solution1
{
public:
    int pathSum(TreeNode *root, long long targetSum)
    {
        if (!root)
            return 0;

        traverse(root, targetSum, result);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return result;
    }

private:
    void traverse(TreeNode *root, long long targetSum, int &result)
    {
        if (!root)
            return;
        if (root->val == targetSum)
            result += 1;
        traverse(root->left, targetSum - root->val, result);
        traverse(root->right, targetSum - root->val, result);
    }
    int result = 0;
};

// DFS prefix sum + backtracking
// TC: O(n) iterate onces
// SC: O(height) stack frame size is h
class Solution2
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;

        int result = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1; // for the matching from root. 0 can also be considered as the prefix of root
        traverse(root, 0, targetSum, prefixSum, result);
        return result;
    }

private:
    void traverse(TreeNode *root, long long currSum, int targetSum, unordered_map<int, int> &prefixSum, int &result)
    {
        if (!root)
            return;
        currSum += root->val;

        unordered_map<int, int>::iterator iter = prefixSum.find(currSum - targetSum);
        if (iter != prefixSum.end())
            result += iter->second;
        prefixSum[currSum]++;

        traverse(root->left, currSum, targetSum, prefixSum, result);
        traverse(root->right, currSum, targetSum, prefixSum, result);

        prefixSum[currSum]--;
    }
};

int main()
{
    vector<int> ivec = {10, 5, -3, 3, 2, null, 11, 3, -2, null, 1};
    int target = 8;
    BFS<TreeNode> bfs(ivec);
    print(bfs.root());
    // Solution1 s;
    Solution2 s;
    int result = s.pathSum(bfs.root(), target);
    cout << result << endl;
    return 0;
}
