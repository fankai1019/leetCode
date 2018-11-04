#include <math.h>
#include <deque>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::deque<int> nums(digits.begin(), digits.end());
        int i = nums.size() - 1;
        while (i >= 0) {
            if (++nums[i] == 10)
                nums[i--] = 0;
            else {
                break;
            }
        }
        if (i == -1) nums.push_front(1);
        std::vector<int> result(nums.begin(), nums.end());
        return result;
    }
};

int main() {
    std::vector<int> inputs = {1, 2, 3};
    Solution a;
    auto result = a.plusOne(inputs);
    for (auto i : result) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
