#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maximumProduct(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        return std::max(nums[nums.size() - 1] * nums[nums.size() - 2] *
                            nums[nums.size() - 3],
                        nums[0] * nums[1] * nums[nums.size() - 1]);
    }
};

int main() {
    std::vector<int> inputs = {1, 2, 3, 4};
    Solution a;
    std::cout << a.maximumProduct(inputs) << std::endl;
    return 0;
}
