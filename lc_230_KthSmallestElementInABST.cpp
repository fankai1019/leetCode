#include "utils.h"

using namespace std;

// DFS kth smallest element is the val of the node which is from the kth left return
// TC: O(n) iterated over all nodes in worse case
// SC: O(h) stack frame size is height
class Solution
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

int main()
{
    vector<int> ivec = {3, 1, 4, null, 2};
    int k = 1;
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Solution s;
    int result = s.kthSmallest(root, k);
    cout << result << endl;
    return 0;
}
