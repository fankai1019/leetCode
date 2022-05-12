#include "utils.h"
using namespace std;

// Backtracking
// TC: O((N^M)*K) N: number of choice at each level. M: number of possible levels.
//     K: time spent on copying results.
//     In our example, N == 4. M = 7 in worset case. K == 7 in worst case.
// SC: O(M) stack size is O(M) in worset case.
//     At each recusion, we need additional space for vector copy.
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> path;
        int sum = 0;
        backtracking(candidates, path, sum, target);
        return results;
    }

private:
    void backtracking(const vector<int> &candidates, vector<int> &path, int &sum, int target)
    {
        if (sum > target)
            return;
        if (sum == target)
            results.push_back(path);
        for (int i = 0; i < candidates.size(); ++i)
        {
            if (!path.size() || candidates[i] >= path.back())
            {
                path.push_back(candidates[i]);
                sum += candidates[i];
                backtracking(candidates, path, sum, target);
                sum -= candidates[i];
                path.pop_back();
            }
        }
    }
    vector<vector<int>> results;
};

int main()
{
    vector<int> ivec = {2, 3, 6, 7};
    int target = 7;
    Solution s;
    vector<vector<int>> result = s.combinationSum(ivec, target);
    printVecVec(result);
    return 0;
}