#include <iostream>
#include <string>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(n^2) nested for loops
// SC: O(n^2) a matrix is needed
class Solution1
{
public:
  string longestPalindrome(string s)
  {
    if (s.size() <= 1)
      return s;
    dp.resize(s.size(), vector<int>(s.size(), -1));
    for (int i = dp.size() - 1; i >= 0; --i)
      for (int j = i; j < dp.size(); ++j)
        if (dp[i][j] == -1)
          isPalindrome(i, j, s);

    size_t max_distance = 0;
    size_t target_i = 0;
    size_t target_j = 0;
    for (size_t i = 0; i < dp.size(); ++i)
    {
      for (size_t j = i; j < dp[i].size(); ++j)
      {
        if (dp[i][j] == 1)
        {
          size_t distance = j - i;
          if (distance > max_distance)
          {
            max_distance = distance;
            target_i = i;
            target_j = j;
          }
        }
      }
    }
    return s.substr(target_i, target_j - target_i + 1);
  }

private:
  bool isPalindrome(size_t i, size_t j, const string &s)
  {
    if (dp[i][j] == -1)
    {
      if (i == j)
        dp[i][j] = 1;
      else if (j == i + 1)
        dp[i][j] = s[i] == s[j] ? 1 : 0;
      else
        dp[i][j] = isPalindrome(i + 1, j - 1, s) && s[i] == s[j] ? 1 : 0;
      return dp[i][j] == 1;
    }
    else
      return dp[i][j] == 1;
  }
  vector<vector<int>> dp;
};

// iterative
// TC: O(n^2) nested for loops
// SC: O(n^2) a matrix is needed
class Solution2
{
public:
  string longestPalindrome(string s)
  {
    int n = s.size();
    if (n <= 1)
      return s;

    size_t max_distance = 0;
    size_t target_i = 0;
    size_t target_j = 0;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int i = 0; i < n - 1; ++i)
    {
      bool flag = s[i] == s[i + 1];
      dp[i][i + 1] = flag ? 1 : 0;
      if (max_distance < 1 && flag)
      {
        max_distance = 1;
        target_i = i;
        target_j = i + 1;
      }
    }

    // 0<= i < n
    // i+2<= j < n
    for (int i = n - 3; i >= 0; --i)
    {
      for (int j = i + 2; j < n; ++j)
      {
        bool flag = dp[i + 1][j - 1] && (s[i] == s[j]);
        dp[i][j] = flag ? 1 : 0;
        if (flag)
        {
          if (j - i > max_distance)
          {
            max_distance = j - i;
            target_i = i;
            target_j = j;
          }
        }
      }
    }

    return s.substr(target_i, target_j - target_i + 1);
  }
};

// two pointer
// TC: O(n^2) nested for loops
// SC: O(1) two pointer
class Solution3
{
public:
  string longestPalindrome(string s)
  {
    int n = s.size();
    if (n <= 1)
      return s;

    size_t max_distance = 0;
    string result(1, s[0]);
    // for (int i = 0; i < n; ++i)
    // at position i, the maximum of possible palindrome string has size (n - 1 - i) * 2
    for (int i = 0; i < n && (n - 1 - i) > max_distance / 2; ++i)
    {
      int left = i - 1;
      int right = i + 1;
      while (right < n && s[right] == s[i])
        ++right;
      while (left >= 0 && right < n && s[left] == s[right])
      {
        left--;
        right++;
      }
      if (right - left - 2 > max_distance)
      {
        max_distance = right - left - 2;
        result = s.substr(left + 1, max_distance + 1);
      }
    }
    return result;
  }
};

int main()
{
  string str = "babad";
  cout << str << endl;
  // Solution1 s;
  // Solution2 s;
  Solution3 s;
  string result = s.longestPalindrome(str);
  cout << result << endl;
  return 0;
}
