#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// Greedy
// TC: O(n) we need to loop over all elements
// SP: O(1) only previous and the one before previous state need to be stored
class Solution1
{
public:
    bool canJump(vector<int> &nums)
    {
        int target = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (i + nums[i] >= target)
                target = i;
        }
        return target == 0;
    }
};

// Greedy
// TC: O(n) we need to loop over all elements
// SP: O(1)
class Solution2
{
    bool canJump(vector<int> &nums)
    {
        int farthest = 0;
        int start = 0;
        int end = 0;
        while (start <= end)
        {
            if (start == nums.size() - 1)
                return true;
            farthest = max(farthest, start + nums[start]);
            if (start == end)
            {
                start = end + 1;
                end = farthest;
            }
            else
                start++;
        }
        return false;
    }
};

// DP
// TC: O(n^2) n states and in each state the worst case needs to loop n elements
// SP: O(n) memo
// state: can I jump to end from position i
class Solution3
{
public:
    bool canJump(vector<int> &nums)
    {
        size_t n = nums.size();
        vector<int> memo(nums.size(), -1);
        return helper(nums, 0, memo);
    }

private:
    // Returns whether we can reach n - 1 from i
    bool helper(const vector<int> &nums, int i, vector<int> &memo)
    {
        if (memo[i] != -1)
            return memo[i];
        size_t n = nums.size();
        if (i >= n - 1 || i + nums[i] >= n - 1)
        {
            memo[i] = 1;
            return true;
        }
        for (size_t j = 1; j <= nums[i]; ++j)
        {
            if (helper(nums, i + j, memo))
            {
                memo[i] = 1;
                return true;
            }
        }
        memo[1] = 0;
        return false;
    }
};

// DP
// define dp[i] as the minimim steps it needs to reach i
// TC: O(n^2))
// SC: O(n)
class Solution4
{
public:
    bool canJump(vector<int> &nums)
    {

        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < dp.size() - 1; ++i)
        {
            if (nums[i] == 0 || dp[i] == INT_MAX)
                continue;
            int steps = dp[i] + 1;
            for (int j = nums[i]; j > 0; --j)
            {
                if (i + j >= dp.size())
                    return true;
                if (steps < dp[i + j])
                    dp[i + j] = steps;
                else
                    break;
            }
        }
        return dp[nums.size() - 1] < INT_MAX;
    }
};

// BFS
// TC: O(n*max(nums[i])) each node is pushed once, at each node, we neeed to iterate from 0 to num[i]
// SC: O(n) a stack is needed and it has size n in worse case
class Solution5
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;

        queue<int> iqueue;
        iqueue.push(0);

        vector<int> visited(nums.size(), 0);
        while (iqueue.size())
        {
            int size = iqueue.size();
            for (int m = 0; m < size; ++m)
            {
                int i = iqueue.front();
                iqueue.pop();
                if (i == nums.size() - 1)
                    return true;
                for (int j = 1; j <= nums[i]; ++j)
                {
                    if (i + j >= nums.size() - 1)
                        return true;
                    if (visited[i + j])
                        continue;
                    iqueue.push(i + j);
                    visited[i + j] = 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    // Solution1 s;
    Solution2 s;
    // Solution3 s;
    // Solution4 s;
    // Solution5 s;
    vector<int> ivec = {2, 3, 1, 1, 4};
    bool result = s.canJump(ivec);
    cout << result << endl;
    return 0;
}
