#include <iostream>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

// DP Top down
// Define dp[i] as the number of way to form a bst using nodes of value from 1 to i
// Then dp[n] = Sum_1^n dp[i-1] * dp[n-i]
// TC: O(n^2) we calculate numTrees(i) (for 1<=i<=n) only once and memoize it which will take O(N).
//  For calculating each of numTrees(i), we need n iterations to calculate Sum_1^n dp[i-1] * dp[n-i].
//  Thus, the overall time complexity becomes O(n*n)
// SC: O(n) a vector is needed to store dp
class Solution
{
public:
    int numTrees(int n)
    {
        static vector<int> dp(20); // all default to 0
        if (dp[n])
            return dp[n];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i <= n; ++i)
            dp[n] += numTrees(i - 1) * numTrees(n - i);
        return dp[n];
    }
};

int main()
{
    Solution s;
    int n = 3;
    int result = s.numTrees(3);
    cout << result << endl;
    return 0;
}
