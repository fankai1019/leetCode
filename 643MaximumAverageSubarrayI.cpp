#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
   public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        double max = sum / k;

        for (int i = 1; i < nums.size() - k + 1; ++i) {
            sum = sum - nums[i - 1] + nums[i + k - 1];
            max = std::max(sum / k, max);
        }
        return max;
    }
};

int main() {
    std::vector<int> inputs = {1, 12, -5, -6, 50, 3};
    Solution a;
    std::cout << a.findMaxAverage(inputs, 4) << std::endl;
    return 0;
}
