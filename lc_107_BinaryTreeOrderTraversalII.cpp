#include <algorithm>
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
// SC: O(n): at worst case you need to hold all vertices in the queue
class Solution
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

int main()
{
    vector<int> ivec = {3, 9, 20, -1, -1, 15, 7};
    BFS bfs(ivec);
    Solution s;
    vector<vector<int>> result = s.levelOrderBottom(bfs.root());
    for (const auto &ivec : result)
    {
        for (const int i : ivec)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
