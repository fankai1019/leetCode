#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "utils.h"
using namespace std;

// DP recursive
// TC: O(4^n/sqrt(n)), check the explanation in leetcode solution
// SC: O(4^n/sqrt(n)), check the explanation in leetcode solution
// dp[n] = "(dp[p])"+"dp[n-p-1]", 0 <= p <= n-1
class Solution1
{
public:
  vector<string> generateParenthesis(int n)
  {
    vector<vector<string>> dp(n + 1);
    return generateParenthesis(n, dp);
  }

private:
  const vector<string> &generateParenthesis(int n, vector<vector<string>> &dp)
  {
    if (dp[n].size())
      return dp[n];
    if (n == 0)
      dp[n].push_back("");
    else if (n == 1)
      dp[n].push_back("()");
    else
    {
      vector<string> all_result;
      for (int p = 0; p <= n - 1; ++p)
      {
        const vector<string> &left = generateParenthesis(p, dp);
        const vector<string> &right = generateParenthesis(n - p - 1, dp);
        vector<string> left_p;
        for (int i = 0; i < left.size(); ++i)
          left_p.push_back("(" + left[i] + ")");

        vector<string> result;
        for (int i = 0; i < left_p.size(); ++i) // O(n^2)
        {
          const string &left_p_i = left_p[i];
          for (int j = 0; j < right.size(); ++j)
          {
            const string &right_j = right[j];
            result.push_back(left_p_i + right_j);
          }
        }
        for (int i = 0; i < result.size(); ++i)
          all_result.push_back(result[i]);
      }
      dp[n].swap(all_result);
    }
    return dp[n];
  }
};

// DP iterative
// TC: O(4^n/sqrt(n)), check the explanation in leetcode solution
// SC: O(4^n/sqrt(n)), check the explanation in leetcode solution
class Solution2
{
public:
  vector<string> generateParenthesis(int n)
  {
    vector<vector<string>> dp(n + 1);
    dp[0].push_back("");
    for (int i = 1; i <= n; ++i)
    {
      vector<string> result_i;
      for (int p = 0; p < i; ++p)
      {
        int q = i - p - 1;
        const vector<string> &left = dp[p];
        const vector<string> &right = dp[q];
        for (int m = 0; m < left.size(); ++m)
          for (int n = 0; n < right.size(); ++n)
            result_i.push_back('(' + left[m] + ')' + right[n]);
      }
      dp[i].swap(result_i);
    }
    return dp[n];
  }
};

// dfs recursive
// TC: O(4^n/sqrt(n)), check the explanation in leetcode solution
// SC: O(4^n/sqrt(n)), check the explanation in leetcode solution
// Every lvl, you are making 2 decisions and the maximum height of the decision tree is 2 * n
// since n is the number of pairs of "(" and ")". So therefore the Time and Space Complexity would be 2^2n or 4^n.
class Solution3
{
public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> result;
    dfs(result, "", n, n);
    return result;
  }

private:
  void dfs(vector<string> &result, string str, int left, int right)
  {
    if (left > right)
      return;

    // do
    if (left == 0 && right == 0)
      result.push_back(str);

    if (left)
      dfs(result, str + "(", left - 1, right);
    if (right)
      dfs(result, str + ")", left, right - 1);
  }
};

// dfs iterative
// TC: O(4^n/sqrt(n)), check the explanation in leetcode solution
// SC: O(4^n/sqrt(n)), check the explanation in leetcode solution
class Solution4
{
public:
  enum STATUS
  {
    NOT_VISITED,
    VISITED
  };

  struct Node
  {
    Node(STATUS st, const string &s, int l, int r) : status(st), str(s), left(l), right(r) {}
    STATUS status;
    string str;
    int left;
    int right;
  };

  vector<string> generateParenthesis(int n)
  {
    vector<string> result;
    stack<Node> nstack;
    nstack.push(Node(NOT_VISITED, "", n, n));

    while (nstack.size())
    {
      Node node = nstack.top();
      nstack.pop();

      if (node.left > node.right)
        continue;

      if (node.status == NOT_VISITED)
      {
        node.status = VISITED;
        nstack.push(node);
        if (node.left)
        {
          Node left_node(NOT_VISITED, node.str + "(", node.left - 1, node.right);
          nstack.push(left_node);
        }
        if (node.right)
        {
          Node right_node(NOT_VISITED, node.str + ")", node.left, node.right - 1);
          nstack.push(right_node);
        }
      }
      else
      {
        if (node.left == 0 && node.right == 0)
          result.push_back(node.str);
      }
    }

    return result;
  }
};

int main()
{
  int n = 3;
  // Solution1 s;
  Solution2 s;
  // Solution3 s;
  // Solution4 s;
  vector<string> result = s.generateParenthesis(n);
  printVec(result);
  return 0;
}
