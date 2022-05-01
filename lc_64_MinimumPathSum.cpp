#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

// DP
// define d[i][j] as the min path sum to reach [i][j]
// TC: O(mn)
// SC: O(mn)
class Solution1
{
public:
  int minPathSum(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size(); // guranteed by constraint
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int j = 1; j < n; ++j)
      dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < m; ++i)
      dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

    return dp[m - 1][n - 1];
  }
};

// DP
// define d[i][j] as the min path sum to reach [i][j]
// TC: O(mn)
// SC: O(1)
class Solution2
{
public:
  int minPathSum(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size(); // guranteed by constraint
    vector<vector<int>> &dp = grid;
    for (int j = 1; j < n; ++j)
      dp[0][j] += dp[0][j - 1];

    for (int i = 1; i < m; ++i)
      dp[i][0] += dp[i - 1][0];

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);

    return dp[m - 1][n - 1];
  }
};

int main()
{
  vector<vector<int>> obstacleGrid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  printVecVec(obstacleGrid);
  // Solution1 s;
  Solution2 s;
  int result = s.minPathSum(obstacleGrid);
  cout << result << endl;
  return 0;
}
