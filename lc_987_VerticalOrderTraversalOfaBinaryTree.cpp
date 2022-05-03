#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// DFS
// TC: O(nlogn) map and set insert is logn
// SC: O(n) need a map to hold node info
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;
        map<int, map<int, multiset<int>>> node_map; // [right][left][val]
        traverse(root, 0, 0, node_map);

        for (auto iter = node_map.begin(); iter != node_map.end(); ++iter)
        {
            vector<int> this_right;
            for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
            {
                for (auto iter3 = iter2->second.begin(); iter3 != iter2->second.end(); ++iter3)
                    this_right.push_back(*iter3);
            }
            result.push_back(this_right);
        }
        return result;
    }

private:
    void traverse(TreeNode *root, int left, int right, map<int, map<int, multiset<int>>> &node_map)
    {
        if (!root)
            return;

        node_map[right][left].insert(root->val);
        traverse(root->left, left + 1, right - 1, node_map);
        traverse(root->right, left + 1, right + 1, node_map);
    }
};

int main()
{
    // vector<int> ivec = {3, 9, 20, -1, -1, 15, 7};
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    bfs.print(root);
    Solution s;
    vector<vector<int>> result = s.verticalTraversal(root);
    printVecVec(result);

    return 0;
}