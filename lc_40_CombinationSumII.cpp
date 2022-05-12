#include "utils.h"
using namespace std;

// Backtracking
// TC: O(2^n) n: number of candidates
//     in the worst case, our algorithm will exhaust all possible combinations
//     from the input array.
//     in the worst case, let us assume that each number is unique.
//     The number of combination for an array of size n would be 2^n
//     i.e. each number is either included or excluded in a combination.
//     The sorting take O(nlogn)
// SC: O(n) We use the variable path to keep track of the current combination we build,
//     which requires O(N) space.
//     In addition, we apply recursion in the algorithm, which will incur additional
//     memory consumption in the function call stack.
//     In the worst case, the stack will pile up to O(n) space.
//     To sum up, the overall space complexity of the algorithm is O(N)+O(N)=O(N).
//     Note: we did not take into account the space needed to hold the final results
//     of combination in the above analysis.
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> path;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, path, sum, 0, target);
        return results;
    }

private:
    void backtracking(const vector<int> &candidates, vector<int> &path, int &sum, int pos, int target)
    {
        if (sum > target)
            return;
        if (sum == target)
            results.push_back(path);
        for (int i = pos; i < candidates.size(); ++i)
        {
            if (i && candidates[i] == candidates[i - 1] && i > pos)
                continue;
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, path, sum, i + 1, target);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> results;
};

int main()
{
    vector<int> ivec = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution s;
    vector<vector<int>> result = s.combinationSum2(ivec, target);
    printVecVec(result);
    return 0;
}