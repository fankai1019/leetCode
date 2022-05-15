#include "utils.h"

using namespace std;

// Backtracking
// TC: O(C(9, k)) at most C(9, k) cases. Rather loose upper bound
// SC: O(k) stack size is k regardless collection of results
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> path;
        backtracking(n, k, path, 1);
        return results;
    }

    void backtracking(int n, int &k, vector<int> &path, int begin)
    {
        if (k == 0 && n == 0)
        {
            results.push_back(path);
            return;
        }

        if (n < 1 || k <= 0)
            return;

        for (int i = begin; i <= 9; ++i)
        {
            if (i <= n)
            {
                path.push_back(i);
                k--;
                backtracking(n - i, k, path, i + 1);
                path.pop_back();
                k++;
            }
        }
    }
    vector<vector<int>> results;
};

int main()
{
    int k = 3;
    int n = 9;
    Solution s;
    vector<vector<int>> results = s.combinationSum3(k, n);
    printVecVec(results);
    return 0;
}
