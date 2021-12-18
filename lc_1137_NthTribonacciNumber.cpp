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
    int tribonacci(int n)
    {
        if (n <= 1)
            return n;
        if (n == 2)
            return 1;
        int a = 0, b = 1, c = 1;
        int d;
        for (size_t i = 3; i < n + 1; ++i)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};

int main()
{
    Solution s;
    int result = s.tribonacci(25);
    cout << result << endl;
    return 0;
}