#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    int findShortestSubArray(std::vector<int>& nums) {
        int result;
        int degree = 0;
        std::unordered_map<int, int> first, counter;
        for (int i = 0; i < nums.size(); ++i) {
            if (first.count(nums[i]) == 0) first[nums[i]] = i;
            if (++counter[nums[i]] > degree) {
                degree = counter[nums[i]];
                result = i - first[nums[i]] + 1;
            } else if (counter[nums[i]] == degree) {
                result = std::min(result, i - first[nums[i]] + 1);
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 2, 3, 1};
    Solution a;
    std::cout << a.findShortestSubArray(nums) << std::endl;
    return 0;
}
