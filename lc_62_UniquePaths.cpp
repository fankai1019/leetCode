#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// DP
// define dp[i][j] as the num of possible paths
// dp[i][j] = dp[i+1][j] + dp[i][j+1]
// TC: O(mn)
// SC: O(mn)
class Solution1
{
public:
  int uniquePaths(int m, int n)
  {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
      dp[i][n - 1] = 1;
    for (int j = 0; j < n; ++j)
      dp[m - 1][j] = 1;
    for (int i = m - 2; i >= 0; --i)
      for (int j = n - 2; j >= 0; --j)
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    return dp[0][0];
  }
};

// DP
// define dp[i][j] as the num of possible paths
// dp[i][j] = dp[i+1][j] + dp[i][j+1]
// TC: O(mn)
// SC: O(n)
class Solution2
{
public:
  int uniquePaths(int m, int n)
  {
    if (m == 1 || n == 1)
      return 1;
    vector<int> prev_row(n, 1);
    vector<int> curr_row(n, 1);
    for (int i = m - 2; i >= 0; --i)
    {
      for (int j = n - 2; j >= 0; --j)
        curr_row[j] = curr_row[j + 1] + prev_row[j];
      swap(prev_row, curr_row);
    }
    return prev_row[0];
  }
};

int main()
{
  int m = 3;
  int n = 7;
  // Solution1 s;
  Solution2 s;
  int result = s.uniquePaths(m, n);
  cout << result << endl;
  return 0;
}
