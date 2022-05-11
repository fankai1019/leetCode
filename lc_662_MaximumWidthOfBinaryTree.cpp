#include "utils.h"
using namespace std;

// BFS
// TC: O(n) need to iterate once
// SC: O(n) a queue is needed
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, unsigned long long int>> nq;
        nq.push(make_pair(root, 0));
        int width = 0;
        while (nq.size())
        {
            int size = nq.size();
            unsigned long long int left = nq.front().second;
            unsigned long long int right = left;
            while (size-- > 0)
            {
                pair<TreeNode *, int> node = nq.front();
                nq.pop();
                right = node.second;
                if (node.first->left)
                    nq.push(make_pair(node.first->left, 2 * right + 1));
                if (node.first->right)
                    nq.push(make_pair(node.first->right, 2 * right + 2));
            }

            width = max(width, (int)(right - left + 1));
        }
        return width;
    }
};

int main()
{
    vector<int> ivec = {1, 3, 2, 5, 3, null, 9};
    int val = 1;
    int depth = 2;
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    int result = s.widthOfBinaryTree(root);
    cout << result << endl;
    return 0;
}