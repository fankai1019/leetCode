#include <math.h>
#include <iostream>
#include <vector>

class Solution {
   public:
    int missingNumber(std::vector<int>& nums) {
        int pos;
        nums.push_back(1);
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[std::abs(nums[i])] > 0)
                nums[std::abs(nums[i])] = -nums[std::abs(nums[i])];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) pos = i;
            if (nums[i] > 0) return i;
        }
        return pos;
    }
};

int main() {
    //    std::vector<int> input = {3, 0, 1};
    std::vector<int> input = {2, 1};
    Solution a;
    std::cout << a.missingNumber(input) << std::endl;
    return 0;
}
