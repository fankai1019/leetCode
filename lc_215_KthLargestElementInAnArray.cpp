#include "utils.h"

using namespace std;

// Prioirty Queue
// TC: O((n+k)logn) build heap nlogn, pop k times klogn
// SC: O(n) heap size is n
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        // 1 <= k <= nums.length <= 10^4
        for (int i = 1; i < k; ++i)
            pq.pop();
        return pq.top();
    }
};

// TODO: more methods

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution s;
    int result = s.findKthLargest(nums, k);
    cout << result << endl;
    return 0;
}
