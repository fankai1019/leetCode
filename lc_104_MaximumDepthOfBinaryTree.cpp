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

// BFS
// TC: O(n): every node is pushed and poped once, so 2n
// SC: O(n): in worst case you need to hold all vertices in the queue
class Solution1
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

// DFS
// TC: O(n): every node is visited 3 times, so 3n
// SC: O(h): tree hight
class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);
        return max(left_max, right_max) + 1;
    }
};

int main()
{
    vector<int> ivec = {3, 9, 20, null, null, 15, 7};
    BFS<TreeNode> tree(ivec);
    // Solution1 s;
    Solution2 s;
    int result = s.maxDepth(tree.root());
    cout << result << endl;

    return 0;
}
