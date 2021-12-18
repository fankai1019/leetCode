#include <algorithm>
#include <iostream>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// DP
// TC: O(n) need to iterate through n states
// SP: O(1) only store two previous fib numbers
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int a = 1, b = 2;
        int c;
        for (size_t i = 3; i < n + 1; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main()
{
    Solution s;
    int result = s.climbStairs(25);
    cout << result << endl;
    return 0;
}
