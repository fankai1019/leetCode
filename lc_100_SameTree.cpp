#include <iostream>
#include <queue>
#include <vector>
#include <memory>

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        queue<TreeNode *> tq1;
        queue<TreeNode *> tq2;
        tq1.push(p);
        tq2.push(q);

        while (tq1.size())
        {
            size_t tq_size1 = tq1.size();
            size_t tq_size2 = tq2.size();
            if (tq_size1 != tq_size2)
                return false;
            for (size_t i = 0; i < tq_size1; ++i)
            {
                TreeNode *curr1 = tq1.front();
                TreeNode *curr2 = tq2.front();
                tq1.pop();
                tq2.pop();
                if (curr1->val != curr2->val)
                    return false;
                if (curr1->left && curr2->left)
                {
                    tq1.push(curr1->left);
                    tq2.push(curr2->left);
                }
                else if (curr1->left || curr2->left)
                    return false;
                if (curr1->right && curr2->right)
                {
                    tq1.push(curr1->right);
                    tq2.push(curr2->right);
                }
                else if (curr1->right || curr2->right)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<int> ivec1 = {1, 2, 1};
    vector<int> ivec2 = {1, 1, 2};
    BFS<TreeNode> bfs1(ivec1);
    BFS<TreeNode> bfs2(ivec2);
    Solution s;
    bool result = s.isSameTree(bfs1.root(), bfs2.root());
    cout << result << endl;
    return 0;
}