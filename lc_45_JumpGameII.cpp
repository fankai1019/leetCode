#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>

#include "utils.h"
using namespace std;

// Brute force
// TC: O(n^2) two for loops and worst case is n^2
// SP: O(n) store results
class Solution1
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int n = nums.size();
        vector<int> result(n - 1, INT_MAX);
        result[n - 2] = nums[n - 2] == 0 ? INT_MAX : 1;

        for (int i = n - 3; i >= 0; --i)
        {
            if (nums[i] + i >= n - 1)
            {
                result[i] = 1;
                continue;
            }
            for (int j = i + 1; j <= min(nums[i] + i, n - 2); ++j)
            {
                result[i] = min(result[j], result[i]);
            }
            if (result[i] != INT_MAX)
                result[i] += 1;
        }
        return result[0];
    }
};

// DP
// TC: O(n^2) n states and in each state the worst case needs to loop n elements
// SP: O(n) store results
class Solution2
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        return helper(nums, 0, memo);
    }

private:
    // Returns the number of jumps to reach n - 1
    int helper(const vector<int> &nums, size_t i, vector<int> &memo)
    {
        if (memo[i] != -1)
            return memo[i];
        size_t n = nums.size();
        if (i >= n - 1)
            return memo[i] = 0;
        if (i + nums[i] >= n - 1)
            return memo[i] = 1;

        int min_steps = n;
        for (size_t j = 1; j <= nums[i]; ++j)
        {
            int steps = helper(nums, i + j, memo);
            if (steps < min_steps)
                min_steps = steps;
        }
        return memo[i] = 1 + min_steps;
    }
};

// BFS
// TC(n^2) for each layer the worse case is we still push n elements in it. This has no memo, slower than dp
// SC(n)
class Solution3
{
public:
    int jump(vector<int> &nums)
    {
        int steps = 0;
        size_t n = nums.size();
        unordered_set<int> visited;
        queue<int> iq;
        iq.push(0);
        while (iq.size())
        {
            size_t size = iq.size();
            for (size_t i = 0; i < size; ++i)
            {
                int j = iq.front();
                iq.pop();
                if (visited.count(j))
                    continue;

                if (j >= n - 1)
                    return steps;
                if (j + nums[j] >= n - 1)
                    return steps + 1;

                for (size_t k = 1; k <= nums[j]; ++k)
                {
                    iq.push(j + k);
                }
                visited.insert(j);
            }
            steps++;
        }
        return steps;
    }
};

// DP
// TC: O(n^2)
// SP: O(n)
// define dp[i] as the min number steps to reach i from 0
// so far best DP
class Solution4
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        // 1 <= nums.size() <= 10^4
        dp[0] = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            int num_steps = dp[i] + 1;
            for (int j = min(i + nums[i], n - 1); j > i; --j)
            {
                // we can break as values of step is increasing
                // for any j > i, dp[j] >= dp[i]
                // if num_dp < dp[j] is false
                // no need to continue going backward
                if (num_steps < dp[j])
                    dp[j] = num_steps;
                else
                    break;
            }
        }
        return dp[n - 1];
    }
};

// DP
// TC: O(n^2)
// SP: O(n)
// define dp[i] as the min number steps to reach i from n - 1
class Solution5
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX - 1);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 1; j <= nums[i]; ++j)
                dp[i] = min(dp[i], dp[min(n - 1, i + j)] + 1);
        }

        return dp[0];
    }
};

// BFS + two pointer
// TC(n) loop over all elements
// SC(1) just need to store start and end
class Solution6
{
public:
    int jump(vector<int> &nums)
    {
        int steps = 0;
        int start = 0;
        int end = 0;
        if (nums.size() == 1)
            return 0;
        size_t n = nums.size();
        while (start <= end)
        {
            if (start >= n - 1)
                return steps;
            int end_new = end;
            for (int i = start; i <= end; ++i)
            {
                end_new = max(end_new, i + nums[i]);
                if (end_new >= n - 1)
                    return steps + 1;
            }
            start = end + 1;
            end = end_new;
            steps++;
        }
        return steps;
    }
};

int main()
{
    // Solution1 s;
    // Solution2 s;
    // Solution3 s;
    // Solution4 s;
    // Solution5 s;
    Solution6 s;
    vector<int> ivec = {2, 3, 0, 1, 4};
    int result = s.jump(ivec);
    cout << result << endl;
    return 0;
}
