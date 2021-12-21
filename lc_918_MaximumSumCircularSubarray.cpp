#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// DP: sum_max(0, i) = a[i] + sum_max(0, i-1) < 0 ? 0 : sum_max(0, i-1), iterative
// DP: sum_max(0, i) = max(a[i], a[i] + sum_max(0, i-1))
// DP: sum_min(0, i) = a[i] + sum_min(0, i-1) > 0 ? 0 : sum_min(0, i-1), iterative
// DP: sum_min(0, i) = min(a[i], a[i] + sum_min(0, i-1))
// TC: O(n) loops over all elements
// SC: O(1) needs 2 integers to store sum and max sum
class Solution
{
public:
    int maxSubArrayCircular(vector<int> &nums)
    {
        int max_sum = nums[0];
        int min_sum = nums[0];
        int curr_max = 0;
        int curr_min = 0;
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            curr_max = max(nums[i], nums[i] + curr_max);
            max_sum = max(max_sum, curr_max);
            curr_min = min(nums[i], nums[i] + curr_min);
            min_sum = min(min_sum, curr_min);
            total += nums[i];
        }
        return max_sum > 0 ? max(max_sum, total - min_sum) : max_sum;
    }
};

int main()
{
    Solution s;
    // vector<int> ivec = {3, -1, 2, 1};
    // vector<int> ivec = {5, -3, 5};
    vector<int> ivec = {-3, -2, -3};
    int result = s.maxSubArrayCircular(ivec);
    cout << result << endl;
    return 0;
}
