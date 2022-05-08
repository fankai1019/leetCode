#include <iostream>
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

// DFS construction
// TC: O(n) loop over every node. Indexes are cached in an unordered map and it takes const time to get num of left nodes
// SC: O(h) stack frame size is tree height
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // 1 <= inorder.length <= 3000
        // inorder.length == postorder.length
        for (int i = 0; i < inorder.size(); ++i)
            mp[inorder[i]] = i;

        return helper(0, inorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }

private:
    TreeNode *helper(int inStart, int inEnd, int postStart, int postEnd, vector<int> &inorder, vector<int> &postorder)
    {
        if (inStart > inEnd)
            return nullptr;
        if (inStart == inEnd)
            return new TreeNode(inorder[inStart]);
        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);
        int rootIndex = mp[rootVal];
        int numLeftNodes = rootIndex - inStart;
        root->left = helper(inStart, rootIndex - 1, postStart, postStart + numLeftNodes - 1, inorder, postorder);
        root->right = helper(rootIndex + 1, inEnd, postStart + numLeftNodes, postEnd - 1, inorder, postorder);
        return root;
    }
    unordered_map<int, int> mp;
};

int main()
{
    Solution s;
    // vector<int> inorder = {9, 3, 15, 20, 7};
    // vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {1, 2, 3, 4};
    vector<int> postorder = {3, 2, 4, 1};
    printVec(inorder);
    printVec(postorder);
    TreeNode *result = s.buildTree(inorder, postorder);
    print(result);
    clear(result);
    return 0;
}
