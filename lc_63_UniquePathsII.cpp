#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// nodes:
// if we define dp[i][j] as the num of possible paths to reach destination
// then dp[i][j] = dp[i+1][j] + dp[i][j+1]
// we need to loop backward and return dp[0][0]
// this might lead to integer overflow,
// because we might end up setting values to some point i and j which is not reachable if we did dp in the forward way

// DP
// define dp[i][j] as the num of possible paths to reach [i][j]
// dp[i][j] = dp[i-1][j] + dp[i][j-1]
// TC: O(mn)
// SC: O(mn)
class Solution1
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0])
      return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 1; i < m; ++i)
    {
      if (obstacleGrid[i][0])
        break;
      dp[i][0] = 1;
    }
    for (int j = 1; j < n; ++j)
    {
      if (obstacleGrid[0][j])
        break;
      dp[0][j] = 1;
    }

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (!obstacleGrid[i][j])
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m - 1][n - 1];
  }
};

// DP
// define dp[i][j] as the num of possible paths to reach [i][j]
// dp[i][j] = dp[i-1][j] + dp[i][j-1]
// TC: O(mn)
// SC: O(1)
class Solution2
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0])
      return 0;

    vector<vector<int>> &dp = obstacleGrid;
    dp[0][0] = 1;

    for (int i = 1; i < m; ++i)
    {
      if (dp[i][0])
        dp[i][0] = 0;
      else
        dp[i][0] = dp[i - 1][0];
    }
    for (int j = 1; j < n; ++j)
    {
      if (dp[0][j])
        dp[0][j] = 0;
      else
        dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (!dp[i][j])
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        else
          dp[i][j] = 0;

    return dp[m - 1][n - 1];
  }
};

int main()
{
  vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  printVecVec(obstacleGrid);
  // Solution1 s;
  Solution2 s;
  int result = s.uniquePathsWithObstacles(obstacleGrid);
  cout << result << endl;
  return 0;
}
