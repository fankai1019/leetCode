#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
   public:
    void moveZeroes(std::vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        for (; j < nums.size(); ++j) {
            nums[j] = 0;
        }
    }
};

class Solution2 {
   public:
    void moveZeroes(std::vector<int>& nums) {
        int begin = 0;
        while (begin != nums.size()) {
            int zeroPos = INT_MAX;
            int nonZeroPos = 0;

            bool zeroFound = false;
            bool nonZeroFound = false;

            for (int i = begin; i < nums.size(); ++i) {
                if (!zeroFound) {
                    if (nums[i] == 0) {
                        zeroPos = i;
                        zeroFound = true;
                        if (nonZeroFound) break;
                    }
                }
                if (!nonZeroFound) {
                    if (nums[i] != 0) {
                        nonZeroPos = i;
                        nonZeroFound = true;
                        if (zeroFound) break;
                    }
                }
            }

            if (zeroFound && nonZeroFound)
                if (nonZeroPos > zeroPos)
                    std::swap(nums[zeroPos], nums[nonZeroPos]);
            begin++;
        }
    }
};

void print(const std::vector<int>& a) {
    for (auto i : a) std::cout << i << ' ';
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {0, 1, 0, 3, 12};
    Solution a;
    a.moveZeroes(nums);

    for (auto i : nums) std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}
