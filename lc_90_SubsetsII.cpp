#include "utils.h"

using namespace std;

// Backtracking
// TC: O(n2^n) there are 2^n possible subsets and each time we need to copy path into results
// SC: O(n) stack frame size is n, path size is n, regardless final results collection.
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        int size = nums.size();
        for (int i = 0; i < size; ++i)
            mp[nums[i]]++;

        while (size >= 0)
        {
            vector<int> path;
            backtracking(nums, size, path, mp);
            size--;
        }
        return results;
    }

private:
    void backtracking(const vector<int> &nums, int k, vector<int> &path, unordered_map<int, int> &mp)
    {
        if (path.size() == k)
        {
            results.push_back(path);
            return;
        }

        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (!iter->second)
                continue;
            if (path.size() && path.back() > iter->first)
                continue;
            path.push_back(iter->first);
            iter->second--;
            backtracking(nums, k, path, mp);
            path.pop_back();
            iter->second++;
        }
    }

    vector<vector<int>> results;
};

int main()
{
    vector<int> nums = {1, 2, 2};
    Solution s;
    vector<vector<int>> results = s.subsetsWithDup(nums);
    printVecVec(results);
    return 0;
}
