#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = nums[0];
        int max = sum;
        for (int i = 1; i < nums.size(); ++i) {
            int temp = nums[i] + sum;
            if (temp < nums[i]) {
                sum = nums[i];
                max = std::max(max, sum);
            } else {
                sum = temp;
                max = std::max(max, sum);
            }
        }

        return max;
    }
};

int main() {
    std::vector<int> inputs = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution a;
    std::cout << a.maxSubArray(inputs) << std::endl;
    return 0;
}
