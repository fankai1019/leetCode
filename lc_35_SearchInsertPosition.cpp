#include "utils.h"

using namespace std;

// Binary search
// TC: O(logn) m number of valid offers
// SC: O(logn) stack size is logn
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return binary(nums, target, 0, nums.size() - 1);
    }

private:
    int binary(const vector<int> &nums, int target, int low, int high)
    {
        if (low > high)
            return low;
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            return binary(nums, target, mid + 1, high);
        return binary(nums, target, low, mid - 1);
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    Solution s;
    int result = s.searchInsert(nums, target);
    cout << result << endl;
    return 0;
}
