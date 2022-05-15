#include "utils.h"
using namespace std;

// TODO: DFS with memo
// DFS
// TC: O(2^n) size of recusion tree will be O(2^n)
// SC: O(n) depth of recursion tree is O(n)
class Solution1
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        dfs(nums, 0, target, 0);
        return count;
    }

    void dfs(const vector<int> &nums, int sum, int target, int i)
    {
        if (i == nums.size())
        {
            if (sum == target)
                count++;
            return;
        }
        dfs(nums, sum + nums[i], target, i + 1);
        dfs(nums, sum - nums[i], target, i + 1);
    }
    int count = 0;
};

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    // vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    // int target = 1;
    Solution1 s;
    int result = s.findTargetSumWays(nums, target);
    cout << result << endl;
    return 0;
}