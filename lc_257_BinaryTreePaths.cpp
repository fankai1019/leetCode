#include <iostream>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

// DFS
// TC: O(n) iterate onces
// SC: O(height) stack frame size is h
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        if (!root)
            return result;

        string currStr;
        traverse(root, currStr, result);
        return result;
    }

private:
    void traverse(TreeNode *root, string currStr, vector<string> &result)
    {
        if (!root)
            return;
        currStr += to_string(root->val);
        if (!root->left && !root->right)
        {
            result.push_back(currStr);
            return;
        }
        currStr += "->";
        traverse(root->left, currStr, result);
        traverse(root->right, currStr, result);
    }
};

int main()
{
    vector<int> ivec = {1, 2, 3, null, 5};
    BFS<TreeNode> bfs(ivec);
    print(bfs.root());
    Solution s;
    vector<string> result = s.binaryTreePaths(bfs.root());
    printVec(result);
    return 0;
}
