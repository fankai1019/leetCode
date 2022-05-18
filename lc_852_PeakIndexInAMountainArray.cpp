#include "utils.h"

using namespace std;

// Binary search
// TC: O(logn) m number of valid offers
// SC: O(logn) stack size is logn
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        return binary(arr, 0, arr.size() - 1);
    }

private:
    int binary(const vector<int> &arr, int low, int high)
    {
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        if (mid == 0)
            return binary(arr, 1, high);
        if (mid == arr.size() - 1)
            return binary(arr, low, mid);
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        if (arr[mid] < arr[mid + 1])
            return binary(arr, mid + 1, high);
        return binary(arr, low, mid - 1);
    }
};

int main()
{
    vector<int> nums = {0, 2, 1, 0};
    Solution s;
    int result = s.peakIndexInMountainArray(nums);
    cout << result << endl;
    return 0;
}
