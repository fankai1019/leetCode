#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// DP: sum(0, i) = a[i] + sum(0, i-1) < 0 ? 0 : sum(0, i-1), iterative
// DP: sum(0, i) = max(a[i], a[i] + sum(0, i-1))
// TC: O(n) loops over all elements
// SC: O(1) needs 2 integers to store sum and max sum
class Solution1
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = INT_MIN;
        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (sum < 0)
                sum = 0;
            sum += nums[i];
            if (max_sum < sum)
                max_sum = sum;
        }
        return max_sum;
    }
};

// DP: sum(0, i) = a[i] + sum(0, i-1) < 0 ? 0 : sum(0, i-1), recursive
// DP: sum(0, i) = max(a[i], a[i] + sum(0, i-1))
// TC: O(n) loops over all elements
// SC: O(n) stack size is n
class Solution2
{
public:
    int maxSubArray(vector<int> &nums)
    {
        global_max_ = nums[0];
        helper(nums, nums.size() - 1);
        return global_max_;
    }

private:
    int helper(vector<int> &nums, int i)
    {
        if (i == 0)
            return nums[0];

        int prev = helper(nums, i - 1);
        int result = max(nums[i], nums[i] + prev);
        if (global_max_ < result)
            global_max_ = result;
        return result;
    }
    int global_max_;
};

// TODO: follow up divide and conquer

int main()
{
    // Solution1 s;
    Solution2 s;
    vector<int> ivec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = s.maxSubArray(ivec);
    cout << result << endl;
    return 0;
}
