#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n) needs to loop over every elements
// SC: O(n) needs a vector to store all emlements in an intermediate vector
class Solution1
{
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
  {
    int m = grid.size();
    int n = grid[0].size();
    k %= m * n;
    if (k == 0)
      return grid;
    vector<int> ivec(m * n);
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (i * n + j + k <= m * n - 1)
          ivec[i * n + j + k] = grid[i][j];
        else
          ivec[i * n + j + k - 1 - m * n + 1] = grid[i][j];
      }
    }

    vector<vector<int>> results(m, vector<int>(n, 0));
    int count = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        results[i][j] = ivec[count++];
    return results;
  }
};

// TC: O(n) needs to loop over every elements
// SC: O(1) only need temp ints to store dimension info
class Solution2
{
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
  {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> results(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        int new_j = (j + k) % n;
        int new_i = ((j + k) / n + i) % m;
        results[new_i][new_j] = grid[i][j];
      }
    }
    return results;
  }
};

int main()
{
  vector<vector<int>> imatrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int k = 2;
  printVecVec(imatrix);
  cout << endl;

  // Solution1 s;
  Solution2 s;
  vector<vector<int>> result = s.shiftGrid(imatrix, k);
  printVecVec(result);

  return 0;
}
