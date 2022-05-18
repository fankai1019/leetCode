#include "utils.h"
using namespace std;

// Similar to 473. Matchsticks to Square
// DFS + Bitmasking
// TC: O(k^n) each number has k choices to be placed.
// SC: O(n) recursion stack
class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        sum /= k;
        // vector<bool> visited(nums.size(), false);
        int visited = 0; // use this (bit-masking) instead of vector to avoid TLE
        backtracking(nums, sum, 0, k, visited, 0);
        return result;
    }

private:
    void backtracking(const vector<int> &nums, int target, int sum, int k, int visited, int start)
    {
        if (result)
            return;
        if (k == 1)
        {
            result = true;
            return;
        }

        if (mp.count(start) && mp[start].count(visited) && !mp[start][visited])
            return;

        if (sum == target)
            backtracking(nums, target, 0, k - 1, visited, 0);

        for (int i = start; i < nums.size(); ++i)
        {
            if (sum + nums[i] <= target)
            {
                // if (!visited[i])
                if (!(visited >> i & 1))
                {
                    // visited[i] = true;
                    visited = visited | (1 << i);
                    backtracking(nums, target, sum + nums[i], k, visited, i + 1);
                    // visited[i] = false;
                    visited = visited & ~(1 << i);
                }
            }
        }
        mp[start][visited] = 0;
    }
    bool result = false;
    unordered_map<int, unordered_map<int, int>> mp; // [start index, visited, true/false]
};

int main()
{
    // vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    // int k = 4;
    vector<int> nums = {2, 9, 4, 7, 3, 2, 10, 5, 3, 6, 6, 2, 7, 5, 2, 4};
    int k = 7;
    Solution s;
    bool result = s.canPartitionKSubsets(nums, k);
    cout << result << endl;
    return 0;
}