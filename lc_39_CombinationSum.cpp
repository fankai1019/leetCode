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
        vector<int> curr;
        int sum = 0;
        backtracking(candidates, curr, sum, target);
        return results;
    }

private:
    void backtracking(const vector<int> &candidates, vector<int> &curr, int &sum, int target)
    {
        if (sum > target)
            return;
        if (sum == target)
            results.push_back(curr);
        for (int i = 0; i < candidates.size(); ++i)
        {
            if (!curr.size() || candidates[i] >= curr.back())
            {
                curr.push_back(candidates[i]);
                sum += candidates[i];
                backtracking(candidates, curr, sum, target);
                sum -= candidates[i];
                curr.pop_back();
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
    vector<vector<int>> result = s.combinationSum(ivec, 7);
    printVecVec(result);
    return 0;
}