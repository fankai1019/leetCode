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

        // vector<int> result(nums.size());
        // result[0] = nums[0];
        // result[1] = max(nums[0], nums[1]);
        // for(size_t i=2; i<result.size(); ++i)
        //   result[i] = max(result[i-2] + nums[i], result[i-1]);
        // return result.back();

        int a = nums[0];
        int b = max(nums[0], nums[1]);
        int c;
        for (size_t i = 2; i < nums.size(); ++i)
        {
            c = max(a + nums[i], b);
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
