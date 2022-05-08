#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// Recursive
// TC: O(n) each node is pushed and poped once
// SC: O(n) worst stack frame size is n
class Solution1
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        postorder(root, result);
        return result;
    };

private:
    void postorder(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
};

// Iterative
// TC: O(n) each node is pushed and poped once
// SC: O(n) a stack is needed
class Solution2
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode *> nstack;
        TreeNode *curr = root;
        TreeNode *prev_poped = nullptr;
        while (curr || nstack.size())
        {
            while (curr)
            {
                nstack.push(curr);
                curr = curr->left;
            }

            TreeNode *node = nstack.top();
            if (node->right && node->right != prev_poped)
                curr = node->right;
            else
            {
                result.push_back(node->val);
                nstack.pop();
                prev_poped = node;
            }
        }
        return result;
    };
};

int main()
{
    vector<int> ivec = {1, null, 2, 3};
    BFS<TreeNode> bfs(ivec);
    print(bfs.root());
    // Solution1 s;
    Solution2 s;
    vector<int> result = s.postorderTraversal(bfs.root());
    printVec(result);
    return 0;
}
