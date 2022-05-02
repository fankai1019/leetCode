#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

// DP
// define d[i][j] as the min num of operations to convert word1[0,...,i) to word2[0,...j)
// TC: O(mn)
// SC: O(mn)
class Solution1
{
public:
  int minDistance(string word1, string word2)
  {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
      dp[i][0] = i;
    for (int j = 1; j <= n; ++j)
      dp[0][j] = j;

    for (int i = 1; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
      }
    }
    return dp[m][n];
  }
};

// DP
// define d[i][j] as the min num of operations to convert word1[0,...,i) to word2[0,...j)
// TC: O(mn)
// SC: O(n) only use 2 vectors for dp
class Solution2
{
public:
  int minDistance(string word1, string word2)
  {
    int m = word1.size();
    int n = word2.size();
    vector<int> curr(n + 1, 0);
    vector<int> prev(n + 1, 0);

    for (int i = 1; i <= n; ++i)
      prev[i] = i;

    for (int i = 1; i <= m; ++i)
    {
      curr[0] = i;
      for (int j = 1; j <= n; ++j)
      {
        if (word1[i - 1] == word2[j - 1])
          curr[j] = prev[j - 1];
        else
          curr[j] = min(min(prev[j], curr[j - 1]), prev[j - 1]) + 1;
      }
      swap(curr, prev);
    }
    return prev[n];
  }
};

int main()
{
  string word1 = "horse";
  string word2 = "ros";
  cout << word1 << endl;
  cout << word2 << endl;
  // Solution1 s;
  Solution2 s;
  int result = s.minDistance(word1, word2);
  cout << result << endl;
  return 0;
}
