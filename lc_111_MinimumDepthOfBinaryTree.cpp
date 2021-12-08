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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> tq;
        tq.push(root);
        int counter = 0;
        while (tq.size())
        {
            counter++;
            size_t size = tq.size();
            for (size_t i = 0; i < size; ++i)
            {
                TreeNode *curr = tq.front();
                tq.pop();
                if (!curr->left && !curr->right)
                    return counter;
                if (curr->left)
                    tq.push(curr->left);
                if (curr->right)
                    tq.push(curr->right);
            }
        }
        return counter;
    }
};

int main()
{
    vector<int> ivec = {3, 9, 20, -1, -1, 15, 7};
    BFS<TreeNode> bfs(ivec);
    Solution s;
    int result = s.minDepth(bfs.root());
    cout << result << endl;
    return 0;
}
