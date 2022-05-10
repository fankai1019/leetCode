#include "utils.h"
using namespace std;

// BFS
// TC: O(n) need to iterate once
// SC: O(n) a queue is needed
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        if (!root)
            return {};

        vector<int> results;
        queue<TreeNode *> nq;
        nq.push(root);
        while (nq.size())
        {
            int size = nq.size();
            int mx = INT_MIN;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = nq.front();
                if (node->val >= mx)
                    mx = node->val;
                nq.pop();
                if (node->left)
                    nq.push(node->left);
                if (node->right)
                    nq.push(node->right);
            }
            results.push_back(mx);
        }
        return results;
    }
};

int main()
{
    vector<int> ivec = {1, 3, 2, 5, 3, null, 9};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    vector<int> result = s.largestValues(root);
    printVec(result);
    return 0;
}