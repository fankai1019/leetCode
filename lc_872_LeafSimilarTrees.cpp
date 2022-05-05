#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// DFS
// TC: O(n) need to iterate once
// SC: O(n) stack frame size is n
class Solution
{
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leaves1;
        vector<int> leaves2;
        traverse(root1, leaves1);
        traverse(root2, leaves2);
        if (leaves1.size() == leaves2.size())
        {
            for (int i = 0; i < leaves1.size(); ++i)
            {
                if (leaves1[i] != leaves2[i])
                    return false;
            }
        }
        else
            return false;
        return true;
    }

private:
    void traverse(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            result.push_back(root->val);
        traverse(root->left, result);
        traverse(root->right, result);
    }
};

int main()
{
    vector<int> ivec1 = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
    vector<int> ivec2 = {3, 5, 1, 6, 7, 4, 2, -1, -1, -1, -1, -1, -1, 9, 8};
    BFS<TreeNode> bfs1(ivec1);
    BFS<TreeNode> bfs2(ivec2);
    TreeNode *root1 = bfs1.root();
    TreeNode *root2 = bfs2.root();
    BFS<TreeNode>::print(root1);
    BFS<TreeNode>::print(root2);
    Solution s;
    bool result = s.leafSimilar(root1, root2);
    cout << result << endl;

    return 0;
}