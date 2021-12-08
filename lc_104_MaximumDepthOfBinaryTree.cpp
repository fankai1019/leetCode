#include <iostream>
#include <queue>
#include <vector>
#include <memory>

#include "utils.h"
using namespace std;

// struct TreeNode
// {
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };

// TC: O(n): every node is pushed and poped once, so 2n
// SC: O(n): at worst case you need to hold all vertices in the queue
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int depth = 0;
        if (!root)
            return depth;

        queue<TreeNode *> tq;
        tq.push(root);
        while (!tq.empty())
        {
            size_t size = tq.size();
            vector<int> level;
            depth++;
            for (size_t i = 0; i < size; ++i)
            {
                TreeNode *curr = tq.front();
                tq.pop();
                level.push_back(curr->val);
                if (curr->left)
                    tq.push(curr->left);
                if (curr->right)
                    tq.push(curr->right);
            }
        }
        return depth;
    }
};

int main()
{
    vector<int> ivec = {3, 9, 20, -1, -1, 15, 7};
    BFS<TreeNode> bfs(ivec);
    Solution s;
    int result = s.maxDepth(bfs.root());
    cout << result << endl;

    return 0;
}
