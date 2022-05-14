#include "utils.h"

using namespace std;

// Binary search
// TC: O(logn) T(n) = T(n/2) + O(1) there are 2^n possible subsets and each time we need to copy path into results
// SC: O(logn) stack frame size is logn
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        return bs(nums, low, high, target);
    }

private:
    int bs(vector<int> &nums, int low, int high, int target)
    {

        if (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] >= target)
                return bs(nums, low, mid - 1, target);
            else
                return bs(nums, mid + 1, high, target);
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    Solution s;
    int result = s.search(nums, target);
    cout << result << endl;
    return 0;
}
