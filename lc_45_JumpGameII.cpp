#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n^2) try BFS
// SP: O(1) only previous and the one before previous state need to be stored
class Solution
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

int main()
{
    Solution s;
    vector<int> ivec = {2, 3, 1, 1, 4};
    int result = s.jump(ivec);
    cout << result << endl;
    return 0;
}
