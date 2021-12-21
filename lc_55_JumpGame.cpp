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

// DP
// TC: O(n^2) n states and in each state the worst case needs to loop n elements
// SP: O(n) memo
// state: can I jump to end from position i
class Solution2
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
    bool helper(const vector<int>& nums, int i, vector<int>& memo)
    {
        if(memo[i] != -1)
            return memo[i];
        size_t n = nums.size();
        if (i >= n - 1 || i + nums[i] >= n-1)
        {
            memo[i] = 1;
            return true;
        }
        for(size_t j=1; j<=nums[i]; ++j)
        {
            if (helper(nums, i+j, memo))
            {
                memo[i] = 1;
                return true;
            }
        }
        memo[1] = 0;
        return false;
    }
};

int main()
{
    // Solution1 s;
    Solution2 s;
    vector<int> ivec = {2, 3, 1, 1, 4};
    bool result = s.canJump(ivec);
    cout << result << endl;
    return 0;
}
