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
// SC: O(n): at worst case you need to hold all vertices in the queue
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;

        queue<TreeNode *> nq;
        nq.push(root);
        while (!nq.empty())
        {
            size_t size = nq.size();
            result.push_back(nq.back()->val);
            for (size_t i = 0; i < size; ++i)
            {
                TreeNode *curr = nq.front();
                nq.pop();
                if (curr->left)
                    nq.push(curr->left);
                if (curr->right)
                    nq.push(curr->right);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> ivec = {1, 2, 3, -1, 5, -1, 4};
    BFS<TreeNode> bfs(ivec);
    Solution s;
    vector<int> result = s.rightSideView(bfs.root());
    for (const int i : result)
        cout << i << endl;
    cout << endl;
    return 0;
}
