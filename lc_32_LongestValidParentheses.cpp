#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// stack
// 1. Scan the string from beginning to end.
// 2. If current character is '(',
//    push its index to the stack. If current character is ')' and the
//    character at the index of the top of stack is '(', we just find a
//    matching pair so pop from the stack. Otherwise, we push the index of
//    ')' to the stack.
// 3. After the scan is done, the stack will only
//    contain the indices of characters which cannot be matched. Then
//    let's use the opposite side - substring between adjacent indices
//    should be valid parentheses.
// 4. If the stack is empty, the whole input
//    string is valid. Otherwise, we can scan the stack to get longest
//    valid substring as described in step 3.

// TC: O(n) loop s chars once and loop stack once
// SC: O(n) a stack is needed and it has size n in worse case
class Solution1
{
public:
  int longestValidParentheses(string s)
  {
    if (s.size() < 2)
      return 0;
    int n = s.size();
    int result = 0;
    stack<int> istack;
    for (int i = 0; i < n; ++i)
    {
      if (istack.empty())
        istack.push(i);
      else
      {
        if (s[i] == '(')
          istack.push(i);
        else
        {
          if (s[istack.top()] == '(')
            istack.pop();
          else
            istack.push(i);
        }
      }
    }

    if (istack.empty())
      result = n;
    else
    {
      int a = 0;
      int b = n;
      while (!istack.empty())
      {
        a = istack.top();
        istack.pop();
        result = max(result, b - a - 1);
        b = a;
      }
      result = max(result, b);
    }
    return result;
  }
};

// TC: O(n) it iteraters all the characters twice
// SC: O(1) two pointer
class Solution2
{
public:
  int longestValidParentheses(string s)
  {
    int n = s.size();
    if (n < 2)
      return 0;

    int result = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; ++i)
    {
      if (s[i] == '(')
        ++left;
      else
        ++right;
      if (right > left)
      {
        left = 0;
        right = 0;
      }
      else if (right == left)
      {
        result = max(result, 2 * right);
      }
    }

    left = 0;
    right = 0;
    for (int i = n - 1; i >= 0; --i)
    {
      if (s[i] == ')')
        ++right;
      else
        ++left;
      if (left > right)
      {
        left = 0;
        right = 0;
      }
      else if (right == left)
      {
        result = max(result, 2 * right);
      }
    }
    return result;
  }
};

// DP
// define dp[i] as the longest length of valid parenthesis ending at i
// TC: O(n) it iteraters all the characters once
// SC: O(n) need a vector for dp
class Solution3
{
public:
  int longestValidParentheses(string s)
  {
    int n = s.size();
    if (n < 2)
      return 0;
    vector<int> dp(n, 0);
    int result = 0;
    for (int i = 1; i < n; ++i)
    {
      if (s[i] == '(')
        dp[i] = 0;
      else // ')'
      {
        if (s[i - 1] == '(')
        {
          dp[i] = 2 + (i - 2 >= 0 ? dp[i - 2] : 0);
          result = max(result, dp[i]);
        }
        else // ')'
        {
          if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
          {
            dp[i] = 2 + dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
            result = max(result, dp[i]);
          }
        }
      }
    }
    return result;
  }
};

int main()
{
  // string str = ")()())";
  // string str = "(()";
  // string str = "()";
  string str = "())))";
  // Solution1 s;
  // Solution2 s;
  Solution3 s;
  int result = s.longestValidParentheses(str);
  cout << result << endl;
  return 0;
}
