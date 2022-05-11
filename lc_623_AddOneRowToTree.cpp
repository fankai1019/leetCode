#include "utils.h"
using namespace std;

// BFS
// TC: O(n) need to iterate once
// SC: O(n) a queue is needed
class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        TreeNode new_head;
        new_head.left = root;

        // root and root's parent
        queue<TreeNode *> nq;
        nq.push(&new_head);
        int curr_depth = 0;
        while (nq.size())
        {
            int size = nq.size();
            while (size-- > 0)
            {
                TreeNode *node = nq.front();
                nq.pop();
                if (curr_depth < depth - 1)
                {
                    if (node->left)
                        nq.push(node->left);
                    if (node->right)
                        nq.push(node->right);
                }
                if (curr_depth == depth - 1)
                {
                    TreeNode *new_left = new TreeNode(val);
                    TreeNode *tmp = node->left;
                    node->left = new_left;
                    new_left->left = tmp;

                    TreeNode *new_right = new TreeNode(val);
                    tmp = node->right;
                    node->right = new_right;
                    new_right->right = tmp;
                }
            }
            curr_depth++;
        }
        return new_head.left;
    }
};

int main()
{
    vector<int> ivec = {4, 2, 6, 3, 1, 5};
    int val = 1;
    int depth = 2;
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    TreeNode *result = s.addOneRow(root, val, depth);
    print(result);
    return 0;
}