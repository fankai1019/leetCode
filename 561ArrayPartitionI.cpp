#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int arrayPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (i % 2 == 0) sum += nums[i];
        return sum;
    }
};

int main() {
    std::vector<int> input = {2, 1, 3, 4};
    Solution a;
    auto result = a.arrayPairSum(input);
    std::cout << result << std::endl;
    return 0;
}
