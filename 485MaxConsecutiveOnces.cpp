#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int sum = 0;
        int max = 0;
        for (auto i : nums) {
            sum += i;
            sum *= i;
            max = std::max(sum, max);
        }
        return max;
    }
};

int main() {
    std::vector<int> input = {1, 0, 1, 1, 0, 1};
    Solution a;
    std::cout << a.findMaxConsecutiveOnes(input) << std::endl;
    return 0;
}
