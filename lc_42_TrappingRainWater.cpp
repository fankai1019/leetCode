#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// dp
// TC: O(n) iterate 3 times
// SC: O(n) max vectors to keep track of left max and right max
// define dp[i] as the stored water at pos i
// dp[i] = max(min(lmax[i], rmax[i]) - height[i], 0)
class Solution1
{
public:
  int trap(vector<int> &height)
  {
    int n = height.size();
    int left_max = -1;
    int right_max = -1;
    vector<int> lmax(n, -1);
    vector<int> rmax(n, -1);
    for (int i = 1; i < height.size(); ++i)
    {
      if (left_max < height[i - 1])
        left_max = height[i - 1];
      lmax[i] = left_max;
    }

    for (int i = height.size() - 2; i >= 0; --i)
    {
      if (right_max < height[i + 1])
        right_max = height[i + 1];
      rmax[i] = right_max;
    }

    int result = 0;
    ;
    for (int i = 0; i < height.size(); ++i)
      result += max(min(lmax[i], rmax[i]) - height[i], 0);
    return result;
  }
};

// two pointers
// TC: O(n) iterate 1 once
// SC: O(1) two pointers
class Solution2
{
public:
  int trap(vector<int> &height)
  {
    int n = height.size();
    int result = 0;
    int lmax = -1;
    int rmax = -1;
    int l = 0;
    int r = height.size() - 1;
    while (l <= r)
    {
      if (height[l] <= height[r])
      {
        if (height[l] >= lmax)
          lmax = height[l];
        else
          result += lmax - height[l];
        l++;
      }
      else
      {
        if (height[r] >= rmax)
          rmax = height[r];
        else
          result += rmax - height[r];
        --r;
      }
    }
    return result;
  }
};

int main()
{
  vector<int> ivec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  printVec(ivec);
  // Solution1 s;
  Solution2 s;
  int result = s.trap(ivec);
  cout << result << endl;
  return 0;
}
