#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
   public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int result = 1;
        int max = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                result++;
            else
                result = 1;
            max = std::max(result, max);
        }
        return max;
    }
};

int main() {
    std::vector<int> inputs = {1, 3, 5, 4, 7};
    Solution a;
    std::cout << a.findLengthOfLCIS(inputs) << std::endl;
    return 0;
}
