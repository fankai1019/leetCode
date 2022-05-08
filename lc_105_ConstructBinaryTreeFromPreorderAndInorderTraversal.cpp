#include <iostream>
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

// DFS construction
// TC: O(n^2) worst case loop over every node and finding num of left nodes takes linear time in each recursion
//     preorder[1, 2, 3, 4] inorder[4, 3, 2, 1], caching node indexes can make TC linear
// SC: O(h) stack frame size is tree height
class Solution1
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 1 <= preorder.length <= 3000
        // preorder.length == inorder.length
        return helper(0, preorder.size() - 1, 0, preorder.size() - 1, preorder, inorder);
    }

private:
    TreeNode *helper(int preStart, int preEnd, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder)
    {
        if (preStart > preEnd)
            return nullptr;
        if (preStart == preEnd)
            return new TreeNode(preorder[preStart]);

        TreeNode *root = new TreeNode(preorder[preStart]);
        int numLeftNodes = 0;
        while (inorder[inStart + numLeftNodes] != preorder[preStart])
            numLeftNodes++;
        root->left = helper(preStart + 1, preStart + numLeftNodes, inStart, inStart + numLeftNodes - 1, preorder, inorder);
        root->right = helper(preStart + 1 + numLeftNodes, preEnd, inStart + numLeftNodes + 1, inEnd, preorder, inorder);
        return root;
    }
};

// DFS construction
// TC: O(n) loop over every node. Indexes are cached in an unordered map and it takes const time to get num of left nodes
// SC: O(h) stack frame size is tree height
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/
class Solution2
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 1 <= preorder.length <= 3000
        // preorder.length == inorder.length
        for (int i = 0; i < inorder.size(); ++i)
            mp[inorder[i]] = i;
        return helper(0, preorder.size() - 1, 0, preorder.size() - 1, preorder, inorder);
    }

private:
    TreeNode *helper(int preStart, int preEnd, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder)
    {
        if (preStart > preEnd)
            return nullptr;
        if (preStart == preEnd)
            return new TreeNode(preorder[preStart]);

        TreeNode *root = new TreeNode(preorder[preStart]);
        int numLeftNodes = mp[preorder[preStart]] - inStart;
        root->left = helper(preStart + 1, preStart + numLeftNodes, inStart, inStart + numLeftNodes - 1, preorder, inorder);
        root->right = helper(preStart + 1 + numLeftNodes, preEnd, inStart + numLeftNodes + 1, inEnd, preorder, inorder);
        return root;
    }
    unordered_map<int, int> mp;
};

int main()
{
    // Solution1 s;
    Solution2 s;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    printVec(preorder);
    printVec(inorder);
    TreeNode *result = s.buildTree(preorder, inorder);
    print(result);
    clear(result);
    return 0;
}
