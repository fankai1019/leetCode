#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// DFS
// TC: O(n) need to iterate once. Unordered map is traversed twice
// SC: O(h) stack frame size is h and an unordered map is needed
class Solution
{
public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        traverse(root);
        int freq = INT_MIN;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second > freq)
                freq = iter->second;
        }
        vector<int> results;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second == freq)
                results.push_back(iter->first);
        }
        return results;
    }

private:
    int traverse(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        int sum = root->val + left + right;
        mp[sum]++;
        return sum;
    }
    unordered_map<int, int> mp;
};

int main()
{
    vector<int> ivec = {5, 2, -3};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    vector<int> results = s.findFrequentTreeSum(root);
    printVec(results);
    return 0;
}