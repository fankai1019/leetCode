#include "utils.h"

using namespace std;

// DFS kth smallest element is the val of the node which is from the kth left return
// TC: O(n) iterated over all nodes in worse case
// SC: O(h) stack frame size is height
class Solution1
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        if (!root)
            return val_;

        kthSmallest(root->left, k);
        k_++;
        if (k == k_)
            val_ = root->val;
        kthSmallest(root->right, k);
        return val_;
    }
    int k_ = 0;
    int val_ = 0;
};

// Solution when redid
// DFS kth smallest element is the val of the node which is from the kth left return
// TC: O(n) iterated over all nodes in worse case
// SC: O(h) stack frame size is height
class Solution2
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root, k);
        return result;
    }

private:
    void dfs(TreeNode *root, int &k)
    {
        if (!root)
            return;
        dfs(root->left, k);
        k--;
        if (k == 0)
        {
            result = root->val;
            return;
        }
        dfs(root->right, k);
        return;
    }
    int result = 0;
};

int main()
{
    vector<int> ivec = {3, 1, 4, null, 2};
    int k = 1;
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    // Solution1 s;
    Solution2 s;
    int result = s.kthSmallest(root, k);
    cout << result << endl;
    return 0;
}
