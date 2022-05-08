#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

#include "utils.h"

using namespace std;

// BFS
// TC: O(n) traverse once
// SC: O(n) need a queue to traverse
class Solution1
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> nq;
        nq.push(root);
        int count = 0;
        while (nq.size())
        {
            int size = nq.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = nq.front();
                nq.pop();
                count++;
                if (node->left && node->right)
                {
                    nq.push(node->left);
                    nq.push(node->right);
                }
                else if (!node->left)
                    return 2 * count - 1;
                else if (!node->right)
                    return 2 * count;
            }
        }
        return -1;
    }
};

// BFS
// TC: O(h^2) every time we calculate the high, it takes logn time.
//     There are n nodes, it looks like nlogn.
//     But there is only one recursive call in 1 + countNodes(root->left) + countNodes(root->right)
//     So it is h + h-1 +h-2 + ... +1 = O(h^2)
//     Another way:
//     T(n) = T(n/2) + c1logn
//          = T(n/4) + c1logn + c2(logn - 1)
//          = ...
//          = T(1) + c[logn + (logn-1) + .. + 1]
//          = logn*logn
// SC: O(h) stack frame size is h
class Solution2
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = 0;
        int rh = 0;
        TreeNode *l = root;
        TreeNode *r = root;
        while (l)
        {
            lh++;
            l = l->left;
        }
        while (r)
        {
            rh++;
            r = r->right;
        }

        if (lh == rh)
            return pow(2, lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{
    vector<int> ivec{1, 2, 3, 4, 5, 6};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    cout << endl;
    // Solution1 s;
    Solution2 s;
    int result = s.countNodes(root);
    cout << result << endl;
    return 0;
}
