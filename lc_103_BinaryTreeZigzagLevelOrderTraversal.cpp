#include <iostream>
#include <memory>
#include <queue>
#include <vector>

#include "utils.h"
using namespace std;

// struct TreeNode
// {
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   int val;
//   TreeNode *left;
//   TreeNode *right;
// };

// TC: O(n): every node is pushed and poped once, so 2n
// SC: O(n): in worst case you need to hold all vertices in the queue
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        bool left_to_right = true;
        queue<TreeNode *> tq;
        tq.push(root);
        while (tq.size())
        {
            size_t size = tq.size();
            vector<int> ivec(size);
            for (int i = 0; i < size; ++i)
            {
                TreeNode *curr = tq.front();
                tq.pop();
                if (left_to_right)
                    ivec[i] = curr->val;
                else
                    ivec[size - 1 - i] = curr->val;
                if (curr->left)
                    tq.push(curr->left);
                if (curr->right)
                    tq.push(curr->right);
            }
            result.push_back(ivec);
            left_to_right = !left_to_right;
        }
        return result;
    }
};

int main()
{
    vector<int> ivec = {3, 9, 20, null, null, 15, 7};
    BFS<TreeNode> bfs(ivec);
    Solution s;
    vector<vector<int>> result = s.zigzagLevelOrder(bfs.root());
    for (const auto &ivec : result)
    {
        for (const int i : ivec)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
