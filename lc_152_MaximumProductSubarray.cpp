#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// DP: prod_max[i] = max(nums[i], nums[i] < 0 ? prod_min[i-1]*nums[i] : prod_max[i-1]*nums[i])
// DP: prod_min[i] = min(nums[i], nums[i] < 0 ? prod_max[i-1]*nums[i] : prod_min[i-1]*nums[i])
// TC: O(n) loops over all elements
// SC: O(1) needs to track curr min max and global max
// iterative
class Solution1
{
public:
    int maxProduct(vector<int> &nums)
    {
        int curr_max = nums[0];
        int curr_min = nums[0];
        int prev_max = curr_max;
        int prev_min = curr_min;
        int prod_max = nums[0];
        for (size_t i = 1; i < nums.size(); ++i)
        {
            int nums_i = nums[i];
            curr_max = max(nums_i, nums_i < 0 ? nums_i * prev_min : nums_i * prev_max);
            curr_min = min(nums_i, nums_i < 0 ? nums_i * prev_max : nums_i * prev_min);
            prev_max = curr_max;
            prev_min = curr_min;
            prod_max = max(prod_max, curr_max);
        }
        return prod_max;
    }
};

// DP: prod_max[i] = max(nums[i], nums[i] < 0 ? prod_min[i-1]*nums[i] : prod_max[i-1]*nums[i])
// DP: prod_min[i] = min(nums[i], nums[i] < 0 ? prod_max[i-1]*nums[i] : prod_min[i-1]*nums[i])
// TC: O(n) loops over all elements
// SC: O(n) stack size is n
// recursive
class Solution2
{
public:
    int maxProduct(vector<int> &nums)
    {
        global_max_ = nums[0];
        int curr_max, curr_min;
        helper(nums, nums.size() - 1, curr_max, curr_min);
        return global_max_;
    }

private:
    // returns prod_min and prod_max at i
    void helper(const vector<int> &nums, int i, int &curr_max, int &curr_min)
    {
        int nums_i = nums[i];
        if (i == 0)
        {
            curr_max = nums_i;
            curr_min = nums_i;
            if (global_max_ < curr_max)
                global_max_ = curr_max;
            return;
        }
        int prev_max;
        int prev_min;
        helper(nums, i - 1, prev_max, prev_min);
        curr_max = max(nums_i, nums_i < 0 ? prev_min * nums_i : prev_max * nums_i);
        curr_min = min(nums_i, nums_i < 0 ? prev_max * nums_i : prev_min * nums_i);
        if (global_max_ < curr_max)
            global_max_ = curr_max;
    }

    int global_max_;
};

int main()
{
    Solution1 s;
    // Solution2 s;
    // vector<int> ivec = {2, 3, -2, 4};
    vector<int> ivec = {-4, -3, -2};
    int result = s.maxProduct(ivec);
    cout << result << endl;
    return 0;
}
