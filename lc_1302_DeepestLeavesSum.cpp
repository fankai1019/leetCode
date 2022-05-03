#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// BFS
// TC: O(n) need to iterate once
// SC: O(n) a queue is needed
class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        if (!root)
            return 0;
        int result;
        queue<TreeNode *> tq;
        tq.push(root);
        int sum = 0;
        while (tq.size())
        {
            int size = tq.size();
            sum = 0;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = tq.front();
                sum += node->val;
                tq.pop();
                if (node->left)
                    tq.push(node->left);
                if (node->right)
                    tq.push(node->right);
            }
        }
        return sum;
    }
};

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, -1, 6, 7, -1, -1, -1, -1, 8};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    bfs.print(root);
    Solution s;
    int result = s.deepestLeavesSum(root);
    cout << result << endl;

    return 0;
}