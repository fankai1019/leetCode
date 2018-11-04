#include <iostream>
#include <numeric>
#include <vector>

class Solution {
   public:
    int pivotIndex(std::vector<int>& nums) {
        int sum = 0;
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); sum += nums[i++]) {
            if (2 * sum == total - nums[i]) return i;
        }
        return -1;
    }
};

class Solution2 {
   public:
    int pivotIndex(std::vector<int>& nums) {
        if (nums.empty()) return -1;
        int sum = std::accumulate(nums.begin() + 1, nums.end(), 0);
        int left = 0;
        int right = sum;
        if (left == right) return 0;

        for (int i = 1; i < nums.size(); ++i) {
            left += nums[i - 1];
            right -= nums[i];
            if (left == right) return i;
        }
        if (left == right) return nums.size() - 1;
        return -1;
    }
};

int main() {
    std::vector<int> inputs = {1, 7, 3, 6, 5, 6};
    Solution a;
    std::cout << a.pivotIndex(inputs) << std::endl;
    return 0;
}
