#include "utils.h"

using namespace std;

// Backtracking
// TC: O(c(n,k)) worst case no repetitive numbers
// SC: O(n) stack frame size is n, unordered_map size is n, path is n
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> nums;
        for (int i = 1; i <= n; ++i)
            nums.push_back(i);

        vector<int> path;
        backtracking(nums, path, k, 0);
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
    int n = 4;
    int k = 2;
    Solution s;
    vector<vector<int>> results = s.combine(n, k);
    printVecVec(results);
    return 0;
}
