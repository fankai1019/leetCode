#include "utils.h"
using namespace std;

// Backtracking
// TC: O(n2^n) for each number we can iter take it or drop it. Each time, copy vector to final results
// SC: O(n) recursion stack
class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> path;
        backtracking(nums, path, 0);
        return results;
    }

    void backtracking(const vector<int> &nums, vector<int> &path, int start)
    {
        if (path.size() >= 2)
            results.push_back(path);

        unordered_map<int, int> visited;
        for (int i = start; i < nums.size(); ++i)
        {
            if (!path.size() || nums[i] >= path.back())
            {
                if (i > start && visited[nums[i]])
                    continue;
                visited[nums[i]] = 1;
                path.push_back(nums[i]);
                backtracking(nums, path, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> results;
};

int main()
{
    vector<int> nums = {4, 6, 7, 7};
    Solution s;
    vector<vector<int>> results = s.findSubsequences(nums);
    printVecVec(results);
    return 0;
}