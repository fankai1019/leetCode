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
    int minCostClimbingStairs(vector<int> &cost)
    {
        // vector<int> fn(cost.size() + 1);
        // fn[0] = 0;
        // fn[1] = 0;
        // for (size_t i = 2; i < fn.size(); ++i)
        // {
        //   fn[i] = min(fn[i - 1] + cost[i - 1], fn[i - 2] + cost[i - 2]);
        // }
        // return fn.back();

        int a = 0;
        int b = 0;
        int c;
        for (size_t i = 2; i < cost.size() + 1; ++i)
        {
            c = min(a + cost[i - 2], b + cost[i - 1]);
            a = b;
            b = c;
        }
        return c;
    }
};

int main()
{
    Solution s;
    // vector<int> ivec = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> ivec = {10, 15, 20};
    int result = s.minCostClimbingStairs(ivec);
    cout << result << endl;
    return 0;
}
