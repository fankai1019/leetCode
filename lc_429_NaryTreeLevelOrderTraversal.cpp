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
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<Node *> nq;
        nq.push(root);
        while (nq.size())
        {
            size_t size = nq.size();
            vector<int> tmp;
            for (size_t i = 0; i < size; ++i)
            {
                Node *curr = nq.front();
                nq.pop();
                tmp.push_back(curr->val);
                for (size_t j = 0; j < curr->children.size(); ++j)
                {
                    if (curr->children[j])
                        nq.push(curr->children[j]);
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
};