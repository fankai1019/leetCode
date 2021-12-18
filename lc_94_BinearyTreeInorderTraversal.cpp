#include <algorithm>
#include <iostream>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// struct TreeNode
// {
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(long x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//     long val;
//     TreeNode *left;
//     TreeNode *right;
// };

// DFS
// TC: O(n): where h is the height of BST
// SC: O(h): depth of the tree
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> result;
        stack<pair<TreeNode *, int>> ns;

        ns.push(make_pair(root, 0));
        while (ns.size())
        {
            pair<TreeNode *, int> curr = ns.top();
            ns.pop();
            if (!curr.first)
                continue;
            if (curr.second == 0)
            {
                ns.push(make_pair(curr.first->right, 0));
                ns.push(make_pair(curr.first, 1));
                ns.push(make_pair(curr.first->left, 0));
            }
            else
            {
                result.push_back(curr.first->val);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> ivec = {1, -1, 2, 3};
    BFS<TreeNode> bfs(ivec);
    BFS<TreeNode>::print(bfs.root());
    Solution s;
    vector<int> result = s.inorderTraversal(bfs.root());
    printVec(result);

    return 0;
}