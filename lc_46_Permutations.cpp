#include "utils.h"
using namespace std;

// First try
// Backtracking
// TC: O(n!n): T(n) = nT(n-1) +O(n)
// SC: O(n) recursion stack
class Solution1
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> path;
        backtracking(nums, path);
        return results;
    }

private:
    void backtracking(const vector<int> &nums, vector<int> &path)
    {
        if (!nums.size())
        {
            results.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            vector<int> rest;
            path.push_back(nums[i]);
            removeIndex(rest, nums, nums[i]);
            backtracking(rest, path);
            path.pop_back();
        }
    }
    void removeIndex(vector<int> &result, const vector<int> &nums, int val)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
                result.push_back(nums[i]);
        }
    }
    vector<vector<int>> results;
};

// Visited nodes
// Backtracking
// TC: O(n!n): T(n) = nT(n-1) +O(n)
// SC: O(n) recursion stack
class Solution2
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        backtracking(nums, path, visited);
        return results;
    }

private:
    void backtracking(const vector<int> &nums, vector<int> &path, vector<bool> &visited)
    {
        if (path.size() == nums.size())
        {
            results.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, path, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> results;
};

int main()
{
    vector<int> ivec = {1, 2, 3};
    // Solution1 s;
    Solution2 s;
    vector<vector<int>> result = s.permute(ivec);
    printVecVec(result);
    return 0;
}