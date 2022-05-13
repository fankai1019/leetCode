#include "utils.h"

using namespace std;

// Backtracking
// TC: O(n2^n) there are 2^n possible subsets and each time we need to copy path into results
// SC: O(n) stack frame size is n, path size is n, regardless final results collection.
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int size = nums.size();
        while (size >= 0)
        {
            vector<int> path;
            backtracking(nums, path, size, 0);
            size--;
        }
        return results;
    }

private:
    void backtracking(const vector<int> &nums, vector<int> &path, int k, int begin)
    {
        if (path.size() == k)
        {
            results.push_back(path);
            return;
        }

        for (int i = begin; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtracking(nums, path, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> results;
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> results = s.subsets(nums);
    printVecVec(results);
    return 0;
}
