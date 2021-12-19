#include <algorithm>
#include <iostream>
#include <map>
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
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> ivec(10001, 0);
        for (size_t i = 0; i < nums.size(); ++i)
            ivec[nums[i]] += nums[i];

        // vector<int> result(ivec.size(), 0);
        // result[1] = ivec[1];
        // result[2] = max(ivec[1], ivec[2]);
        // for(size_t i=3; i<result.size(); ++i)
        //   result[i] = max(result[i-2] + ivec[i], result[i-1]);
        // return result.back();

        int a = ivec[1];
        int b = max(ivec[1], ivec[2]);
        int c;
        for (size_t i = 3; i < ivec.size(); ++i)
        {
            c = max(a + ivec[i], b);
            a = b;
            b = c;
        }
        return c;
    }
};

int main()
{
    Solution s;
    vector<int> ivec = {2, 2, 3, 3, 3, 4};
    int result = s.deleteAndEarn(ivec);
    cout << result << endl;
    return 0;
}
