#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

#include "utils.h"
using namespace std;

// Reverse
// TC: O(n): every node is pushed and poped once, so 2n
// SC: O(n): in worst case you need to hold all vertices in the queue
class Solution1
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<TreeNode *> tq;
        tq.push(root);
        while (tq.size())
        {
            size_t size = tq.size();
            vector<int> ivec;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *curr = tq.front();
                tq.pop();
                ivec.push_back(curr->val);
                if (curr->left)
                    tq.push(curr->left);
                if (curr->right)
                    tq.push(curr->right);
            }
            result.push_back(ivec);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// BFS + DFS
// TC: O(n): bfs traverse once to calculate max depth then dfs traverse once
// SC: O(n): queue and stack frame size are n
class Solution2
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return {};

        int h = depth(root);
        vector<vector<int>> result(h, vector<int>());
        traverse(root, 0, result);
        return result;
    }

private:
    void traverse(TreeNode *root, int depth, vector<vector<int>> &result)
    {
        if (!root)
            return;
        result[result.size() - depth - 1].push_back(root->val);
        traverse(root->left, depth + 1, result);
        traverse(root->right, depth + 1, result);
    }
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> nq;
        nq.push(root);
        int depth = 0;
        while (nq.size())
        {
            int size = nq.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = nq.front();
                nq.pop();
                if (node->left)
                    nq.push(node->left);
                if (node->right)
                    nq.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};

int main()
{
    vector<int> ivec = {3, 9, 20, -1, -1, 15, 7};
    BFS<TreeNode> bfs(ivec);
    // Solution1 s;
    Solution2 s;
    vector<vector<int>> result = s.levelOrderBottom(bfs.root());
    for (const auto &ivec : result)
    {
        for (const int i : ivec)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
