#include "utils.h"
using namespace std;

// DFS
// TC: O(n) need to iterate once. Unordered map is traversed twice
// SC: O(h) stack frame size is h and an unordered map is needed
class Solution1
{
public:
    vector<int> findMode(TreeNode *root)
    {
        traverse(root);
        vector<int> result;
        int mode = 0;
        int freq = INT_MIN;
        for (unordered_map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second > freq)
                freq = iter->second;
        }

        for (unordered_map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second == freq)
                result.push_back(iter->first);
        }
        return result;
    }

private:
    void traverse(TreeNode *root)
    {
        if (!root)
            return;

        mp[root->val]++;
        traverse(root->left);
        traverse(root->right);
    }
    unordered_map<int, int> mp;
};

// Follow up question:
// Could you do that without using any extra space?
// (Assume that the implicit stack space incurred due to recursion does not count).
// DFS
// TC: O(n) need to iterate twice.
// SC: O(1) if stack frame size does not count, then SC is linear
class Solution2
{
public:
    vector<int> findMode(TreeNode *root)
    {
        traverse1(root);
        freq = 0;
        prev = INT_MIN;
        traverse2(root);
        return result;
    }

private:
    void traverse1(TreeNode *root)
    {
        if (!root)
            return;

        traverse1(root->left);
        cout << "val: " << root->val << endl;
        if (prev != root->val)
        {
            freq = 1;
            prev = root->val;
        }
        else
        {
            freq++;
        }
        max_freq = max(max_freq, freq);
        traverse1(root->right);
    }
    void traverse2(TreeNode *root)
    {
        if (!root)
            return;
        traverse2(root->left);
        if (prev != root->val)
        {
            freq = 1;
            prev = root->val;
        }
        else
        {
            freq++;
        }
        if (freq == max_freq)
            result.push_back(root->val);
        traverse2(root->right);
    }

    int freq = 0;
    int max_freq = 0;
    int prev = INT_MIN;
    vector<int> result;
};

int main()
{
    vector<int> ivec = {1, null, 2, 2};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    // Solution1 s;
    Solution2 s;
    vector<int> results = s.findMode(root);
    printVec(results);
    return 0;
}