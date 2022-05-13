#include "utils.h"

using namespace std;

// Backtracking
// TC: O(n!) worst case no repetitive numbers
// SC: O(n) stack frame size is n, unordered_map size is n, path is n
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> path;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
            mp[nums[i]]++;
        backtracking(nums, path, mp);
        return results;
    }

private:
    void backtracking(const vector<int> &nums, vector<int> &path, unordered_map<int, int> &mp)
    {
        if (path.size() == nums.size())
        {
            results.push_back(path);
            return;
        }

        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second == 0)
                continue;
            path.push_back(iter->first);
            iter->second--;
            backtracking(nums, path, mp);
            path.pop_back();
            iter->second++;
        }
    }
    vector<vector<int>> results;
};

int main()
{
    vector<int> nums = {1, 1, 2};
    Solution s;
    vector<vector<int>> results = s.permuteUnique(nums);
    printVecVec(results);
    return 0;
}
