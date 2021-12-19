#include <algorithm>
#include <iostream>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// DP
// TC: O(n) we need to loop over all states
// SP: O(1) only previous and the one before previous state need to be stored
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        return max(helper(nums, 0, nums.size() - 1), helper(nums, 1, nums.size() - 1));
    }

private:
    int helper(const vector<int> &nums, size_t index, size_t size)
    {
        if (size == 1)
            return nums[index];
        if (size == 2)
            return max(nums[index], nums[index + 1]);

        int a = nums[index];
        int b = max(nums[index], nums[index + 1]);
        int c;
        for (size_t i = 2; i < size; ++i)
        {
            c = max(a + nums[index + i], b);
            a = b;
            b = c;
        }
        return c;
    }
};

int main()
{
    Solution s;
    vector<int> ivec = {1, 2, 3, 1};
    int result = s.rob(ivec);
    cout << result << endl;
    return 0;
}
