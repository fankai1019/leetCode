#include <iostream>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

// DFS
// TC: O(n) iterate onces
// SC: O(height) stack frame size is h
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};

int main()
{
    vector<int> ivec = {6, 2, 8, 0, 4, 7, 9, null, null, 3, 5};
    BFS<TreeNode> bfs(ivec);
    TreeNode *p = bfs.find(2);
    TreeNode *q = bfs.find(8);
    print(bfs.root());
    Solution s;
    TreeNode *result = s.lowestCommonAncestor(bfs.root(), p, q);
    if (result)
        cout << result->val << endl;
    return 0;
}
