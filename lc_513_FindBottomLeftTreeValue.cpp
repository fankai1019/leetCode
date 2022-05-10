#include "utils.h"
using namespace std;

// BFS
// TC: O(n) need to iterate once
// SC: O(n) a queue is needed
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        if (!root)
            return 0;
        int result = 0;
        queue<TreeNode *> nq;
        nq.push(root);
        while (nq.size())
        {
            int size = nq.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = nq.front();
                nq.pop();
                if (i == 0)
                    result = node->val;
                if (node->left)
                    nq.push(node->left);
                if (node->right)
                    nq.push(node->right);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> ivec = {1, 2, 3, 4, null, 5, 6, null, null, 7};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    int result = s.findBottomLeftValue(root);
    cout << result << endl;
    return 0;
}