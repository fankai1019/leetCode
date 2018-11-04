#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    int dominantIndex(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; ++i) map[nums[i]] = i;
        std::sort(nums.begin(), nums.end());
        if (nums[n - 1] >= 2 * nums[n - 2])
            return map[nums[n - 1]];
        else
            return -1;
    }
};

int main() {
    std::vector<int> inputs = {3, 6, 1, 0};
    Solution a;
    std::cout << a.dominantIndex(inputs) << std::endl;
    return 0;
}

