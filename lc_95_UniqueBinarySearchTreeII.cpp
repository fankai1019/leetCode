#include <iostream>
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

// DP without cache
// Define dp[pair<left, right>] as the vector of root of trees that build from left to right
// Then a tree with root i built from 1 to n is: i->left = dp[pair<1, i-1>] i->right = dp[pair<i+1, n>]
// TC: O(nC(n))To constrcut all possible trees with a give root, we need time C(n) (catalan number)
//     we need to do this from 1 to n. So totaltime is n*C(n)
// SC: O(nC(n))
class Solution1
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }

private:
    // low <=mid <=high
    vector<TreeNode *> helper(int left, int right)
    {
        vector<TreeNode *> result;
        if (left > right)
        {
            result.push_back(nullptr);
        }
        else if (left == right)
        {
            TreeNode *node = new TreeNode(left);
            result.push_back(node);
        }
        else
        {
            for (int i = left; i <= right; ++i)
            {
                vector<TreeNode *> left_tree = helper(left, i - 1);
                vector<TreeNode *> right_tree = helper(i + 1, right);
                for (int l = 0; l < left_tree.size(); ++l)
                {
                    for (int r = 0; r < right_tree.size(); ++r)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = left_tree[l];
                        root->right = right_tree[r];
                        result.push_back(root);
                    }
                }
            }
        }
        return result;
    }
};

// DP with cache
// Define dp[pair<left, right>] as the vector of root of trees that build from left to right
// Then a tree with root i built from 1 to n is: i->left = dp[pair<1, i-1>] i->right = dp[pair<i+1, n>]
// TC: not trivial to calculate
// SC: a map is needed
class Solution2
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }

private:
    // low <=mid <=high
    const vector<TreeNode *> &helper(int left, int right)
    {
        if (left > right)
        {
            left = 0;
            right = 0;
        }

        pair<int, int> key = make_pair(left, right);
        if (mp.count(key))
            return mp[key];

        vector<TreeNode *> result;
        if (left == 0)
        {
            result.push_back(nullptr);
            mp[key] = result;
        }
        else if (left == right)
        {
            TreeNode *node = new TreeNode(left);
            result.push_back(node);
            mp[key] = result;
        }
        else
        {
            for (int i = left; i <= right; ++i)
            {
                const vector<TreeNode *> &left_tree = helper(left, i - 1);
                const vector<TreeNode *> &right_tree = helper(i + 1, right);
                for (int l = 0; l < left_tree.size(); ++l)
                {
                    for (int r = 0; r < right_tree.size(); ++r)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = left_tree[l];
                        root->right = right_tree[r];
                        result.push_back(root);
                    }
                }
            }
            mp[key] = result;
        }
        return mp[key];
    }
    map<pair<int, int>, vector<TreeNode *>> mp;
};

int main()
{
    Solution1 s;
    vector<TreeNode *> results = s.generateTrees(3);
    for (int i = 0; i < results.size(); ++i)
    {
        BFS<TreeNode>::print(results[i]);
        cout << endl;
    }
    return 0;
}
