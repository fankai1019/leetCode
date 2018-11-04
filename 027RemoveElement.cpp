#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int removeElement(std::vector<int>& nums, int val) {
        int pos = 0;
        int size = nums.size();
        int last = size - 1;
        while (pos <= last) {
            if (nums[last] == val) {
                --last;
                --size;
                continue;
            }
            if (nums[pos] == val) {
                std::swap(nums[pos], nums[last]);
                --last;
                --size;
            }
            ++pos;
        }
        return size;
    }
};

int main() {
    std::vector<int> inputs = {0, 1, 2, 2, 3, 0, 4, 2};
    Solution a;
    std::cout << a.removeElement(inputs, 2) << std::endl;
    return 0;
}
