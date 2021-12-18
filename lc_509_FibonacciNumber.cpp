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
// SP: O(n) n states to store
class Solution1
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        vector<int> ivec(n + 1);
        ivec[0] = 0;
        ivec[1] = 1;
        for (size_t i = 2; i < ivec.size(); ++i)
            ivec[i] = ivec[i - 1] + ivec[i - 2];
        return ivec[n];
    }
};

// DP
// TC: O(n) need to iterate through n states
// SP: O(1) only store two previous fib numbers
class Solution2
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        int a = 0, b = 1;
        int c;
        for (size_t i = 2; i < n + 1; ++i)
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
    // Solution1 s;
    Solution2 s;
    int result = s.fib(30);
    cout << result << endl;
    return 0;
}