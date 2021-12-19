#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n) we need to loop over all elements
// SP: O(1) only previous and the one before previous state need to be stored
class Solution
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

int main()
{
    Solution s;
    vector<int> ivec = {2, 3, 1, 1, 4};
    bool result = s.canJump(ivec);
    cout << result << endl;
    return 0;
}
